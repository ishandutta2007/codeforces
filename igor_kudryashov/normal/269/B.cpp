#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 5000 + 3;

int n, m;
int t[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;

    forn(i, n)
    {
        char buf[30];
        assert(scanf("%d%s", &t[i], buf) == 2);
        t[i]--;
    }

    return true;
}

int d[N][N];

inline void solve()
{
    memset(d, 63, sizeof(d));

    d[0][0] = 0;

    forn(i, n)
    {
        forn(j, m)
        {
            int dv = d[i][j];

            //if (dv < INF / 2)
                //cerr << i << ' ' << j << ' ' << dv << endl;

            if (t[i] < j)
                d[i + 1][j] = min(d[i + 1][j], dv + 1);
            else if (t[i] == j)
                d[i + 1][j] = min(d[i + 1][j], dv);
            else
            {
                d[i + 1][j] = min(d[i + 1][j], dv + 1);
                d[i + 1][t[i]] = min(d[i + 1][t[i]], dv);
            }
        }
    }

    int ans = INF;

    forn(i, m) ans = min(ans, d[n][i]);

    cout << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();

    return 0;
}