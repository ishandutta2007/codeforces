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

const int N = 100 * 1000 + 3;
const int LOGN = 20;

int n, m;
vector <int> sourg[N];
vector <int> g[N], tg[N];
int used[N];
int perm[N], szperm;
int c[N], col;
vector <pt> ed;
set <pt> wasEd;
int p[N][LOGN];
int tin[N], tout[N], t;
set <pt> seenEd;

inline bool parent (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getLen (int a, int pr)
{
    if (a == pr) return 0;
    
    int ans = 0;
    
    ford(i, LOGN)
        if (!parent(p[a][i], pr))
        {
            a = p[a][i];
            ans += (1 << i);
        }
        
    assert(!parent(a, pr) && p[a][0] == pr);
    return ans + 1;
}

int lca (int a, int b)
{
    if (parent(a, b)) return a;
    if (parent(b, a)) return b;
    
    ford(i, LOGN)
        if (!parent(p[a][i], b))
            a = p[a][i];
            
    assert(!parent(a, b) && parent(p[a][0], b));
    return p[a][0];
}

int dist (int a, int b)
{
    if (a == b) return 0;
    int c = lca(a, b);
    return getLen(a, c) + getLen(b, c);
}

void dfsL (int v, int pr)
{
    tin[v] = t++;
    p[v][0] = pr;
    
    for1(i, LOGN - 1)
        p[v][i] = p[p[v][i - 1]][i - 1];
        
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        dfsL(to, v);
    }
    tout[v] = t++;
}

void dfs (int v)
{
    used[v] = true;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        
        if (!used[to])
            dfs(to);
    }
    
    perm[szperm++] = v;
}

void css (int v)
{
    c[v] = col;
    
    forn(i, sz(tg[v]))
    {
        int to = tg[v][i];
        
        if (c[to] == -1)
            css(to);
    }
}

void dfsS (int v)
{
    used[v] = true;
    
    forn(i, sz(sourg[v]))
    {
        int to = sourg[v][i];
        
        if (seenEd.count(mp(min(v, to), max(v, to))))
            continue;
            
        seenEd.insert(mp(min(v, to), max(v, to)));
        
        g[v].pb(to);
        tg[to].pb(v);
        
        if (!used[to])
            dfsS(to);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        ed.pb(mp(a, b));
        sourg[a].pb(b);
        sourg[b].pb(a);
    }
    
    dfsS(0);
    
    /*forn(i, n)
    {
        forn(j, sz(g[i]))
            cerr << g[i][j] << ' ';
        cerr << endl;
    }
    cerr << endl;*/
    
    memset(used, 0, sizeof(used));
    
    forn(i, n)
        if (!used[i])
            dfs(i);
            
    assert(szperm == n);
    reverse(perm, perm + szperm);
    
    memset(c, -1, sizeof(c));
    
    forn(i, n)
        if (c[perm[i]] == -1)
            css(perm[i]), col++;
            
    /*forn(i, n)
        cerr << c[i] << endl;
    cerr << endl;*/
            
    forn(i, n)
        g[i].clear();
        
    forn(i, m)
    {
        int a = c[ed[i].ft], b = c[ed[i].sc];
        if (a > b) swap(a, b);
        
        if (a == b || wasEd.count(mp(a, b))) continue;
        wasEd.insert(mp(a, b));
        
        g[a].pb(b);
        g[b].pb(a);
    }
    
    /*forn(i, n)
    {
        forn(j, sz(g[i]))
            cerr << g[i][j] << ' ';
        cerr << endl;
    }
    cerr << endl;*/
    
    dfsL(0, 0);
    
    int k;
    cin >> k;
    
    forn(i, k)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        a = c[a], b = c[b];
        printf("%d\n", dist(a, b));
    }

    return 0;
}