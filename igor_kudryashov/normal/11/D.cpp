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

const int N = 19;

int n, m;
vector <int> g[N];
int bit[30];
int cntBit[(1 << N) + 13];
int gg[N][N];

li ans = 0;
li d[N][(1 << N) + 13];

void solve ()
{
    forn(i, n)
        forn(mask, bit[n])
            d[i][mask] = 0;
    d[0][1] = 1;
    
    for1(mask, bit[n] - 1)
    {
        forn(i, n)
        {
            li& dv = d[i][mask];
            if (dv == 0)
                continue;
                
            assert(dv > 0);
                
            if (cntBit[mask] > 2 && gg[0][i])
                ans += dv;
                
            forn(j, sz(g[i]))
            {
                int to = g[i][j];
                
                if (mask & bit[to])
                    continue;
                    
                d[to][mask ^ bit[to]] += dv;
            }
        }
    }
}

vector <int> ng[N];

void rebuild ()
{
    forn(i, n - 1)
    {
        ng[i].clear();
        
        forn(j, sz(g[i + 1]))
        {
            int to = g[i + 1][j];
            if (to != 0)
                ng[i].pb(to - 1);
        }
    }
    
    n--;
    forn(i, n)
        g[i] = ng[i];
        
    memset(gg, 0, sizeof(gg));
    
    forn(i, n)
        forn(j, sz(g[i]))
            gg[i][g[i][j]] = true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 30)
        bit[i] = (1 << i);
        
    for1(mask, bit[N] - 1)
        cntBit[mask] = cntBit[mask & (mask - 1)] + 1;
    
    cin >> n >> m;
    
    //int cura = 1, curb = 2;

    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        
        /*a = cura, b = curb;
        curb++;
        if (curb == n + 1)
            cura++, curb = cura + 1;*/
        
        --a, --b;
        
        g[a].pb(b);
        g[b].pb(a);
        
        gg[a][b] = gg[b][a] = true;
    }
    
    while (n > 2)
    {
        solve();
        rebuild();
    }
    
    cout << ans / 2 << endl;

    return 0;
}