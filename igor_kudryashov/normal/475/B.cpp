#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 20 + 3;

int n, m;
char s[2][N];
vector<pt> g[N][N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    forn(i, 2) assert(scanf("%s", s[i]) == 1);
    return true;
}

int used[N][N], u;

void dfs (int x, int y)
{
    used[x][y] = u;
    
    forn(i, sz(g[x][y]))
    {
        int tx = g[x][y][i].ft, ty = g[x][y][i].sc;
        if (used[tx][ty] != u) dfs(tx, ty);
    }
}

inline void solve()
{
    forn(i, n) forn(j, m)
    {
        pt to1 = mp(i, j + 1);
        if (s[0][i] == '<') to1.sc = j - 1;
        if (correct(to1.x, to1.y, n, m)) g[i][j].pb(to1);
        
        pt to2 = mp(i + 1, j);
        if (s[1][j] == '^') to2.ft = i - 1;
        if (correct(to2.x, to2.y, n, m)) g[i][j].pb(to2);
    }
    
    forn(i, n) forn(j, m)
    {
        u++;
        dfs(i, j);
        forn(ii, n) forn(jj, m) if (used[ii][jj] != u)
        {
            puts("NO");
            return;
        }
    }
    
    puts("YES");
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
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}