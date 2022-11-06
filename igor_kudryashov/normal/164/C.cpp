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
const int INF = 2 * 1000 * 1000 * 1000;

const int N = 10 * 1000 + 3;

struct edge
{
    int to, f, c, cost, rev;
};

int n, k;
int start[N], len[N], cost[N];
vector <edge> g[N];

void add (int from, int to, int c, int cost)
{
    edge forw = {to, 0, c, cost, sz(g[to])};
    edge back = {from, 0, 0, -cost, sz(g[from])};
    
    g[from].pb(forw);
    g[to].pb(back);
}

int d[N];
int q[N], tail, head;
int inQ[N];
int p[N], pe[N];

bool enlarge (int s, int t)
{
    forn(i, t + 1) d[i] = -INF;
    tail = head = 0;
    q[tail++] = s;
    inQ[s] = true;
    d[s] = 0;
    
    while (head != tail)
    {
        int v = q[head];
        if (++head == N) head = 0;
        inQ[v] = false;
        
        forn(i, sz(g[v]))
        {
            edge& e = g[v][i];
            
            if (e.f < e.c && d[e.to] < d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                p[e.to] = v;
                pe[e.to] = i;
                
                if (!inQ[e.to])
                {
                    inQ[e.to] = true;
                    q[tail] = e.to;
                    if (++tail == N) tail = 0;
                }
            }
        }
    }
    
    if (d[t] == -INF) return false;
    
    for (int v = t; v != s; v = p[v])
    {
        edge& e = g[p[v]][pe[v]];
        e.f++;
        g[e.to][e.rev].f--;
    }
    
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> k;
    
    forn(i, n)
        scanf("%d%d%d", &start[i], &len[i], &cost[i]);
        
    int midS = 2 * n, s = midS + 1, t = s + 1;
    
    add(s, midS, k, 0);

    forn(i, n)
    {
        add(midS, i, 1, 0);
        add(i, i + n, 1, cost[i]);
        add(i + n, t, 1, 0);
    }
    
    forn(i, n)
        forn(j, n)
            if (start[j] >= start[i] + len[i])
                add(i + n, j, 1, 0);
                
    while (enlarge(s, t));
    
    forn(i, n)
        forn(j, sz(g[i]))
            if (g[i][j].to == i + n)
                printf("%d ", g[i][j].f);
                
    puts("");
        
    return 0;
}