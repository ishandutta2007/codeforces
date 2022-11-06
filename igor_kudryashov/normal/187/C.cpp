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

int n, m, k;
int good[N];
vector <int> g[N];
int s, t;
int d[N];
int inQ[N];

bool can (int mid)
{
    queue <int> q;
    q.push(s);
    inQ[s] = true;
    
    memset(d, 63, sizeof(d));
    d[s] = 0;
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        inQ[v] = false;
        
        if (d[v] == mid) continue;
        
        forn(i, sz(g[v]))
        {
            int to = g[v][i];
            int nd = d[v] + 1;
            if (good[to]) nd = 0;
            
            if (d[to] > nd)
            {
                d[to] = nd;
                
                if (!inQ[to])
                {
                    inQ[to] = true;
                    q.push(to);
                }
            }
        }
    }
    
    return d[t] <= mid;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> k;
    
    forn(i, k)
    {
        int cur;
        scanf("%d", &cur);
        --cur;
        good[cur] = true;
    }
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    cin >> s >> t;
    --s, --t;
    
    int lf = 0, rg = n;
    
    while (lf != rg)
    {
        int mid = (lf + rg) >> 1;
        
        if (can(mid))
            rg = mid;
        else
            lf = mid + 1;
    }
    
    if (can(lf))
        cout << lf << endl;
    else
        puts("-1");

    return 0;
}