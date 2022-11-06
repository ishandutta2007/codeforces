#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <numeric>
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
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
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

const int N = 300 * 1000 + 13;

int n, m;
vector <int> g[N];
int used[N], u, c[N];

void dfs (int v, int col)
{
    used[v] = u;
    c[v] = col;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (used[to] != u) dfs(to, col ^ 1);
    }
}

bool check ()
{
    forn(i, n)
    {
        int cnt[] = {0, 0};
        
        forn(j, sz(g[i])) cnt[c[g[i][j]]]++;
        
        if (cnt[c[i]] > 1) return false;
    }
    
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    while (true)
    {
        u++;
        forn(i, n) random_shuffle(all(g[i]));
        
        forn(i, n)
            if (used[i] != u)
                dfs(i, 0);
        
        const int M = 5;
    
        forn(iter, M)
        {
            bool ok = true;
            
            forn(i, n)
            {
                int cnt[] = {0, 0};
                
                forn(j, sz(g[i])) cnt[c[g[i][j]]]++;
                
                if (cnt[c[i]] > 1)
                {
                    c[i] ^= 1;
                    ok = false;
                }
            }
            
            if (ok) break;
        }
        
        if (check())
        {
            forn(i, n) putchar('0' + c[i]);
            puts("");
            return 0;
        }
        
        if (clock() > 1800)
        {
            puts("-1");
            return 0;
        }
    }
    
    return 0;
}