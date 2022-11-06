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

const int M = 100 + 3;
const int N = M * M;

struct edge
{
    int to, f, c, cost, rev;
};

int n, m;
int a[M][M];
vector <edge> g[N];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forn(i, n)
        forn(j, m)
            assert(scanf("%d", &a[i][j]) == 1);
            
    return true;
}

void add (int from, int to, int c, int cost)
{
    edge forw = { to, 0, c, cost, sz(g[to]) };
    edge back = { from, 0, 0, -cost, sz(g[from]) };
    
    g[from].pb(forw);
    g[to].pb(back);
}

int q[N], tail, head, inq[N];
int d[N], p[N], pe[N]; // BE SURE d INTEGER, NOT LONG !!!

inline bool enlarge (int s, int t)
{
    tail = head = 0;
    
    forn(i, t + 1) d[i] = INF;
    d[s] = 0;
    
    q[tail++] = s;
    inq[s] = true;
    
    while (tail != head)
    {
        int v = q[head];
        inq[v] = false;
        if (++head == N) head = 0;
        
        forn(i, sz(g[v]))
        {
            const edge& e = g[v][i];
            
            if (e.f < e.c && d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                p[e.to] = v;
                pe[e.to] = i;
                
                if (!inq[e.to])
                {
                    inq[e.to] = true;
                    q[tail] = e.to;
                    if (++tail == N) tail = 0;
                }
            }
        }
    }
    
    if (d[t] > INF / 2) return false; // BE SURE THAT INF / 2 IS ENOUGH !!!
    
    int flow = INF;
    for (int v = t; v != s; v = p[v])
        flow = min(flow, g[p[v]][pe[v]].c - g[p[v]][pe[v]].f);
    
    for (int v = t; v != s; v = p[v])
    {
        edge& e = g[p[v]][pe[v]];
        e.f += flow;
        g[v][e.rev].f -= flow;
    }
    
    return true;
}

inline void solve()
{
    const int s = n * m, t = s + 1;
    
    forn(i, n)
        forn(j, m)
        {
            int num = i * m + j;
            
            if ((i + j) & 1)
            {
                add(num, t, 1, 0);
                continue;
                
            } else
                add(s, num, 1, 0);
            
            forn(k, 4)
            {
                int tx = i + dx[k], ty = j + dy[k];
                if (!correct(tx, ty, n, m)) continue;
                
                int cost = (a[i][j] != a[tx][ty]);
                
                add(num, tx * m + ty, 1, cost);
            }
        }
        
    while (enlarge(s, t));
    
    int ans = 0;
    
    forn(i, n)
        forn(j, m)
        {
            int num = i * m + j;
            forn(k, sz(g[num]))
                if (g[num][k].f > 0)
                    ans += g[num][k].cost;
        }
        
    //assert(ans % 2 == 0 && ans <= n * m / 2);
        
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