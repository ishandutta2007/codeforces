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

li gcd (li a, li b)
{
    return a == 0 ? b : gcd(b % a, a);
}

li f[2];
li a, b, c;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> a >> b;
    
    c = a / gcd(a, b) * b;
    
    li cura = a, curb = b;
    li last = 0;
    
    while (cura < c || curb < c)
    {   
        if (cura < curb)
        {
            f[0] += cura - last;
            last = cura;
            cura += a;
        } else
        {
            f[1] += curb - last;
            last = curb;
            curb += b;
        }
    }
    
    if (a > b)
        f[0] += c - last;
    else if (b > a)
        f[1] += c - last;
        
    if (f[0] > f[1])
        puts("Dasha");
    else if (f[1] > f[0])
        puts("Masha");
    else
        puts("Equal");

    return 0;
}