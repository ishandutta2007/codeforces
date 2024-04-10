#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

const int N = 50 + 13;

int n, m;
int d[N];
vector <int> g[N];
int c[N];
int col = 0;
int used[N];

void dfs (int v)
{
    c[v] = col;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        
        if (c[to] == 0)
            dfs(to);
    }
}

void dfs2 (int v)
{
    used[v] = true;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        
        if (!used[to])
            dfs2(to);
    }
}

bool bad ()
{
    memset(used, 0, sizeof(used));
    
    dfs2(0);
    
    forn(i, n)
        if (!used[i])
            return true;
            
    return false;
}

int main()
{
 
    cin >> n >> m;
    
    if (n == 1)
    {
        if (m == 1)
            printf("YES\n0\n");
        else if (m == 0)
            printf("YES\n1\n1 1\n");
        else
            puts("NO");
            
        return 0;
    }
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        
        d[a]++, d[b]++;
        
        if (d[a] == 3 || d[b] == 3)
        {
            puts("NO");
            return 0;
        }
        
        g[a].pb(b);
        g[b].pb(a);
    }
    
    vector <pt> v;
    
    forn(i, n)
        if (d[i] == 1 && c[i] == 0)
        {
            col++;
            
            dfs(i);
            
            pt p = mp(i, -1);
            
            forn(j, n)
                if (i != j && c[j] == col && d[j] == 1)
                    p.sc = j;
                    
            if (p.ft > p.sc)
                swap(p.ft, p.sc);
                
            v.pb(p);
        } else if (d[i] == 0)
            v.pb(mp(i, i));
        
    vector <pt> ans;
        
    while (sz(v) > 1)
    {   
        sort(all(v));
        
        pt f = *(v.begin());
        v.erase(v.begin());
        
        pt s = *(v.begin());
        v.erase(v.begin());
        
        ans.pb(mp(f.ft, s.ft));
        
        g[f.ft].pb(s.ft);
        g[s.ft].pb(f.ft);
        
        pt nw = mp(f.sc, s.sc);
        if (nw.ft > nw.sc)
            swap(nw.ft, nw.sc);
        
        v.pb(nw);
    }
    
    if (!v.empty())
    {
        ans.pb(mp(v[0].ft, v[0].sc));
        
        g[v[0].ft].pb(v[0].sc);
        g[v[0].sc].pb(v[0].ft);
    }
    
    if (bad())
    {
        puts("NO");
        return 0;
    }
    
    sort(all(ans));
    
    puts("YES");
    
    cout << sz(ans) << endl;
    
    forn(i, sz(ans))
        printf("%d %d\n", ans[i].ft + 1, ans[i].sc + 1);
    
    return 0;
}