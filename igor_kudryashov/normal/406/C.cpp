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

const int N = 100 * 1000 + 13;

int n, m;
vector <int> g[N];
int p[N];
int used[N];
int dep[N];

void dfs (int v)
{
    used[v] = true;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (used[to]) continue;
        
        dep[to] = dep[v] + 1;
        p[to] = v;
        dfs(to);
    }
}

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    return true;
}

set <int> gs[N], gtree[N];
vector <int> ans[N];
int szans;
set <pair <pt, int> > ord;

inline void add (int a, int b, int c)
{
    //cerr << "add = " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    ans[szans].pb(a);
    ans[szans].pb(b);
    ans[szans].pb(c);
    szans++;
}

inline void solve()
{
    if (m % 2 == 1)
    {
        puts("No solution");
        return;
    }
    
    memset(p, -1, sizeof(p));
    dfs(0);
    
    //forn(i, n) cerr << p[i] + 1 << ' '; cerr << endl;
    
    forn(i, n)
        forn(j, sz(g[i]))
        {
            int to = g[i][j];
            if (p[to] == i) gtree[i].insert(to);
            if (to == p[i] || p[to] == i) continue;
            gs[i].insert(to);
        }
    
    forn(i, n)
        while (sz(gs[i]) >= 2)
        {
            int v1 = *gs[i].rbegin();
            gs[i].erase(--gs[i].end());
            gs[v1].erase(i);
            int v2 = *gs[i].rbegin();
            gs[i].erase(--gs[i].end());
            gs[v2].erase(i);
            add(v1, i, v2);
        }
        
    //cerr << "szans = " << szans << endl; forn(i, szans) { forn(j, sz(ans[i])) cerr << ans[i][j] + 1 << ' '; cerr << endl; }
        
    forn(i, n) if (gtree[i].empty()) ord.insert(mp(mp(dep[i], sz(gs[i])), i));
    
    while (!ord.empty())
    {
        int v = ord.rbegin()->sc;
        ord.erase(--ord.end());
        //cerr << "v = " << v + 1 << endl;
        
        assert(gtree[v].empty());
        
        if (p[v] == -1 || !gtree[p[v]].count(v)) continue;
        
        if (!gs[v].empty())
        {
            assert(sz(gs[v]) == 1);
            int to = *gs[v].begin();
            gs[v].erase(to);
            gs[to].erase(v);
            
            gtree[p[v]].erase(v);
            if (gtree[p[v]].empty()) ord.insert(mp(mp(dep[p[v]], sz(gs[p[v]])), p[v]));
            
            add(to, v, p[v]);
            continue;
        }
        
        if (sz(gtree[p[v]]) >= 2)
        {
            gtree[p[v]].erase(v);
            int to = *gtree[p[v]].begin();
            gtree[p[v]].erase(gtree[p[v]].begin());
            assert(gs[to].empty());
            
            add(v, p[v], to);
            if (gtree[p[v]].empty()) ord.insert(mp(mp(dep[p[v]], sz(gs[p[v]])), p[v]));
            continue;
        }
        
        if (!gs[p[v]].empty())
        {
            assert(sz(gs[p[v]]) == 1);
            int to = *gs[p[v]].begin();
            gs[p[v]].erase(to);
            gs[to].erase(p[v]);
            
            gtree[p[v]].erase(v);
            if (gtree[p[v]].empty()) ord.insert(mp(mp(dep[p[v]], sz(gs[p[v]])), p[v]));
            
            add(v, p[v], to);
            continue;
        }
        
        assert(p[p[v]] != -1);
        
        gtree[p[v]].erase(v);
        gtree[p[p[v]]].erase(p[v]);
        if (gtree[p[p[v]]].empty()) ord.insert(mp(mp(dep[p[p[v]]], sz(gs[p[p[v]]])), p[p[v]]));
        
        add(v, p[v], p[p[v]]);
    }
    
    forn(i, szans)
    {
        forn(j, sz(ans[i])) printf("%d ", ans[i][j] + 1);
        puts("");
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
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}