#undef NDEBUG
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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 200 + 13;

struct edge
{
    int to, f, c, rev;
};

int n, m;
vector <edge> g[N];

inline void add (int from, int to, int cap)
{
    edge f = { to, 0, cap, sz(g[to]) };
    edge b = { from, 0, 0, sz(g[from]) };
    g[from].pb(f);
    g[to].pb(b);
}

int lev[N];
int head, tail, q[N];

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

int ptr[N];

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
    forn(i, n) forn(j, sz(g[i])) g[i][j].f = 0;
    
    int ans = 0;

    while (bfs(s, t))
    {
        memset(ptr, 0, sizeof(ptr));

        for (int f; (f = dfs(s, t, INF)) != 0; ans += f);
    }

    return ans;
}

void gomoriHu(int ans[N][N])
{
    static int p[N];
    forn(i, n) p[i] = 0;
    forn(i, n) forn(j, n) ans[i][j] = INF;
    
    forl(i, n - 1)
    {
        int f = dinic(i, p[i]);
        fore(j, i + 1, n - 1) if (lev[j] < INF / 2 && p[j] == p[i]) p[j] = i;
        ans[i][p[i]] = ans[p[i]][i] = f;
        forn(j, i) ans[j][i] = ans[i][j] = min(ans[j][p[i]], f);
    }
    
    forn(i, n) ans[i][i] = 0;
}

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, m)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        add(a, b, c);
        add(b, a, c);
    }
    
    return true;
}

int F[N][N];
int used[N];

inline void solve()
{
    gomoriHu(F);
    
    /*forn(i, n)
    {
        forn(j, n) printf("%d ", F[i][j]);
        puts("");
    }*/
    
    vector <int> ans;
    int ansVal = 0;
    
    ans.pb(0);
    used[0] = true;
    
    forn(i, n - 1)
    {
        int curMax = -1, curPos = -1;
        
        forn(j, n)
            if (!used[j] && F[ans.back()][j] > curMax)
                curMax = F[ans.back()][j], curPos = j;
                
        used[curPos] = true;
        ansVal += F[ans.back()][curPos];
        ans.pb(curPos);
    }
    
    cout << ansVal << endl;
    forn(i, n) printf("%d ", ans[i] + 1);
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
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}