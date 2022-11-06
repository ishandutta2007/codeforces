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

const int N = 10 * 1000 + 13;
const ld EPS = 1e-7;

struct pt
{
    ld x, y, z;
    
    pt (ld x = 0.0, ld y = 0.0, ld z = 0.0) : x(x), y(y), z(z) {}
};

inline bool operator == (const pt& a, const pt& b)
{
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS && abs(a.z - b.z) < EPS;
}

inline pt operator - (const pt& a, const pt& b)
{
    return pt(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline pt operator + (const pt& a, const pt& b)
{
    return pt(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline pt operator * (const pt& a, const ld& c)
{
    return pt(a.x * c, a.y * c, a.z * c);
}

inline ld dist (const pt& a, const pt& b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}

inline ld leng (const pt& v)
{
    return sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z));
}

inline pt norm (const pt& v)
{
    ld len = leng(v);

    return pt(v.x / len, v.y / len, v.z / len);
}

int n;
pt p[N];
ld vp, vs;
pt init;

ld f (int idx, pt curp, ld curt)
{
    if (curp == init)
        return 0.0;

    ld t = curt + dist(curp, p[idx]) / vs;
    
    pt v = curp - init;
    
    ld s = t * vp;

    pt nextp = init + norm(v) * s;
    
    return dist(nextp, curp);
}

inline bool can (int idx, ld curt, pt& ans)
{
    pt v = p[idx + 1] - p[idx];
    
    ld lf = 0.0, rg = 1.0;
    
    forn(i, 300)
    {
        ld lfmid = lf + (rg - lf) / 3.0;
        ld rgmid = rg - (rg - lf) / 3.0;
        
        pt plf = p[idx] + v * lfmid;
        pt prg = p[idx] + v * rgmid;
        
        if (f(idx, plf, curt) + 1e-9 < f(idx, prg, curt))
            rg = rgmid;
        else
            lf = lfmid;
    }
    
    pt curp = p[idx] + v * ((lf + rg) / 2.0);
    
    if (f(idx, curp, curt) < 1e-6)
    {
        ans = p[idx] + v * ((lf + rg) / 2.0);
        
        return true;
    }
    
    return false;
}

int main()
{
    
    cin >> n;
    n++;
    
    forn(i, n)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        
        p[i] = pt(x, y, z);
    }
    
    cin >> vp >> vs;
    
    cin >> init.x >> init.y >> init.z;
    
    ld curt = 0.0;
    
    forn(i, n - 1)
    {
        if (i > 0)
            curt += dist(p[i - 1], p[i]) / vs;
            
        pt ans;
        
        if (can(i, curt, ans))
        {
//          assert((curt + dist(ans, p[i]) / vs - dist(ans, init) / vp) < 1e-6);
        
            cout << "YES" << endl;
            
            cout << setprecision(10) << fixed;
            
            cout << dist(ans, init) / vp << endl;
            
            cout << ans.x << ' ' << ans.y << ' ' << ans.z << endl;
            
            return 0;
        }
    }
    
    cout << "NO" << endl;

    return 0;
}