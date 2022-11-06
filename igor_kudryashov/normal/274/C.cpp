#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

struct pt
{
    ld x, y;
    pt (ld x, ld y) : x(x), y(y) {}
    pt () {}
};

inline pt operator - (const pt& a, const pt& b) { return pt(a.x - b.x, a.y - b.y); }
inline pt operator + (const pt& a, const pt& b) { return pt(a.x + b.x, a.y + b.y); }
inline pt operator * (const pt& a, const ld& b) { return pt(a.x * b, a.y * b); }

inline pt ort (const pt& v) { return pt(-v.y, v.x); }

inline ld nextLd ()
{
    int tmp;
    assert(scanf("%d", &tmp) == 1);
    return ld(tmp);
}

const int N = 1000 + 13;

int n;
pt p[N];
pti a[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {
        assert(scanf("%d%d", &a[i].x, &a[i].y) == 2);
        p[i] = pt(a[i].x, a[i].y);
    }
    
    return true;
}

inline ld det (const ld& a, const ld& b, const ld& c, const ld& d) { return a * d - b * c; }

inline bool intersect (const pt& a, const pt& b, const pt& c, const pt& d, pt& p)
{
    ld A1 = b.y - a.y, B1 = a.x - b.x, C1 = -(A1 * a.x + B1 * a.y);
    ld A2 = d.y - c.y, B2 = c.x - d.x, C2 = -(A2 * c.x + B2 * c.y);
    
    ld Det = det(A1, B1, A2, B2);
    
    if (abs(Det) < EPS) return false;
    
    p.x = det(-C1, B1, -C2, B2) / Det;
    p.y = det(A1, -C1, A2, -C2) / Det;
    
    return true;
}

inline pt getCen (const pt& a, const pt& b, const pt& c)
{
    pt ab = (a + b) * 0.5;
    pt bc = (b + c) * 0.5;
    pt vab = ort(a - ab), vbc = ort(b - bc);
    pt p;
    assert(intersect(ab, ab + vab, bc, bc + vbc, p));
    return p;
}

inline ld dist (const pt& a, const pt& b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
inline int dist2 (const pti& a, const pti& b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }

ld angs[N];
int szangs;

inline ld angle (const pt& v)
{
    ld res = atan2(v.y, v.x);
    if (res < -EPS) res += 2.0 * PI;
    return res;
}

inline bool check (const pt& a, const ld& d)
{
    szangs = 0;
    
    forn(i, n)
        if (abs(dist(a, p[i]) - d) < EPS)
            angs[szangs++] = angle(p[i] - a);
            
    sort(angs, angs + szangs);
    angs[szangs] = angs[0] + 2.0 * PI;
    
    forn(i, szangs)
        if ((angs[i + 1] - angs[i]) + EPS >= PI)
            return false;
            
    return true;
}

inline bool haveLess (const pt& c, const ld& d)
{
    forn(i, n)
        if (dist(c, p[i]) + EPS < d)
            return true;
            
    return false;
}

inline pti operator - (const pti& a, const pti& b) { return mp(a.x - b.x, a.y - b.y); }

inline li cross (const pti& a, const pti& b) { return a.x * 1LL * b.y - a.y * 1LL * b.x; }

inline void solve()
{
    ld ans = 0.0;
    
    forn(i, n)
        forn(j, i)
            forn(k, j)
            {
                if (cross(a[j] - a[i], a[k] - a[i]) == 0) continue;
                
                pt c = getCen(p[i], p[j], p[k]);
                ld dd = dist(p[i], c);
                
                if (haveLess(c, dd)) continue;
                
                if (check(c, dd))
                    ans = max(ans, dd);
            }
            
    if (ans < EPS)
    {
        puts("-1");
        return;
    }
            
    cout << setprecision(10) << fixed;
    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}