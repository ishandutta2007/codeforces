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

const int N = 1000 + 13;

int n, k;
ld p[N];
ld z[N][N];
li deg10[20];

inline int leng (li n)
{
    if (n == 0)
        return 1;
        
    int res = 0;
    
    while (n > 0)
        res++, n /= 10;
        
    return res;
}

inline int fir (li n)
{
    while (n >= 10)
        n /= 10;
        
    return int(n % 10);
}

li getOnes (li lf, li rg)
{
    int lenlf = leng(lf) - 1, lenrg = leng(rg) - 1;
    
    if (lenlf == lenrg)
    {
        if (fir(lf) > 1)
            return 0;
            
        rg = min(rg, deg10[lenrg] * 2 - 1);
        
        return rg - lf + 1;
    }
    
    assert(lenlf < lenrg);
    
    li ans = 0;
    
    if (fir(lf) == 1)
        ans += (deg10[lenlf] * 2 - 1) - lf + 1;
        
    {
        li curlf = deg10[lenrg];
        li currg = min(deg10[lenrg] * 2 - 1, rg);
        
        ans += currg - curlf + 1;
    }
    
    for (int i = lenlf + 1; i < lenrg; i++)
        ans += deg10[i];
        
    return ans;
}

int main()
{
    deg10[0] = 1LL;
    for1(i, 18)
        deg10[i] = deg10[i - 1] * 10LL;

    cin >> n;
    
    forn(i, n)
    {
        li lf, rg;
        cin >> lf >> rg;
        
        li t = getOnes(lf, rg);
        
        p[i] = t * 1.0 / (rg - lf + 1);
    }
    
    cin >> k;
    k = (k * n / 100) + (k * n % 100 != 0);
    
    assert(k <= n);
    
    z[0][0] = 1.0;
    
    forn(i, n)
        forn(j, i + 1)
        {
            z[i + 1][j] += z[i][j] * (1.0 - p[i]);
            z[i + 1][j + 1] += z[i][j] * p[i];
        }
        
    ld ans = 0.0;
    
    for (int i = k; i <= n; i++)
        ans += z[n][i];
        
    cout << setprecision(10) << fixed;
    
    cout << ans << endl;

    return 0;
}