#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

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

const int N = 1000 + 3;
const int SH = 500;

int dx[] = {0, 0, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 0};

int a[N][N], add[N][N];
int used[N][N], u;
int n, m;
pt cur[N * N], next[N * N];
int szcur, sznext;

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;

    return true;
}

void prepare ()
{
    a[SH][SH] = n;
    if (n >= 4) cur[szcur++] = mp(SH, SH);
    
    while (szcur > 0)
    {
    /*fore(i, -10, 10)
    {
        fore(j, -10, 10)
            cerr << a[SH + i][SH + j] << ' ';
        cerr << endl;
    }
    cerr << endl;*/
    
        u++;
        
        forn(i, szcur)
        {
            forn(j, 4)
            {
                int tx = cur[i].x + dx[j], ty = cur[i].y + dy[j];
                //assert(correct(tx, ty, N, N));
                
                if (used[tx][ty] != u) used[tx][ty] = u, add[tx][ty] = 0;
                add[tx][ty] += (a[cur[i].x][cur[i].y] >> 2);
            }
            
            if (used[cur[i].x][cur[i].y] != u) used[cur[i].x][cur[i].y] = u, add[cur[i].x][cur[i].y] = 0;
            add[cur[i].x][cur[i].y] -= a[cur[i].x][cur[i].y] - (a[cur[i].x][cur[i].y] & 3);
        }
        
    
    /*fore(i, -10, 10)
    {
        fore(j, -10, 10)
            if (used[SH + i][SH + j] == u)
                cerr << add[SH + i][SH + j] << ' ';
            else
                cerr << 0 << ' ';
        cerr << endl;
    }
    cerr << endl;   */
        
        sznext = 0;
        u++;
        
        forn(i, szcur)
            forn(j, 5)
            {
                int tx = cur[i].x + dx[j], ty = cur[i].y + dy[j];
                if (used[tx][ty] == u) continue;
                a[tx][ty] += add[tx][ty];
                used[tx][ty] = u;
                if (a[tx][ty] >= 4) next[sznext++] = mp(tx, ty);
            }
            
        szcur = sznext;
        forn(i, szcur) cur[i] = next[i];
    }
}

inline void solve()
{
    prepare();
    
    /*fore(i, -10, 10)
    {
        fore(j, -10, 10)
            cerr << a[SH + i][SH + j] << ' ';
        cerr << endl;
    }*/
    
    forn(i, m)
    {
        int x, y;
        assert(scanf("%d%d", &x, &y) == 2);
        
        x += SH, y += SH;
        
        if (x < 0 || x >= N || y < 0 || y >= N)
            puts("0");
        else
            printf("%d\n", a[x][y]);
    }
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
    cerr << clock() << endl;
    
    return 0;
}