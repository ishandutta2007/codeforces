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

const int N = 100 * 1000 + 13;

set <pt> q;
int a[N];
int n;

int exactly (int lf, int rg, pt q)
{
    int numer = q.ft, denom = q.sc;
    
    if (a[lf] * numer % denom != 0)
        return false;
    
    int must = a[lf] * numer / denom;
    
    for (int i = lf + 1; i <= rg; i++)
    {
        if (a[i] != must)
            return false;
            
        must = a[i] * numer / denom;
    }
    
    return true;
}

int can (const pt& q)
{
    if (exactly(0, n - 1, q))
        return 0;
        
    if (exactly(1, n - 1, q))
        return 1;

    int numer = q.ft, denom = q.sc;

    if (a[0] * numer % denom != 0)
        return 2;
    
    int cnt = 0;
    int must = a[0] * numer / denom;
    
    for1(i, n - 1)
    {
        if (a[i] != must)
            cnt++;
        else
        {
            if (a[i] * numer % denom != 0 && i != n - 1)
                return 2;

            must = a[i] * numer / denom;
        }
    }
    
    if (cnt == 1)
        return 1;
        
    return 2;
}

int gcd (int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int solve ()
{
    vector <pt> qs = vector <pt> (q.begin(), q.end());
    
    if (qs.empty())
        return a[n - 1] != 0;
        
    if (sz(qs) > 10)
        return 2;
        
    int ans = 2;
        
    forn(i, sz(qs))
    {
        int what = can(qs[i]);
        
        ans = min(ans, what);
    }

    return ans;
}

int main()
{
    
    cin >> n;
    
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    forn(i, n)
        scanf("%d", &a[i]);

    /*  
    if (n == 2 && a[0] == 0 && a[1] != 0)
    {
        cout << 1 << endl;
        return 0;
    }
    */
        
    for1(i, n - 1)
    {
        int numer = a[i], denom = a[i - 1];
        
        if (denom == 0)
            continue;
            
        if (numer == 0)
        {
            q.insert(mp(0, 1));
            continue;
        }
            
        if (denom < 0)
            numer *= -1, denom *= -1;

        int g = gcd(abs(numer), denom);
        
        numer /= g, denom /= g;
        
        q.insert(mp(numer, denom));
    }
    
    cout << solve() << endl;    

    return 0;
}