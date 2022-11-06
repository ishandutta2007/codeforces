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

const int N = 4 * 10 * 1000 + 13;

inline bool operator < (const ptd& a, const ptd& b)
{
    if (abs(a.ft - b.ft) > EPS)
        return a.ft < b.ft;
        
    return a.sc + EPS < b.sc;
}

inline ptd operator - (const ptd& a, const ptd& b)
{
    return mp(a.ft - b.ft, a.sc - b.sc);
}

inline ptd operator + (const ptd& a, const ptd& b)
{
    return mp(a.ft + b.ft, a.sc + b.sc);
}

inline ptd operator / (const ptd& a, const ld& c)
{
    return mp(a.ft / c, a.sc / c);
}

inline ld cross (const ptd& a, const ptd& b)
{
    return a.ft * b.sc - a.sc * b.ft;
}

inline ld dot (const ptd& a, const ptd& b)
{
    return a.ft * b.ft + a.sc * b.sc;
}

inline bool turnRight (const ptd& a, const ptd& b, const ptd& c)
{
    ptd v1 = b - a, v2 = c - a;
    
    return cross(v1, v2) < -EPS;
}

inline ld len (const ptd& a)
{
    return sqrt(sqr(a.ft) + sqr(a.sc));
}

inline ptd norm (const ptd& v)
{
    ld l = len(v);
    
    assert(abs(l) > EPS);
    
    return mp(v.ft / l, v.sc / l);
}

inline ptd inBasis (const ptd& e1, const ptd& e2, const ptd& p)
{
    return mp(dot(p, e1), dot(p, e2));
}

int n;
ptd p[N];
ld s[N];
ptd cen;

inline ld getS (int i, int j)
{
    if (i == j)
        return 0.0;

    assert(j > 0);

    return s[j - 1] - ((i == 0) ? 0.0 : s[i - 1]);
}

inline ld square (int i, int j, const ptd& t)
{
    ld res = abs(t.ft * t.sc * 0.5);
    
    res += abs(cross(p[i] - cen, p[j] - cen)) * 0.5;
    
    if (i <= j)
        res -= getS(i, j);
    else
        res -= getS(i, n) + getS(0, j);
        
    return abs(res);
}

inline ld calcSquare (vector <ptd> pol)
{
    ld ans = 0.0;
    
    pol.pb(pol[0]);
    
    forn(i, sz(pol) - 1)
        ans += (pol[i + 1].ft - pol[i].ft) * (pol[i + 1].sc + pol[i].sc) * 0.5;
        
    return abs(ans);
}

inline ld det (ld ax, ld ay, ld bx, ld by)
{
    return ax * by - ay * bx;
}

inline ptd intersect (const ptd& a, const ptd& b, const ptd& c)
{
    ld A1 = b.sc - a.sc, B1 = a.ft - b.ft, C1 = -(a.ft * A1 + a.sc * B1);
    ld A2 = B1, B2 = -A1, C2 = -(A2 * c.ft + B2 * c.sc);
    
    ld d = det(A1, B1, A2, B2);
    
    if (abs(d) < EPS)
        return c;
    
    ld x = det(-C1, B1, -C2, B2) / d;
    ld y = det(A1, -C1, A2, -C2) / d;
    
    return mp(x, y);
}

int main()
{
    
    cin >> n;
    
    forn(i, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = mp(x, y);
    }
    
    ld ans = 1e15;
    
    forn(k, 2)
    {
    
    forn(i, n)
        p[i].ft *= -1.0;
    
    if (turnRight(p[0], p[1], p[2]))
        reverse(p, p + n);
        
    cen = mp(0.0, 0.0);
    forn(i, n)
        cen = cen + p[i];
    cen = cen / n;

    s[0] = cross(p[0] - cen, p[1] - cen) * 0.5;
    for1(i, n - 1)
        s[i] = s[i - 1] + cross(p[i] - cen, p[(i + 1) % n] - cen) * 0.5;
        
    ptd e1 = norm(p[1] - p[0]), e2 = mp(-e1.sc, e1.ft);
    
    int idx = 0;
    
    forn(i, n)
        if (inBasis(e1, e2, p[i] - p[0]) < inBasis(e1, e2, p[idx] - p[0]))
            idx = i;

    ans = min(ans, square(idx, 0, inBasis(e1, e2, p[idx] - p[0])));
    
    for1(i, n - 1)
    {
        int nexti = i + 1 == n ? 0 : i + 1;
        
        e1 = norm(p[nexti] - p[i]), e2 = mp(-e1.sc, e1.ft);
        
        while (inBasis(e1, e2, p[(idx + 1) % n] - p[i]) < inBasis(e1, e2, p[idx] - p[i]))
            idx = (idx + 1) % n;
            
        ans = min(ans, square(idx, i, inBasis(e1, e2, p[idx] - p[i])));

/*      
        vector <ptd> v;
        int tmp = idx;
        
        while (tmp != i)
        {
            v.pb(p[tmp]);
            tmp = (tmp + 1) % n;
        }
        v.pb(p[i]);
        
        v.pb(intersect(p[i], p[nexti], p[idx]));
        
        ans = min(ans, calcSquare(v));      
*/
    }
    
    }
    
    cout << setprecision(10) << fixed;
    
    cout << ans << endl;    

    return 0;
}