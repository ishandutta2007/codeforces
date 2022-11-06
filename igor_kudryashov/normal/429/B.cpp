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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 + 3;

int n, m;
int a[N][N];
int d[2][2][N][N];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, n) forn(j, m) assert(scanf("%d", &a[i][j]) == 1);
    
    return true;
}

void bfs (const pt& start, int d[N][N], int mask)
{
    forn(i, n) forn(j, m) d[i][j] = -1;
    
    queue <pt> q;
    q.push(start);
    
    d[start.x][start.y] = a[start.x][start.y];
    
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        
        forn(i, 4)
        {
            if ((mask & (1 << i)) == 0) continue;
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty, n, m)) continue;
            
            if (d[tx][ty] < d[x][y] + a[tx][ty])
            {
                d[tx][ty] = d[x][y] + a[tx][ty];
                q.push(mp(tx, ty));
            }
        }
    }
}

inline void solve()
{
    bfs(mp(0, 0), d[0][0], (1 << 1) | (1 << 2));
    bfs(mp(n - 1, m - 1), d[0][1], (1 << 0) | (1 << 3));
    bfs(mp(n - 1, 0), d[1][0], (1 << 0) | (1 << 2));
    bfs(mp(0, m - 1), d[1][1], (1 << 1) | (1 << 3));
    
    /*forn(i, n) { forn(j, m) cerr << a[i][j] << ' '; cerr << endl; } cerr << endl;
    
    forn(t1, 2) forn(t2, 2)
    {
        forn(i, n)
        {
            forn(j, m) printf("%d ", d[t1][t2][i][j]);
            puts("");
        }
        puts("");
    }*/
    
    int ans = 0;
    
    forl(i, n - 2) forl(j, m - 2)
    {
        int v1 = d[0][0][i][j - 1] + d[0][1][i][j + 1] + d[1][0][i + 1][j] + d[1][1][i - 1][j];
        int v2 = d[0][0][i - 1][j] + d[0][1][i + 1][j] + d[1][0][i][j - 1] + d[1][1][i][j + 1];
        
        ans = max(ans, max(v1, v2));
    }
    
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
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}