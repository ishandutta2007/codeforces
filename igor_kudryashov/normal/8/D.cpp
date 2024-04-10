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
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;
const int INF = 1000 * 1000 * 1000;

struct pt
{
    ld x, y;
    pt (ld x, ld y) : x(x), y(y) {}
    pt () {}
};

typedef pair <pt, ld> circle;

inline ld dist (const pt& a, const pt& b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
inline pt operator + (const pt& a, const pt& b) { return pt(a.x + b.x, a.y + b.y); }
inline pt operator - (const pt& a, const pt& b) { return pt(a.x - b.x, a.y - b.y); }
inline pt operator * (const pt& a, const ld& b) { return pt(a.x * b, a.y * b); }
inline pt norm (const pt& v) { ld l = sqrt(sqr(v.x) + sqr(v.y)); return l < EPS ? v : pt(v.x / l, v.y / l); }

ld t1, t2, T1, T2;
pt cinema, home, shop;

inline void intersect (const circle& a, const circle& b, vector <pt>& v)
{
    if (dist(a.ft, b.ft) > a.sc + b.sc + EPS) return;
    if (dist(a.ft, b.ft) + a.sc <= b.sc + EPS) return void(v.pb(a.ft));
    if (dist(a.ft, b.ft) + b.sc <= a.sc + EPS) return void(v.pb(b.ft));
    
    ld d = dist(a.ft, b.ft);
    ld cosa = (sqr(a.sc) + sqr(d) - sqr(b.sc)) / (2.0 * a.sc * d);
    ld sina = sqrt(max(ld(0), 1.0 - sqr(cosa)));
    
    pt vec = norm(b.ft - a.ft) * a.sc;
    
    forn(iter, 2)
    {
        v.pb(a.ft + pt(vec.x * cosa - vec.y * sina, vec.x * sina + vec.y * cosa));
        sina *= -1;
    }
}

inline bool inside (const circle& c, const pt& p) { return dist(p, c.ft) <= c.sc + EPS; }

inline bool can (const ld& r)
{
    vector <circle> circles;
    circles.pb(mp(cinema, r));
    circles.pb(mp(shop, T1 - dist(shop, home) - r));
    circles.pb(mp(home, T2 - r));
    
    //cerr << circles[1].sc << ' ' << circles[2].sc << endl;
    
    forn(i, sz(circles))
        forn(j, i)
        {
            vector <pt> points;
            intersect(circles[i], circles[j], points);
            
            /*cerr << i << ' ' << j << ' ';
            forn(k, sz(points))
                cerr << "(" << points[k].x << "," << points[k].y << ") ";
            cerr << endl;*/
            
            forn(k, sz(circles))
                if (k != i && k != j)
                    forn(it, sz(points))
                        if (inside(circles[k], points[it]))
                            return true;
        }
        
    return false;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> t1 >> t2;
    cin >> cinema.x >> cinema.y;
    cin >> home.x >> home.y;
    cin >> shop.x >> shop.y;
    
    T1 = dist(cinema, shop) + dist(shop, home) + t1;
    T2 = dist(cinema, home) + t2;
    
    if (T2 + EPS >= dist(cinema, shop) + dist(shop, home))
    {
        cout << setprecision(10) << fixed;
        cout << min(T1, T2) << endl;
        return 0;
    }
    
    ld lf = 0.0, rg = min(T1 - dist(shop, home), T2);
    
    forn(iter, 3000)
    {
        ld mid = (lf + rg) / 2.0;
        if (can(mid))
            lf = mid;
        else
            rg = mid;
    }
    
    cout << setprecision(10) << fixed;
    cout << lf << endl;

    return 0;
}