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

ld a, v, l, d, w;

int main()
{
    
    cin >> a >> v >> l >> d >> w;
    
    cout << setprecision(10) << fixed;
    
    if (v < w + EPS || sqr(w) / (2.0 * a) + EPS > d)
    {
        ld s = sqr(v) / (2.0 * a);
        
        if (s + EPS > l)
        {
            ld t = sqrt(2.0 * l / a);
            
            cout << t << endl;
        } else
        {
            ld t = sqrt(2.0 * s / a) + (l - s) / v;
            
            cout << t << endl;
        }
    
        return 0;
    }
    
    ld tForDec = (v - w) / a;
    ld sForDec = v * tForDec - a * sqr(tForDec) / 2.0;
    ld sToMaxv = sqr(v) / (2.0 * a);
    
    if (d - sForDec + EPS > sToMaxv)
    {
        ld tToMaxv = sqrt(2.0 * sToMaxv / a);
        ld tToStop = tToMaxv + (d - sForDec - sToMaxv) / v + tForDec;
        
        ld tToMaxv2 = (v - w) / a;
        ld sToMaxv2 = w * tToMaxv2 + a * sqr(tToMaxv2) / 2.0;
        
        ld tAfterStop;
        
        if (l - d + EPS > sToMaxv2)
            tAfterStop = tToMaxv2 + (l - d - sToMaxv2) / v;
        else
        {
            ld D = sqr(2.0 * w) + 8.0 * a * (l - d);
            assert(D + EPS > 0);
        
            tAfterStop = (-2.0 * w + sqrt(max(ld(0.0), D))) / (2.0 * a);
        }
        
        cout << tToStop + tAfterStop << endl;
        
    } else
    {
        ld u = sqrt((2.0 * a * d + sqr(w)) / 2.0);
        
        assert(u + EPS > w);
        
        ld tToU = u / a;
        
        ld tToStop = tToU + (u - w) / a;
        
        ld tToMaxv2 = (v - w) / a;
        ld sToMaxv2 = w * tToMaxv2 + a * sqr(tToMaxv2) / 2.0;
        
        ld tAfterStop;
        
        if (l - d + EPS > sToMaxv2)
            tAfterStop = tToMaxv2 + (l - d - sToMaxv2) / v;
        else
        {
            ld D = sqr(2.0 * w) + 8.0 * a * (l - d);
            assert(D + EPS > 0);
        
            tAfterStop = (-2.0 * w + sqrt(max(ld(0.0), D))) / (2.0 * a);
        }
        
        cout << tToStop + tAfterStop << endl;
    }

    return 0;
}