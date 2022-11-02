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

int main() {
    int n;
    cin >> n;
    map<int, int> M;
    int s = 2 * 1000 * 1000 * 1000;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++M[x];
        s = min(s, x);
    }

    int cur = s;
    for (int i = 0; i < n; ++i) {
//        cerr << cur << "\n";
        --M[cur];
        if ((i == n - 1 && cur + 1 == s) || M[cur + 1] > 0) ++cur;
        else if ((i == n - 1 && cur - 1 == s) || M[cur - 1] > 0) --cur;
        else {
            printf("NO\n");
            return 0;
        }
    }
    if (cur != s) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}