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

const int N = 1600 + 13;

int n, m;
char f[N][N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forn(i, n)
        forn(j, m)
        {
            int tmp;
            assert(scanf("%d", &tmp) == 1);
            f[i][j] = char(tmp);
        }
            
    return true;
}

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool used[N][N];
pt comp[N * N];
int szcomp;
int d[N][N];
int delps[N][N];
bool elps[N][N];

void dfs (int x, int y)
{
    used[x][y] = true;
    comp[szcomp++] = mp(x, y);
    
    forn(i, 8)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (!correct(tx, ty, n, m) || used[tx][ty] || f[tx][ty] != 1) continue;
        dfs(tx, ty);
    }
}

inline bool bord (const pt& a)
{
    forn(i, 8)
    {
        int tx = a.x + dx[i], ty = a.y + dy[i];
        if (!correct(tx, ty, n, m) || f[tx][ty] == 0) return true;
    }
    return false;
}

const int M2 = 7; // distance to ellipse, > M

void dfse (int x, int y)
{
    elps[x][y] = true;
    
    forn(i, 8)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (!correct(tx, ty, n, m) || f[tx][ty] == 0 || elps[tx][ty] || delps[tx][ty] <= M2) continue;
        dfse(tx, ty);
    }
}

void printEllipse ()
{
    forn(i, n)
    {
        forn(j, m) cerr << (delps[i][j] <= M2);
        cerr << endl;
    }
    cerr << endl;
}

int calc (int sx, int sy)
{
    szcomp = 0;
    dfs(sx, sy);
    
    queue <pt> q;
    
    forn(i, szcomp)
        if (bord(comp[i]))
        {
            d[comp[i].x][comp[i].y] = 0;
            q.push(comp[i]);
        }
    
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        
        forn(i, 8)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty, n, m) || f[tx][ty] == 0 || d[tx][ty] <= d[x][y] + 1) continue;
            d[tx][ty] = d[x][y] + 1;
            q.push(mp(tx, ty));
        }
    }
    
    /*forn(i, n)
    {
        forn(j, m) printf("%10d ", d[i][j]);
        puts("");
    }
    puts("");*/
    
    const int M = 3; // distance from border
    
    forn(i, szcomp)
        if (d[comp[i].x][comp[i].y] > M)
        {
            q.push(comp[i]);
            delps[comp[i].x][comp[i].y] = 0;
        }
        
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        
        forn(i, 8)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty, n, m) || f[tx][ty] == 0 || delps[tx][ty] <= delps[x][y] + 1) continue;
            delps[tx][ty] = delps[x][y] + 1;
            q.push(mp(tx, ty));
        }
    }
    
    /*forn(i, n)
    {
        forn(j, m) printf("%10d ", delps[i][j]);
        puts("");
    }
    puts("");*/
    
    //printEllipse();
    
    int ans = 0;
    
    forn(i, szcomp)
    {
        int x = comp[i].x, y = comp[i].y;
        
        if (elps[x][y] || delps[x][y] <= M2) continue;
        
        ans++;
        dfse(x, y);
    }
    
    return ans; 
}

inline void solve()
{
    forn(i, n) forn(j, m) d[i][j] = delps[i][j] = INF;
    
    vector <int> ans;
    
    forn(i, n)
        forn(j, m)
            if (f[i][j] == 1 && !used[i][j])
                ans.pb(calc(i, j));
                
    //forn(i, sz(ans)) cout << ans[i] << ' '; cout << endl;
                
    sort(all(ans));
    
    cout << sz(ans) << endl;
    forn(i, sz(ans)) printf("%d ", ans[i]);
    puts("");
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