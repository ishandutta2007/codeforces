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

const int N = 100 * 1000 + 13;

int n, m;
int a[N], b[N], w[N];
vector <int> g[N];
int h[N];
int c[N], szc[N];
int perm[N];
li we[N];
li ansVal = 0;
int szt[N];

void dfs (int v, int pr)
{
    if (v != 0)
        h[v] = h[pr] + 1;
        
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        
        if (to != pr)
            dfs(to, v);
    }
}

inline bool cmp (int i, int j)
{
    if (w[i] != w[j])
        return w[i] < w[j];
        
    int h1 = max(h[a[i]], h[b[i]]);
    int h2 = max(h[a[j]], h[b[j]]);
    
    if (h1 != h2)
        return h1 > h2;
        
    return i < j;
}

int leader (int v)
{
    return c[v] == v ? v : c[v] = leader(c[v]);
}

inline bool merge (int a, int b)
{
    a = leader(a);
    b = leader(b);
    
    if (a == b)
        return false;
        
    if (rand() & 1)
    {
        c[a] = b;
        szc[b] += szc[a];
    
    } else
    {
        c[b] = a;
        szc[a] += szc[b];
    }
    
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    m = n - 1;
    
    forn(i, m)
    {
        scanf("%d%d%d", &a[i], &b[i], &w[i]);
        --a[i], --b[i];
        
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
        perm[i] = i;
    }
    
    dfs(0, 0);
    
    forn(i, n)
        c[i] = i, szc[i] = 1, szt[i] = 1;
        
    sort(perm, perm + m, cmp);
    
    for (int idx = 0; idx < m; )
    {
        int st = idx;
        
        while (idx < m && w[perm[idx]] == w[perm[st]])
            idx++;
            
        for (int j = st; j < idx; j++)
        {
            int i = perm[j];
            
            int fr = a[i], to = b[i];
            if (h[fr] > h[to])
                swap(fr, to);
                
            szt[to] = szc[leader(to)];
            assert(merge(fr, to));
        }

        for (int j = st; j < idx; j++)
        {
            int i = perm[j];
            
            int fr = a[i], to = b[i];
            if (h[fr] > h[to])
                swap(fr, to);
                
            li c1 = szt[to], c2 = szc[leader(fr)] - szt[to];
            
            we[i] = 2LL * c1 * c2;
            
            ansVal = max(ansVal, we[i]);
        }
    }
    
    vector <int> ans;
    
    forn(i, m)
        if (we[i] == ansVal)
            ans.pb(i);
            
    cout << ansVal << ' ' << sz(ans) << endl;
    
    forn(i, sz(ans))
        printf("%d ", ans[i] + 1);
        
    puts("");

    return 0;
}