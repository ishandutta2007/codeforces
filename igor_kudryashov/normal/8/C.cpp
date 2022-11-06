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

const int N = 25;

int n;
int stx, sty;
pt a[N];
int dist[N][N];
int d[(1 << 24) + 13];
int p[(1 << 24) + 13];
int pos[(1 << 24) + 13];
int bit[30];

int dist2 (const pt& a, const pt& b)
{
    return sqr(a.ft - b.ft) + sqr(a.sc - b.sc);
}

int main()
{
    
    forn(i, 30)
        bit[i] = (1 << i);
    
    cin >> stx >> sty >> n;
    
    forn(i, n)
        cin >> a[i].ft >> a[i].sc;
        
    a[n] = mp(stx, sty);
        
    forn(i, n + 1)
        forn(j, n + 1)
            dist[i][j] = dist2(a[i], a[j]);

    forn(i, n)
        pos[(1 << i)] = i;
        
    memset(d, 63, sizeof(d));
    d[0] = 0;
        
    for1(mask, bit[n] - 1)
    {
        int pmask = (mask & (mask - 1));
        int last = pos[mask ^ pmask];
        
        if (d[mask] > d[pmask] + dist[n][last] + dist[last][n])
        {
            d[mask] = d[pmask] + dist[n][last] + dist[last][n];
            p[mask] = pmask;
        }
        
        forn(i, n)
            if (pmask & bit[i])
            {
                int prevmask = pmask ^ bit[i];
                int cur = d[prevmask] + dist[n][last] + dist[last][i] + dist[i][n];
                
                if (d[mask] > cur)
                {
                    d[mask] = cur;
                    p[mask] = prevmask;
                }
            }
    }
    
    vector <int> ans;
    
    for (int i = bit[n] - 1; i != 0; i = p[i])
        ans.pb(i);
    ans.pb(0);  
    
    reverse(all(ans));
    
    cout << d[bit[n] - 1] << endl;
    
    forn(i, sz(ans) - 1)
    {
        printf("0 ");
        
        int mask = ans[i] ^ ans[i + 1];
        
        forn(j, n)
            if (mask & bit[j])
                printf("%d ", j + 1);
    }
    
    puts("0");
        
    return 0;
}