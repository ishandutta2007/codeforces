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
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-6;
const int INF = 1000 * 1000 * 1000;

struct pt
{
    ld x, y;
    
    pt (ld x = 0.0, ld y = 0.0) : x(x), y(y) {}
};

inline bool operator == (const pt& a, const pt& b)
{
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}

inline bool operator != (const pt& a, const pt& b)
{   
    return !(a == b);
}

inline pt operator * (const pt& a, const ld& c)
{
    return pt(a.x * c, a.y * c);
}

inline pt operator + (const pt& a, const pt& b)
{
    return pt(a.x + b.x, a.y + b.y);
}

inline pt operator - (const pt& a, const pt& b)
{
    return pt(a.x - b.x, a.y - b.y);
}

inline pt normal (const pt& v)
{
    return pt(v.y, -v.x);
}

inline ld leng (const pt& v)
{
    return sqrt(sqr(v.x) + sqr(v.y));
}

inline pt norm (const pt& v)
{
    assert(leng(v) > EPS);
    
    return v * (1.0 / leng(v));
}

inline ld dist (const pt& a, const pt& b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

struct line
{
    ld A, B, C;
    pt a, b;
    
    line (pt a, pt b) : a(a), b(b)
    {
        A = b.y - a.y;
        B = a.x - b.x;
        C = -(A * a.x + B * a.y);
    }
};

struct circle
{
    pt o;
    ld r;
    
    circle (pt o, ld r = 0.0) : o(o), r(r) {}
};

ld rr[3];
pt p[3];

inline line getLine (const pt& a, const pt& b)
{   
    assert(a != b);

    pt mid = (a + b) * 0.5;
    pt v = normal(b - a);
    
    return line(mid, mid + v);
}

inline circle getCircle (pt a, ld ra, pt b, ld rb)
{
    if (ra + EPS < rb)
        swap(a, b), swap(ra, rb);
        
    ld d = dist(a, b);
        
    ld x1 = ra * d / (ra + rb);
    ld x2 = rb * d / (ra - rb);
    
    pt p1 = a + norm(b - a) * x1;
    pt p2 = a + norm(b - a) * (d + x2);
    
    assert(p1 != p2);
    
    pt o = (p1 + p2) * 0.5;
    
    return circle(o, dist(o, p1));
}

inline ld det (const ld& ax, const ld& ay, const ld& bx, const ld& by)
{
    return ax * by - ay * bx;
}

inline void intersect (line L1, line L2, vector <pt>& cand)
{
    ld d = det(L1.A, L1.B, L2.A, L2.B);
    
    if (abs(d) < EPS)
        return;
        
    ld x = det(-L1.C, L1.B, -L2.C, L2.B) / d;
    ld y = det(L1.A, -L1.C, L2.A, -L2.C) / d;
    
    cand.pb(pt(x, y));
}

inline void intersect (line L1, circle C, vector <pt>& cand)
{
    pt sh = C.o;
    
    L1 = line(L1.a - sh, L1.b - sh);
    C = circle(C.o - sh, C.r);
    
    ld d = abs(L1.C) / sqrt(sqr(L1.A) + sqr(L1.B));
    
    if (d - C.r > EPS)
        return;
        
    pt M(-L1.A * L1.C / (sqr(L1.A) + sqr(L1.B)), -L1.B * L1.C / (sqr(L1.A) + sqr(L1.B)));
    
    ld k = sqrt(sqr(C.r) - sqr(d));
    
    pt v = norm(normal(pt(L1.A, L1.B))) * k;
    
    cand.pb(M + v + sh);
    cand.pb(M - v + sh);    
}

inline void intersect (circle C1, circle C2, vector <pt>& cand)
{
    ld d = dist(C1.o, C2.o);
    
    if (d - (C1.r + C2.r) > EPS)
        return;

    ld cosa = (sqr(C2.r) - sqr(C1.r) - sqr(d)) / (-2.0 * C1.r * d);
    ld sina = sqrt(max(ld(0.0), 1.0 - sqr(cosa)));
    
    pt v = norm(C2.o - C1.o);
    
    pt v1(v.x * cosa + v.y * sina, -v.x * sina + v.y * cosa);
    pt v2(v.x * cosa - v.y * sina, v.x * sina + v.y * cosa);
    
    cand.pb(C1.o + v1 * C1.r);
    cand.pb(C1.o + v2 * C1.r);
}

bool check (const pt& a, ld& ang)
{
    forn(i, 3)
        assert(dist(a, p[i]) + EPS > rr[i]);

    ang = 2.0 * asin(rr[0] / dist(a, p[0]));
    
    for1(i, 2)
    {
        ld tang = 2.0 * asin(rr[i] / dist(a, p[i]));
        
        if (abs(ang - tang) > EPS)
            return false;
    }
    
    return true;
}

int main()
{
    
    forn(i, 3)
        cin >> p[i].x >> p[i].y >> rr[i];
        
    vector <pt> cand;
        
    if (abs(rr[0] - rr[1]) < EPS)
    {
        line L1 = getLine(p[0], p[1]);
        
        if (abs(rr[0] - rr[2]) < EPS)
        {
            line L2 = getLine(p[0], p[2]);
            
            intersect(L1, L2, cand);
        
        } else
        {
            circle C = getCircle(p[0], rr[0], p[2], rr[2]);
            
            intersect(L1, C, cand);
        }
    
    } else
    {
        circle C1 = getCircle(p[0], rr[0], p[1], rr[1]);
        
        if (abs(rr[0] - rr[2]) < EPS)
        {   
            line L1 = getLine(p[0], p[2]);
            
            intersect(L1, C1, cand);
        } else
        {
            circle C2 = getCircle(p[0], rr[0], p[2], rr[2]);
            
            intersect(C1, C2, cand);
        }
    }
    
    pt ans;
    ld ansAng = -1e10;
    
    forn(i, sz(cand))
    {
        ld ang = 0.0;
    
        if (check(cand[i], ang))
            if (ang > ansAng + EPS)
                ans = cand[i], ansAng = ang;
    }
    
    cout << setprecision(10) << fixed;
    
    if (ansAng > -EPS)
        cout << ans.x << ' ' << ans.y << endl;  

    return 0;
}