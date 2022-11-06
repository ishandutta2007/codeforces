#pragma comment(linker, "/stack:64000000")
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

const int N = 10 * 1000 + 13;

int n, k, l;
int a[N];
int b[25];
int szb = 0;
int dist[25][25];
int d[N];
int leng[100 + 13];
int z[(1 << 20) + 13];

void bfs (int v)
{
    queue <int> q;
    q.push(v);
    forn(i, n + 1)
        d[i] = INF;
    d[v] = 0;
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        
        forn(i, l)
            for (int dx = -1; dx <= 1; dx += 2)
            {
                int next = v + dx * leng[i];
            
                if (next >= 0 && next <= n && d[next] > d[v] + 1)
                {
                    d[next] = d[v] + 1;
                    q.push(next);
                }
            }
    }
}

int bit[30];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 30)
        bit[i] = (1 << i);
    
    cin >> n >> k >> l;
    
    forn(i, k)
    {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    
    forn(i, l)
        scanf("%d", &leng[i]);
    
    forn(i, n + 1)
        if (a[i] != a[i + 1])
            b[szb++] = i;
            
    forn(i, szb)
    {
        bfs(b[i]);
        forn(j, szb)
            dist[i][j] = d[b[j]];
    }
    
    forn(i, bit[szb])
        z[i] = INF;
    
    z[bit[szb] - 1] = 0;
    
    for (int mask = bit[szb] - 1; mask > 0; mask--)
    {
        int f = -1;
        forn(i, szb)
            if (mask & bit[i])
            {
                if (f == -1)
                    f = i;
                else
                {
                    int nmask = mask ^ bit[i] ^ bit[f];
                    z[nmask] = min(z[nmask], z[mask] + dist[i][f]);
                }
            }
    }
    
    if (z[0] > INF / 2)
        z[0] = -1;
        
    cout << z[0] << endl;

    return 0;
}