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
const li INF64 = li(1e18);

const int N = 1500 + 13;

int n, m;
int a[N][N];
li z[N][N];
int sum[N][N];

int main()
{
    
    cin >> n >> m;
    
    forn(i, n)
    {
        forn(j, m)
            scanf("%d", &a[i][j]);
            
        sum[i][0] = a[i][0];
        
        for1(j, m - 1)
            sum[i][j] = sum[i][j - 1] + a[i][j];
    }
    
    forn(j, m)
        z[0][j] = sum[0][j], z[n - 1][j] = -INF64;
        
    for1(i, n - 1)
    {
        li curmax = -INF64;
        
        if (i & 1)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                curmax = max(curmax, z[i - 1][j + 1]);
                
                z[i][j] = curmax + sum[i][j];
            }
        } else
        {
            for (int j = 1; j < m; j++)
            {
                curmax = max(curmax, z[i - 1][j - 1]);
                
                z[i][j] = curmax + sum[i][j];
            }
        }
    }
    
    li ans = -INF64;
    
    forn(j, m)
        ans = max(ans, z[n - 1][j]);
        
    cout << ans << endl;    

    return 0;
}