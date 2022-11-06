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
const int INF = 1000 * 1000 * 1000;

li up (li d, li k)
{
    if (d >= 0)
        return (d / k + 1) * k;
        
    return (d / k) * k;
}

li down (li d, li k)
{
    if (d >= 0)
        return (d / k) * k;
        
    return (d / k - 1) * k;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    li a, b, x1, y1, x2, y2;
    
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    a *= 2, b *= 2;
    
    li d1 = x1 + y1, d2 = x2 + y2;
    li dd1 = x1 - y1, dd2 = x2 - y2;
    
    if (d1 > d2)
        swap(d1, d2);
    if (dd1 > dd2)
        swap(dd1, dd2);
        
    li dlf = up(d1, a), drg = down(d2, a);
    li ddlf = up(dd1, b), ddrg = down(dd2, b);
    
    assert((drg - dlf) % a == 0 && (ddrg - ddlf) % b == 0);
    
    li dcnt = (drg >= dlf ? (drg - dlf) / a + 1 : 0);
    li ddcnt = (ddrg >= ddlf ? (ddrg - ddlf) / b + 1 : 0);
    
    cout << max(dcnt, ddcnt) << endl;

    return 0;
}