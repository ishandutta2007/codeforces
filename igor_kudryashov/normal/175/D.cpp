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

typedef double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 3500 + 3;
const int H = 200 + 3;

int h1, dt1, lf1, rg1, h2, dt2, lf2, rg2;
ld p1, p2;
ld dv[N][H], de[N][H];

void calc (int h, int lf, int rg, ld p, ld d[N][H])
{
    d[0][h] = 1.0;
    ld coef = (1.0 - p) / ld(rg - lf + 1);
    
    forn(i, N - 1)
        forn(j, h + 1)
        {
            ld& dv = d[i][j];
            if (abs(dv) < EPS) continue;
            
            d[i + 1][j] += dv * p;
            
            for (int dam = lf; dam <= rg; dam++)
                d[i + 1][max(j - dam, 0)] += dv * coef;
        }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> h1 >> dt1 >> lf1 >> rg1 >> p1;
    cin >> h2 >> dt2 >> lf2 >> rg2 >> p2;
    
    p1 /= 100.0;
    p2 /= 100.0;
    
    if (abs(p1 - 1.0) < EPS)
    {
        cout << setprecision(10) << fixed;
        cout << ld(0) << endl;
        return 0;
    }   
    
    if (abs(p2 - 1.0) < EPS)
    {
        cout << setprecision(10) << fixed;
        cout << ld(1) << endl;
        return 0;
    }
    
    calc(h1, lf2, rg2, p2, dv);
    calc(h2, lf1, rg1, p1, de);
    
    ld ans = 0.0;
    
    for1(k, N - 1)
    {
        int secSteps = dt1 * (k - 1) / dt2 + 1;
        if ((dt1 * (k - 1)) % dt2 == 0) secSteps--;
        
        if (secSteps < N)
            ans += (1.0 - dv[secSteps][0]) * (de[k][0] - de[k - 1][0]);
    }
    
    cout << setprecision(10) << fixed;
    cout << ans << endl;

    return 0;
}