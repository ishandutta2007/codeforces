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

const int N = 1000 + 13;

const li INF64 = li(1e18);

int n, m, S, T;
int t[N], c[N];
vector <pt> g[N];
pt ng[N][N];
int szng[N];
li d[N];
int q[N * N], head, tail, inQ[N];

li bfsNG (int s, int t)
{
    forn(i, n)
        d[i] = INF64;
    d[s] = 0;
    q[tail++] = s;
    inQ[s] = true;
    
    while (head != tail)
    {
        int v = q[head++];
        inQ[v] = false;
        
        forn(i, szng[v])
        {
            int to = ng[v][i].ft, w = ng[v][i].sc;
            
            if (d[to] > d[v] + w)
            {
                d[to] = d[v] + w;
                
                if (!inQ[to])
                {
                    inQ[to] = true;
                    q[tail++] = to;
                }
            }
        }
    }
    
    if (d[t] > INF64 / 4)
        d[t] = -1;
    
    return d[t];
}

void bfs (int s)
{
    forn(i, n)
        d[i] = INF64;
    d[s] = 0;
    q[tail++] = s;
    inQ[s] = true;
    
    while (head != tail)
    {
        int v = q[head++];
        inQ[v] = false;
        
        forn(i, sz(g[v]))
        {
            int to = g[v][i].ft, w = g[v][i].sc;
            
            if (d[to] > d[v] + w)
            {
                d[to] = d[v] + w;
                
                if (!inQ[to])
                {
                    inQ[to] = true;
                    q[tail++] = to;
                }
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> S >> T;
    --S, --T;
    
    forn(i, m)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }
    
    forn(i, n)
        scanf("%d%d", &t[i], &c[i]);
        
    forn(i, n)
    {
        bfs(i);
        
        forn(j, n)
            if (d[j] <= t[i])
                ng[i][szng[i]++] = mp(j, c[i]);
    }
    
    cout << bfsNG(S, T) << endl;

    return 0;
}