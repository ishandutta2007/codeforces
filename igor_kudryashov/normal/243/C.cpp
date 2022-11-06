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
typedef pair<li, li> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 3000 + 13;

int n;
pt p[N];
li xs[N], ys[N];
int szxs, szys;
int a[N][N];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
char dirs[] = { 'D', 'U', 'R', 'L' };

inline int getDir (char c) { forn(i, 4) if (dirs[i] == c) return i; throw; }

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    li curx = li(1e10) / 2, cury = li(1e10) / 2;
    
    for (int d = -1; d <= 1; d++)
        xs[szxs++] = curx + d, ys[szys++] = cury + d;
        
    p[0] = mp(curx, cury);  
    
    forn(i, n)
    {
        char c;
        int len;
        assert(scanf(" %c %d", &c, &len) == 2);
        int dir = getDir(c);
        
        curx += dx[dir] * len, cury += dy[dir] * len;
        
        for (int d = -1; d <= 1; d++)
            xs[szxs++] = curx + d, ys[szys++] = cury + d;
            
        p[i + 1] = mp(curx, cury);
    }
    
    return true;
}

int used[N][N];

void dfs (int x, int y)
{
    used[x][y] = true;
    
    forn(i, 4)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (!correct(tx, ty, szxs, szys) || a[tx][ty] == 1) continue;
        if (used[tx][ty]) continue;
        dfs(tx, ty);
    }
}

inline void solve()
{
    //forn(i, n + 1) cerr << p[i].x << ' ' << p[i].y << endl;
    //forn(i, n + 1) cerr << p[i].x - li(5e9) << ' ' << p[i].y - li(5e9) << endl;

    sort(xs, xs + szxs);
    szxs = int(unique(xs, xs + szxs) - xs);
    sort(ys, ys + szys);
    szys = int(unique(ys, ys + szys) - ys);
    
    forn(i, n)
    {
        int xlf = int(lower_bound(xs, xs + szxs, p[i].x) - xs);
        int xrg = int(lower_bound(xs, xs + szxs, p[i + 1].x) - xs);
        int ylf = int(lower_bound(ys, ys + szys, p[i].y) - ys);
        int yrg = int(lower_bound(ys, ys + szys, p[i + 1].y) - ys);
        
        if (xlf > xrg) swap(xlf, xrg);
        if (ylf > yrg) swap(ylf, yrg);
        
        for (int x = xlf; x <= xrg; x++)
            for (int y = ylf; y <= yrg; y++)
                a[x][y] = 1;
    }
    
    //forn(i, szxs) cerr << xs[i] - li(5e9) << ' '; cerr << endl;
    //forn(i, szys) cerr << ys[i] - li(5e9) << ' '; cerr << endl;
    
    dfs(0, 0);
    
    /*forn(i, szxs)
    {
        forn(j, szys)
            cerr << used[i][j];
        cerr << endl;
    }
    
    forn(i, szxs)
    {
        forn(j, szys)
            cerr << a[i][j];
        cerr << endl;
    }*/
    
    li ans = 0;
    
    forn(i, szxs)
        forn(j, szys)
            if (!used[i][j] && a[i][j] == 0)
            {
                //cerr << xs[i] << ' ' << ys[j] << endl;
                //cerr << xs[i + 1] << ' ' << ys[j + 1] << endl;
                
                assert(!used[i + 1][j] && !used[i][j + 1] && !used[i + 1][j + 1]);
                ans += (xs[i + 1] - xs[i]) * 1LL * (ys[j + 1] - ys[j]);
            } else if (!used[i][j] && a[i][j] == 1)
            {
                if (!used[i + 1][j]) ans += xs[i + 1] - xs[i];
                if (!used[i][j + 1]) ans += ys[j + 1] - ys[j];
                if (!used[i + 1][j] && !used[i][j + 1]) ans--;
                if (used[i + 1][j] && used[i][j + 1]) ans++;
            }
            
    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}