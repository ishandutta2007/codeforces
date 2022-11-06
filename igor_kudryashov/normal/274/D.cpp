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

const int N = 100 * 1000 + 3;
const int M = 1000 * 1000 + 3;

int n, m;
vector <int> a[N];
vector <int> g[M];
int cntv;
int deg[M];
int c[M];
int used[M];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forn(i, n)
    {
        a[i].resize(m);
        forn(j, m) assert(scanf("%d", &a[i][j]) == 1);
    }
    
    return true;
}

vector <int> perm;

void dfs2 (int v)
{
    used[v] = true;
    forn(i, sz(g[v]))
        if (!used[g[v][i]])
            dfs2(g[v][i]);
    perm.pb(v);
}

bool dfs (int v)
{
    c[v] = 1;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (c[to] == 1) return true;
        if (c[to] == 0 && dfs(to)) return true;
    }
    
    c[v] = 2;
    return false;
}

inline void solve()
{
    cntv = m;
    
    forn(i, n)
    {
        vector <int> vals;
        forn(j, m) if (a[i][j] != -1) vals.pb(a[i][j]);
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        
        vector <int> idxs;
        forn(j, sz(vals)) idxs.pb(cntv++);
        
        forn(j, m)
        {
            if (a[i][j] == -1) continue;
            int idx = int(lower_bound(all(vals), a[i][j]) - vals.begin());
            
            if (idx < sz(vals))
            {
                g[j].pb(idxs[idx]);
                deg[idxs[idx]]++;
            }
            
            if (--idx >= 0)
            {
                g[idxs[idx]].pb(j);
                deg[j]++;
            }
        }
        
        forn(j, sz(idxs) - 1)
        {
            int a = idxs[j], b = idxs[j + 1];
            g[a].pb(b);
            deg[b]++;
        }
    }
    
    forn(i, cntv)
        if (c[i] == 0 && dfs(i))
        {
            puts("-1");
            return;
        }
    
    forn(i, cntv)
        if (deg[i] == 0)
            dfs2(i);
            
    reverse(all(perm));
        
    forn(i, sz(perm))
        if (perm[i] < m)
            printf("%d ", perm[i] + 1);
    puts("");
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