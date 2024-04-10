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
typedef pair<ld, ld> pt;
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-5;
const int INF = 1000 * 1000 * 1000;

ld ax, ay, bx, by, cx, cy;

int getCnt (int i, int j, int n)
{
    if (i > j)
        swap(i, j);
        
    return min(j - i, i + n - j);
}

inline pt operator * (const pt& v, const ld& a)
{
    return mp(v.ft * a, v.sc * a);
}

inline pt operator + (const pt& a, const pt& b)
{
    return mp(a.ft + b.ft, a.sc + b.sc);
}

inline pt operator - (const pt& a, const pt& b)
{
    return mp(a.ft - b.ft, a.sc - b.sc);
}

inline ld dist (ld ax, ld ay, ld bx, ld by)
{
    return sqrt(sqr(ax - bx) + sqr(ay - by));
}

inline ld leng (const pt& v)
{
    return sqrt(sqr(v.ft) + sqr(v.sc));
}

inline pt norm (const pt& v)
{
    assert(leng(v) > EPS);
    
    return v * (1.0 / leng(v));
}

inline pt turn (const pt& v, const ld& phi)
{
    return mp(v.ft * cos(phi) + v.sc * sin(phi), -v.ft * sin(phi) + v.sc * cos(phi));
}

inline ld getAng (const pt& a, const pt& c)
{   
    return abs(atan2(a.sc, a.ft) - atan2(c.sc, c.ft));
}

inline bool vertOfPol (const pt o, const ld r, const int n)
{
    if (abs(dist(o.ft, o.sc, cx, cy) - r) > EPS)
        return false;
        
    ld phi = 2.0 * PI / n;
    
    ld ang = getAng(mp(ax, ay) - o, mp(cx, cy) - o);

    ld d = ang / phi;
    
    int dd = int(d + 0.5);
    
    if (abs(d - dd) > EPS)
        return false;
        
    return true;
}

int main()
{
    
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    cout << setprecision(10) << fixed;
    
    ld ans = 1e18;
    
    ld d = dist(ax, ay, bx, by);
    int ansn = -1;
    
    for (int n = 3; n <= 100; n++)
    {
        forn(i, n)
            forn(j, n)
            {
                if (i == j)
                    continue;
                    
                ld phi = (2.0 * PI / n) * 1.0 * getCnt(i, j, n);
                
                ld alp = (PI - phi) / 2.0;
                
                ld r = sqrt(sqr(d) / (2.0 * (1.0 - cos(phi))));
                
                pt v = norm(mp(bx - ax, by - ay)) * r;
                
                pt o1 = mp(ax, ay) + turn(v, alp);
                pt o2 = mp(ax, ay) + turn(v, -alp);
                
                if (vertOfPol(o1, r, n) || vertOfPol(o2, r, n))
                {
                    ld s = sqr(r) * 0.5 * abs(sin(2.0 * PI / n)) * n;
                
                    if (ans > s + 1e-6)
                    {
                        ans = s;
                        ansn = n;
                    }
                }
            }
    }
    
    cout << ans << endl;
    
    return 0;
}