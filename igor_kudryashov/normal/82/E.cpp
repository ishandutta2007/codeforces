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
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

struct pt
{
    ld x, y;
    
    pt (ld x = 0.0, ld y = 0.0) : x(x), y(y) {}
};

const int N = 500 + 13;

int n, h, f;
int lf[N], rg[N];
pt focus, mfocus;
pt lftop, rgtop, lfbot, rgbot;

inline ld det (const ld& ax, const ld& ay, const ld& bx, const ld& by)
{
    return ax * by - ay * bx;
}

inline bool between (const pt& c, const pt& a, const pt& b)
{
    if (c.x + EPS < min(a.x, b.x) || c.x > max(a.x, b.x) + EPS) 
        return false;

    if (c.y + EPS < min(a.y, b.y) || c.y > max(a.y, b.y) + EPS) 
        return false;
        
    return true;
}

inline bool intersect (const pt& a, const pt& b, const pt& c, const pt& d, pt& p, bool segm)
{
    ld A1 = b.y - a.y, B1 = a.x - b.x, C1 = -(a.x * A1 + a.y * B1);
    ld A2 = d.y - c.y, B2 = c.x - d.x, C2 = -(c.x * A2 + c.y * B2);
    
    ld Det = det(A1, B1, A2, B2);
    
    if (abs(Det) < EPS)
        return false;
        
    p.x = det(-C1, B1, -C2, B2) / Det;
    p.y = det(A1, -C1, A2, -C2) / Det;
    
    if (segm)
        return between(p, a, b) && between(p, c, d);
        
    return true;        
}

inline ld square (const vector <pt>& pol)
{
    ld res = 0.0;
    
    forn(i, sz(pol))
    {
        int nexti = (i + 1 == sz(pol) ? 0 : i + 1);
        
        res += (pol[nexti].x - pol[i].x) * (pol[nexti].y + pol[i].y);
    }
    
    return abs(res) * 0.5;
}

inline int sign (const ld& c)
{
    return c > EPS ? 1 : c < -EPS ? -1 : 0;
}

void cut (vector <pt>& pol, pt a, pt b, const pt& c)
{
    if (sz(pol) < 3)
        return;
    
    ld A = b.y - a.y, B = a.x - b.x, C = -(a.x * A + a.y * B);
    int s = sign(A * c.x + B * c.y + C);
    
    pt v = pt((b.x - a.x) * 1e6, (b.y - a.y) * 1e6);
    a = pt(a.x - v.x, a.y - v.y);
    b = pt(b.x + v.x, b.y + v.y);
    
    vector <pt> ans;

    forn(i, sz(pol))
    {
        int nexti = (i + 1 == sz(pol) ? 0 : i + 1);
        
        int s1 = sign(A * pol[i].x + B * pol[i].y + C) * s;
        int s2 = sign(A * pol[nexti].x + B * pol[nexti].y + C) * s;
        
        if ((s1 < 0 && s2 < 0) || (s1 == 0 && s2 < 0))
            continue;
        
        if (s1 * s2 < 0)
        {
            pt p;
            assert(intersect(pol[i], pol[nexti], a, b, p, true));
            ans.pb(p);
            
            if (s2 > 0)
                ans.pb(pol[nexti]);
                
            continue;
        }
        
        ans.pb(pol[nexti]);
    }
    
    pol = ans;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> h >> f;
    focus = pt(0.0, f);
    mfocus = pt(0.0, -f);
    lftop = pt(-1e7, h);
    rgtop = pt(1e7, h);
    lfbot = pt(-1e7, -h);
    rgbot = pt(1e7, -h);
    
    forn(i, n)
        scanf("%d%d", &lf[i], &rg[i]);

    ld S = 0.0;
        
    forn(i, n)
    {
        vector <pt> pol;
        pt plf = pt(lf[i], h), prg = pt(rg[i], h);
        
        pt cur;
        assert(intersect(focus, plf, lftop, rgtop, cur, false));
        pol.pb(cur);
        assert(intersect(focus, plf, lfbot, rgbot, cur, false));
        pol.pb(cur);
        assert(intersect(focus, prg, lfbot, rgbot, cur, false));
        pol.pb(cur);
        assert(intersect(focus, prg, lftop, rgtop, cur, false));
        pol.pb(cur);
        
        ld spol = square(pol);
        S += 2.0 * spol;
        
        forn(j, n)
        {
            pt nplf = pt(lf[j], -h), nprg = pt(rg[j], -h);
            vector <pt> npol = pol;
            
            cut(npol, mfocus, nplf, nprg);
            cut(npol, mfocus, nprg, nplf);
            
            ld s = square(npol);
            
            if (s + EPS < spol)
                S -= s;
        }
    }
    
    cout << setprecision(10) << fixed;
    
    cout << S << endl;

    return 0;
}