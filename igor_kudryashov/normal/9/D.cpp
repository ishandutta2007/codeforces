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

int n, h;
li z[N][N];

li solve (int n, int h)
{
    li& res = z[n][h];
    
    if (res != -1)
        return res;
        
    if (h > n)
        return res = 0;
        
    if (h == 0)
        return res = n == 0;

    if (n == 1)
        return res = h == 1;

    if (n == 0)
        return res = h == 0;
        
    res = 0;
        
    for (int k = 0; k <= n - 1; k++)
    {
        forn(i, h - 1)
            res += solve(k, h - 1) * solve(n - 1 - k, i) + solve(k, i) * solve(n - 1 - k, h - 1);
            
        res += solve(k, h - 1) * solve(n - 1 - k, h - 1);
    }
    
    return res;
}

int main()
{
    
    cin >> n >> h;
    
    memset(z, -1, sizeof(z));
    
    li ans = 0;
    
    for (int i = h; i <= n; i++)
        ans += solve(n, i);
    
    cout << ans << endl;

    return 0;
}