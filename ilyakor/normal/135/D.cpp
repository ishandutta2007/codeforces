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

const int maxn = 1010;

int n, m;
char a[maxn][maxn];
int u[maxn][maxn];

int IT = 57;

vector<ii> cur;

const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool good(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canOut;

void dfs(int x, int y, int D, bool add) {
    int rev = u[x][y];
    u[x][y] = IT;
    for (int dir = 0; dir < D; ++dir) {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (!good(xx, yy)) { canOut = true; continue; }
        if (a[xx][yy] != a[x][y]) {
            if (add) {
                if (u[xx][yy] != IT) {                 
                    u[xx][yy] = IT;
                    cur.pb(ii(xx, yy));
                }
            }
            continue;            
        }
        if (u[xx][yy] != rev) continue;

        dfs(xx, yy, D, add);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf("%s", a[i]);

    memset(u, 0, sizeof(u));
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '0' && !u[i][j]) {
                cur.clear();
                ++IT;
                canOut = false;
                dfs(i, j, 8, true);
                if (canOut) continue;
                int rev = IT;
//                cerr << sz(cur) << "\n";
                
                if (sz(cur) <= res) continue;
                bool ok = true;
                for (int p = 0; p < sz(cur); ++p) {
                    int x = cur[p].first;
                    int y = cur[p].second;
                    int cnt = 0;
                    for (int dir = 0; dir < 4; ++dir) {
                        int xx = x + dx[dir];
                        int yy = y + dy[dir];
                        if (!good(xx, yy)) continue;
                        if (a[xx][yy] != '1') continue;
                        if (u[xx][yy] != rev) continue;
                        ++cnt;
                    }
//                    cerr << x << " " << y << " " << cnt << "\n";
                    if (cnt != 2) {
                        ok = false;
                        break;
                    }
                }
//                cerr << "check: " << ok << "\n";
                if (!ok) continue;

                int cmp = 0;
                ++IT;
                for (int p = 0; p < sz(cur); ++p) {
                    int x = cur[p].first;
                    int y = cur[p].second;
                    if (u[x][y] != rev) continue;
                    dfs(x, y, 4, false);
                    ++cmp;
                }
                if (cmp != 1) continue;

                res = max(res, sz(cur));
            }

    for (int i = 0; i + 1 < n; ++i)
        for (int j = 0; j + 1 < m; ++j)
            if (a[i][j] == '1' && a[i + 1][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j + 1] == '1') res = max(res, 4);

    cout << res << "\n";

    return 0;
}