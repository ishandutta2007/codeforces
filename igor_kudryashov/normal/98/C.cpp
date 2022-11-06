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
const int INF = 1000 * 1000 * 1000;

const ld EPS = 1e-10;

inline ld f (const ld& x, const ld& a, const ld& b, const ld& len)
{
    ld y = sqrt(max(ld(0), sqr(len) - sqr(x)));
    
    ld A = y, B = x, C = -A * x;
    ld l = sqrt(sqr(A) + sqr(B));
    A /= l, B /= l, C /= l;

    return A * a + B * b + C;
}

ld solve (ld a, ld b, ld len)
{
    ld lf = 0.0, rg = len;
    
    forn(i, 10000)
    {
        ld lfmid = lf + (rg - lf) / 3.0;
        ld rgmid = rg - (rg - lf) / 3.0;
        
        if (f(lfmid, a, b, len) + EPS < f(rgmid, a, b, len))
            rg = rgmid;
        else
            lf = lfmid;
    }
    
    return f((lf + rg) / 2.0, a, b, len);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int a, b, l;
    cin >> a >> b >> l;
    
    if (a > b)
        swap(a, b);
        
    if (l <= a)
        printf("%.10lf\n", double(l));
    else if (l <= b)
        printf("%.10lf\n", double(a));
    else
    {
        ld t = solve(a, b, l);
        
        if (t + EPS < 1e-7)
            puts("My poor head =(");
        else
            printf("%.10lf\n", double(t));
    }

    return 0;
}