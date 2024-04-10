/*
 * Powered by C++Helper v0.001alpha
*/

#ifdef DEBUG_OUTPUT

#include <iostream>
#include <string>
#include <utility>

#define DEBUG(x) DebugOutput::run(std::cerr, __FILE__, __LINE__, #x, x)

struct DebugOutput {
    template <typename T>
    struct IsContainer
    {
        template<typename U>
        static char test(U* u, typename U::const_iterator b = ((U*)0)->begin(), typename U::const_iterator e = ((U*)0)->end());

        template<typename U>
        static int test(...);

        enum { value = (1 == sizeof test<T>(0)) };
    };

    template<typename T>
    struct IsCharacter {
        static char test(const char *u);

        static char test(const unsigned char *u);

        static int test(...);

        enum { value = (1 == sizeof test((T*)0)) };
    };

    template<typename T>
    struct IsString {
        static char test(char **u);

        static char test(unsigned char **u);

        static char test(const char **u);

        static char test(const unsigned char **u);

        template<int N>
        static char test(char (*)[N]);

        template<int N>
        static char test(unsigned char (*)[N]);

        template<int N>
        static char test(const char (*)[N]);

        template<int N>
        static char test(const unsigned char (*)[N]);

        static char test(std::string *u);

        static int test(...);

        enum { value = (1 == sizeof test((T*)0)) };
    };

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[!IsContainer<T>::value && !IsCharacter<T>::value && !IsString<T>::value] = 0) {
        out << value;
    }

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[IsCharacter<T>::value] = 0) {
        out << "'" << value << "'";
    }

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[IsContainer<T>::value && !IsString<T>::value] = 0) {
        out << "{";
        bool first = true;
        for (typename T::const_iterator it = value.begin(); it != value.end(); ++it) {
            if (first) {
                first = false;
            }
            else {
                out << ", ";
            }
            print(out, *it);
        }
        out << "}";
    }

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[IsString<T>::value] = 0) {
        out << "\"" << value << "\"";
    }

    template<typename T1, typename T2>
    static void print(std::ostream &out, const std::pair<T1, T2> &value) {
        out << "(";
        print(out, value.first);
        out << ", ";
        print(out, value.second);
        out << ")";
    }

    template<typename T>
    static void run(std::ostream &out, const std::string &fileName, int lineNumber, const std::string &name, const T &value) {
        out << "file \"" << fileName << "\" line " << lineNumber << ": " << name << " = ";
        print(out, value);
        out << std::endl;
    }
};
#else
#define DEBUG(x) ({})
#endif



#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int check(vector<ii> v) {
    int res = -1;
    sort(all(v));
    do {
        int cur = 1;
        int val = -1;
        for (int i = 0; i < 4; ++i) {
            int j = (i + 1) % 4;
            int k = (j + 1) % 4;
            int x1 = v[i].first, y1 = v[i].second;
            int x2 = v[j].first, y2 = v[j].second;
            int x3 = v[k].first, y3 = v[k].second;
            if ((x2 - x1) * (x3 - x2) + (y3 - y2) * (y2 - y1) != 0) {
                cur = -1;
                break;
            }
            int cv = sqr(x2 - x1) + sqr(y2 - y1);
            if (val != -1 && val != cv) val = -2;
            if (val != -2) val = cv;
        }
        if (val == -2) cur = min(cur, 0);
        res = max(res, cur);
    } while (next_permutation(all(v)));
    return res;
}

int main() {
    vector<ii> v(8);
    for (int i = 0; i < 8; ++i)
        cin >> v[i].first >> v[i].second;

    for (int mask = 0; mask < (1 << 8); ++mask) {
        vector<ii> v1, v2;
        for (int i = 0; i < 8; ++i) {
            if ((mask >> i) & 1) v1.pb(v[i]); else v2.pb(v[i]);
        }
        if (sz(v1) != sz(v2)) continue;
        int s1 = check(v1);
        int s2 = check(v2);
        //cerr << s1 << " " << s2 << "\n";
        if (s1 == 1 && s2 != -1) {
            printf("YES\n");
            for (int i = 0; i < 8; ++i)
                if ((mask >> i) & 1) printf("%d ", i + 1);
            printf("\n");

            for (int i = 0; i < 8; ++i)
                if (!((mask >> i) & 1)) printf("%d ", i + 1);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}