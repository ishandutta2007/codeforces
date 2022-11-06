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

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n;
int a[N][N], b[N][N];
int cir, sq;
vector <pt> fig;
int used[N][N];
int minx, maxx, miny, maxy;

void dfs (int x, int y)
{
    fig.pb(mp(x, y));
    used[x][y] = true;
    
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
    
    forn(i, 4)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (correct(tx, ty, n, n) && !used[tx][ty] && a[tx][ty] == 1)
            dfs(tx, ty);
    }
}

void calc (int x, int y)
{
    fig.clear();
    minx = miny = INF;
    maxx = maxy = -INF;
    dfs(x, y);
    
    if (sz(fig) < 100)
        return;
        
    ld cx = 0.0, cy = 0.0;
    forn(i, sz(fig))
        cx += fig[i].ft, cy += fig[i].sc;
    cx /= ld(sz(fig)), cy /= ld(sz(fig));
    //ld cx = (minx + maxx) / 2.0, cy = (miny + maxy) / 2.0;
    
    ld r = 0.0;
    forn(i, sz(fig))
        r = max(r, sqr(cx - fig[i].ft) + sqr(cy - fig[i].sc));
        
    //cerr << sz(fig) / r << endl;
        
    if (sz(fig) / r < 2.3)
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
            scanf("%d", &a[i][j]);
            
    forn(i, n)
        forn(j, n)
            if (a[i][j] == 0)
            {
                int cnt = 0;
                
                for (int dx = -2; dx <= 2; dx++)
                    for (int dy = -2; dy <= 2; dy++)
                    {
                        int tx = i + dx, ty = j + dy;
                        if (correct(tx, ty, n, n) && a[tx][ty] == 1)
                            cnt++;
                    }
                    
                if (cnt > 12)
                    b[i][j] = 1;
            
            } else
                b[i][j] = 1;
                
    memcpy(a, b, sizeof(a));
    
    forn(i, n)
        forn(j, n)
            if (a[i][j] == 1 && !used[i][j])
                calc(i, j);
                
    cout << cir << ' ' << sq << endl;

    return 0;
}