#undef NDEBUG
#ifdef SU2_PROJ
//#define _GLIBCXX_DEBUG
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

const int N = 22 + 3;
const int N2 = N * N;

struct body
{
    int x, y, v;
    body (int x, int y, int v) : x(x), y(y), v(v) {}
};

int n, m;
vector<body> bs[2];
char f[N][N];

inline bool read()
{
    int males, females;
    if (scanf("%d%d%d%d", &n, &m, &males, &females) != 4) return false;
    forn(i, n) assert(scanf("%s", f[i]) == 1);
    int x, y, v;
    assert(scanf("%d%d%d", &x, &y, &v) == 3);
    x--, y--;
    if (males + 1 == females) bs[0].pb(body(x, y, v));
    else if (females + 1 == males) bs[1].pb(body(x, y, v));
    else
    {
        puts("-1");
        exit(0);
    }
    
    forn(i, males)
    {
        assert(scanf("%d%d%d", &x, &y, &v) == 3);
        x--, y--;
        bs[0].pb(body(x, y, v));
    }
    
    forn(i, females)
    {
        assert(scanf("%d%d%d", &x, &y, &v) == 3);
        x--, y--;
        bs[1].pb(body(x, y, v));
    }
    
    return true;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

li z[N][N];

inline void bfs (const body& b)
{
    queue<pt> q;
    q.push(mp(b.x, b.y));
    
    forn(i, n) forn(j, m) z[i][j] = INF64 + 13;
    z[b.x][b.y] = 0;
    
    //cerr << b.x << ' ' << b.y << endl;
    
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        
        forn(i, 4)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty, n, m) || f[tx][ty] == '#') continue;
            if (z[tx][ty] > z[x][y] + b.v)
            {
                z[tx][ty] = z[x][y] + b.v;
                q.push(mp(tx, ty));
            }
        }
    }
}

struct edge
{
    int to, f, c, rev;
};

const int SZG = 4 * N2 + 13;

int S, T;
vector<edge> g[SZG];

inline void add (int from, int to, int cap)
{
    edge f = { to, 0, cap, sz(g[to]) };
    edge b = { from, 0, 0, sz(g[from]) };
    g[from].pb(f);
    g[to].pb(b);
}

int lev[SZG];
int head, tail, q[SZG];

inline bool bfs(int s, int t)
{
    memset(lev, 63, sizeof(lev));
    head = tail = 0;

    lev[s] = 0;
    q[head++] = s;

    while (head != tail)
    {
        int v = q[tail++];

        forn(i, sz(g[v]))
            if (g[v][i].f < g[v][i].c && lev[g[v][i].to] > lev[v] + 1)
            {
                lev[g[v][i].to] = lev[v] + 1;
                q[head++] = g[v][i].to;
            }
    }

    return lev[t] < INF / 2;
}

int ptr[SZG];

int dfs(int v, int t, int f)
{
    if (v == t) return f;

    for ( ; ptr[v] < sz(g[v]); ptr[v]++)
    {
        edge& e = g[v][ptr[v]];
        if (e.f == e.c || lev[e.to] != lev[v] + 1) continue;

        int df = dfs(e.to, t, min(f, e.c - e.f));

        if (df > 0)
        {
            e.f += df;
            g[e.to][e.rev].f -= df;
            return df;
        }
    }

    return 0;
}

inline int dinic(int s, int t)
{
    int ans = 0;

    while (bfs(s, t))
    {
        memset(ptr, 0, sizeof(ptr));

        for (int f; (f = dfs(s, t, INF)) != 0; ans += f);
    }

    return ans;
}

li dists[2][N2][N][N];

inline void buildGraph(const li& mid)
{
    S = sz(bs[0]) + 2 * n * m + sz(bs[1]);
    T = S + 1;
    
    forn(i, T) g[i].clear();
    
    forn(i, sz(bs[0])) add(S, i, 1);

    forn(i, sz(bs[0])) forn(x, n) forn(y, m) if (dists[0][i][x][y] <= mid)
        add(i, sz(bs[0]) + x * m + y, 1);
        
    forn(x, n) forn(y, m) add(sz(bs[0]) + x * m + y, sz(bs[0]) + n * m + x * m + y, 1);
    
    forn(i, sz(bs[1])) forn(x, n) forn(y, m) if (dists[1][i][x][y] <= mid)
        add(sz(bs[0]) + n * m + x * m + y, sz(bs[0]) + 2 * n * m + i, 1);
        
    forn(i, sz(bs[1])) add(sz(bs[0]) + 2 * n * m + i, T, 1);
    
    //forn(i, T) { forn(j, sz(g[i])) cerr << i << ' ' << g[i][j].to << endl; cerr << endl; }
}

inline bool can (const li& mid)
{
    buildGraph(mid);
    return dinic(S, T) == sz(bs[0]);
}

inline void prepare ()
{
    forn(it, 2) forn(i, N2) forn(j, N) forn(k, N) dists[it][i][j][k] = INF64 + 13;
    
    forn(it, 2) forn(i, sz(bs[it]))
    {
        bfs(bs[it][i]);
        forn(x, n) forn(y, m) dists[it][i][x][y] = z[x][y];
    }
}

inline void solve()
{
    prepare();
    
    /*forn(it, 2) forn(i, sz(bs[it]))
    {
        cerr << it << ' ' << i << endl;
        forn(x, n) { forn(y, m) cerr << dists[it][i][x][y] << ' '; cerr << endl; }
        cerr << endl;
    }*/
    
    li lf = 0, rg = INF64;
    
    while (lf != rg)
    {
        li mid = (lf + rg) >> 1;
        if (can(mid)) rg = mid;
        else lf = mid + 1;
    }
    
    if (can(lf)) cout << lf << endl;
    else puts("-1");
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