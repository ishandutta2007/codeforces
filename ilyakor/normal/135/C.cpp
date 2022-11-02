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

string solve(string s) {
    int l = 0, r = 0;
    int w = 0;
    int c = sz(s);
    while (c > 2) {
        if (w == 0) {
            while (l < sz(s) && s[l] != '1') ++l;
            if (l == sz(s)) break;                    
            s[l] = 'x', --c;            
        } else {
            while (r < sz(s) && s[r] != '0') ++r;
            if (r == sz(s)) break;
            s[r] = 'x', --c;
        }
        w = 1 - w;
    }
    string res;
    for (int i = 0; i < sz(s) && sz(res) < 2; ++i)
        if (s[i] != 'x') res += s[i];
    return res;
}

int main() {
    string s;
    cin >> s;
    string s1 = s, s2 = s, s3 = s, s4 = s;
    int z = 0, o = 0, q = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '0') ++z;
        else if (s[i] == '1') ++o;
        else ++q;
        s1[i] = s[i] != '1' ? '0' : '1';
        s2[i] = s[i] != '0' ? '1' : '0';
    }
    vector<string> res;
    res.pb(solve(s1));
    res.pb(solve(s2));

    int Z = sz(s) / 2, O = sz(s) / 2 + sz(s) % 2;

    int tz = Z - z, to = O - o;
    for (int i = 0; i < sz(s3) && tz > 0; ++i)
        if (s3[i] == '?') s3[i] = '0', --tz;
    for (int i = sz(s3) - 1; i >= 0 && to > 0; --i)
        if (s3[i] == '?') s3[i] = '1', --to;
    res.pb(solve(s3));
    tz = Z - z, to = O - o;
    for (int i = 0; i < sz(s4) && to > 0; ++i)
        if (s4[i] == '?') s4[i] = '1', --to;
    for (int i = sz(s4) - 1; i >= 0 && tz > 0; --i)
        if (s4[i] == '?') s4[i] = '0', --tz;
    res.pb(solve(s4));
    
    sort(all(res));
    res.erase(unique(all(res)), res.end());

    for (int i = 0; i < sz(res); ++i)
        cout << res[i] << "\n";
    return 0;
}