#pragma comment(linker, "/stack:64000000")
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


li gcd (li a, li b)
{
    return a == 0 ? b : gcd(b % a, a);
}

li lcm (li a, li b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    
    li a, b, c, d, e, f;
    
    cin >> a >> b >> c >> d >> e >> f;
    
    if (d == 0)
    {
        puts("Hermione");
        return 0;
    }
    
    if (c == 0)
    {
        puts("Ron");
        return 0;
    }
    
    if (b == 0)
    {
        puts("Hermione");
        return 0;
    }
    
    if (a == 0)
    {
        puts("Ron");
        return 0;
    }
    
    if (f == 0)
    {
        puts("Hermione");
        return 0;
    }
    
    if (e == 0)
    {
        puts("Ron");
        return 0;
    }
    
    li g1 = lcm(b, c) / c;
    li g2 = lcm(d, e) / d;
    
    li g = lcm(g1, g2);
    
    li Sw = c * g, Gold = d * g;
    li needP = Sw / b * a;
    li resP = Gold / e * f;
    
    if (needP >= resP)
        puts("Hermione");
    else
        puts("Ron");

    return 0;
}