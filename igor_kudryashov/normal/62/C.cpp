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
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const int INF = 1000 * 1000 * 1000;

const ld EPS = 1e-9;

struct pt
{
    ld x, y;
    
    pt (ld x = 0.0, ld y = 0.0) : x(x), y(y) {}
};

struct seg
{
    pt a, b;
    int idx;
    
    seg (pt a, pt b, int idx = -1) : a(a), b(b), idx(idx) {}
};

inline bool goodBox (const pt& a, const seg& s)
{
    if (a.x + EPS < min(s.a.x, s.b.x) || a.x > max(s.a.x, s.b.x) + EPS)
        return false;
        
    if (a.y + EPS < min(s.a.y, s.b.y) || a.y > max(s.a.y, s.b.y) + EPS)
        return false;
        
    return true;
}

inline ld det (const ld& ax, const ld& ay, const ld& bx, const ld& by)
{
    return ax * by - ay * bx;
}

inline bool intersect (const seg& s1, const seg& s2, pt& p)
{
    ld A1 = s1.b.y - s1.a.y, B1 = s1.a.x - s1.b.x, C1 = -(A1 * s1.a.x + B1 * s1.a.y);
    ld A2 = s2.b.y - s2.a.y, B2 = s2.a.x - s2.b.x, C2 = -(A2 * s2.a.x + B2 * s2.a.y);
    
    ld d = det(A1, B1, A2, B2);
    
    if (abs(d) < EPS)
        return false;
        
    ld x = det(-C1, B1, -C2, B2) / d;
    ld y = det(A1, -C1, A2, -C2) / d;
    
    p = pt(x, y);
    
    if (!goodBox(p, s1) || !goodBox(p, s2))
        return false;
        
    return true;
}

inline ld dist (const pt& a, const pt& b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline ld leng (const seg& s)
{
    return dist(s.a, s.b);
}

inline bool cmpLess (const ld& a, const ld& b)
{
    return a + EPS < b;
}

inline bool cmpEq (const ld& a, const ld& b)
{   
    return abs(a - b) < EPS;
}

inline bool cmpY (const seg& s1, const seg& s2)
{
    ld mid1 = (s1.a.y + s1.b.y) / 2.0;
    ld mid2 = (s2.a.y + s2.b.y) / 2.0;
    
    return mid1 + EPS < mid2;
}

inline bool cmpYs (const pair <ld, int>& a, const pair <ld, int>& b)
{
    return a.ft + EPS < b.ft;
}

const int N = 300 + 13;

int n;
vector <ld> xs;
vector <seg> s;
int opened[N];

int main()
{
    
    cin >> n;
    
    ld alp = 1.23478362834823;
    ld cosa = cos(alp);
    ld sina = sin(alp);
    
    forn(i, n)
    {
        pt p[3];
        
        forn(j, 3)
        {
            int ax, ay;
            scanf("%d%d", &ax, &ay);
            
            p[j] = pt(ax, ay);
            
            p[j] = pt(p[j].x * cosa + p[j].y * sina, -p[j].x * sina + p[j].y * cosa);
        }
            
        forn(j, 3)
            s.pb(seg(p[j], p[(j + 1) % 3], i));
    }

    forn(i, sz(s))
    {
        xs.pb(s[i].a.x);
        xs.pb(s[i].b.x);
    
        forn(j, i)
        {
            pt p;
            
            if (!intersect(s[j], s[i], p))
                continue;
                
            xs.pb(p.x);
        }
    }
    
    sort(all(xs), cmpLess);
    xs.erase(unique(all(xs), cmpEq), xs.end());
    
    ld ans = 0.0;
    
    forn(i, sz(xs) - 1)
    {
        ld x1 = xs[i], x2 = xs[i + 1];
        
        seg s1 = seg(pt(x1, -1e6), pt(x1, 1e6));
        seg s2 = seg(pt(x2, -1e6), pt(x2, 1e6));
        
        vector <seg> ys;
        
        forn(j, sz(s))
        {
            seg& cur = s[j];
            
            if (max(cur.a.x, cur.b.x) < x1 + EPS || min(cur.a.x, cur.b.x) + EPS > x2)
                continue;
                
            pt p1, p2;
            
            assert(intersect(s1, cur, p1));
            assert(intersect(s2, cur, p2));
            
            ys.pb(seg(p1, p2, s[j].idx));
        }
        
        sort(all(ys), cmpY);
        
        int cntOp = 0;
        
        forn(j, sz(ys))
        {
            int idx = ys[j].idx;
            
            if (opened[idx])
            {
                cntOp--;
                
                assert(cntOp >= 0);
                
                if (cntOp == 0)
                    ans += leng(ys[j]);
            
            } else
            {
                assert(cntOp >= 0);
                
                if (cntOp == 0)
                    ans += leng(ys[j]);
                    
                cntOp++;
            }
            
            opened[idx] = 1 - opened[idx];
        }
        
        forn(j, n)
            assert(!opened[j]);
    }
    
    cout << setprecision(10) << fixed;
    
    cout << ans << endl;

    return 0;
}