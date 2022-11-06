#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 2000 + 3;

int n;
int f[N][N];
int sq, cir;
int used[N][N], u;
pt lf;
int minx, maxx, miny, maxy;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector <pt> fig;

void bfs (int sx, int sy)
{
    queue <pt> q;
    q.push(mp(sx, sy));
    used[sx][sy] = u;
    
    while (!q.empty())
    {
        int x = q.front().ft, y = q.front().sc;
        q.pop();
        
        fig.pb(mp(x, y));
        
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
        
        lf = min(lf, mp(x, y));
        
        forn(i, 4)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty, n, n) || used[tx][ty] == u || f[tx][ty] == 0)
                continue;
                
            used[tx][ty] = u;
            q.push(mp(tx, ty));
        }
    }
}

inline ld dist (const pt& a, const pt& b) { return sqrt(sqr(ld(a.ft - b.ft)) + sqr(ld(a.sc - b.sc))); }
inline pt operator - (const pt& a, const pt& b) { return mp(a.ft - b.ft, a.sc - b.sc); }

inline ld angle (const pt& v) { return atan2(ld(v.sc), ld(v.ft)); }

bool bord (pt p)
{
    forn(i, 4)
    {
        int tx = p.ft + dx[i], ty = p.sc + dy[i];
        if (correct(tx, ty, n, n) && f[tx][ty] == 0)
            return true;
    }
    return false;
}

void calc (int x, int y)
{
    u++;
    lf = mp(INF, INF);
    minx = miny = INF;
    maxx = maxy = -INF;
    fig.clear();
    bfs(x, y);
    
    {
        ld maxD = 0.0;
        
        forn(i, sz(fig))
            maxD = max(maxD, dist(lf, fig[i]));
        
        if (maxD < 15)
            return;
    }
    
    int midx = (maxx + minx) / 2;
    int midy = (maxy + miny) / 2;
    int idx = -1;
    li bestD = li(1e18);
    
    forn(i, sz(fig))
    {
        li curd = sqr(li(fig[i].ft - midx)) + sqr(li(fig[i].sc - midy));
        if (curd < bestD)
            bestD = curd, idx = i;
    }
    assert(idx != -1);
    pt curP = fig[idx];
    
    ld minD = 1e18, maxD = -1e18;
    
    forn(i, sz(fig))
        if (bord(fig[i]))
        {
            minD = min(minD, dist(curP, fig[i]));
            maxD = max(maxD, dist(curP, fig[i]));
        }       
        
    //cerr << maxD << ' ' << minD << endl;
    
    if (maxD / minD > 1.3)
        sq++;
    else
        cir++;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        forn(j, n)
            scanf("%d", &f[i][j]);
            
    forn(i, n)
        forn(j, n)
            if (f[i][j] == 1 && used[i][j] == 0)
                calc(i, j);
                
    cout << cir << ' ' << sq << endl;

    return 0;
}