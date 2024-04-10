#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

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
typedef pair<li, li> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;

int n;
int x[N], c[N];
li d[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n) assert(scanf("%d", &x[i]) == 1);
    
    forn(i, n) assert(scanf("%d", &c[i]) == 1);
    
    return true;
}

vector <pt> L;
vector <pt> xs;

li gcd (li a, li b) { return a == 0 ? b : gcd(b % a, a); }

inline pt intersect (const pt& L1, const pt& L2)
{
    li num = L2.y - L1.y, den = L1.x - L2.x;
    li g = gcd(abs(num), abs(den));
    num /= g, den /= g;
    if (den < 0) den *= -1, num *= -1;
    return mp(num, den);
}

inline bool bad (const pt& L1)
{
    pt p = intersect(L[sz(L) - 2], L1);
    
    if (ld(p.ft) / ld(p.sc) > 2 * INF) return false;
    
    return ld(p.x) / ld(p.y) < ld(xs.back().x) / ld(xs.back().y);
    
    //return p.x * xs.back().y < p.y * xs.back().x;
}

inline int find (int x)
{
    int lf = 0, rg = sz(xs) - 1;
    while (lf != rg)
    {
        int mid = (lf + rg + 1) >> 1;
        
        if (ld(x) * xs[mid].y < xs[mid].x)
            rg = mid - 1;
        else
            lf = mid;
    }
    return lf;
}

inline void solve()
{
    d[0] = 0;
    L.pb(mp(c[0], 0));
    xs.pb(mp(0, 1));
    
    forl(i, n - 1)
    {
        /*forn(j, sz(L)) cerr << "(" << L[j].x << ", " << L[j].y << ") " << ' '; cerr << endl;
        forn(j, sz(xs)) cerr << "(" << xs[j].x << ", " << xs[j].y << ") " << ' '; cerr << endl;
        cerr << endl;*/
        
        int idx = find(x[i]);
        
        //cerr << idx << endl;
        
        d[i] = L[idx].x * x[i] + L[idx].y;
        pt curL = mp(c[i], d[i]);
        
        while (sz(L) >= 2 && bad(curL))
        {
            L.pop_back();
            xs.pop_back();
        }
        
        xs.pb(intersect(curL, L.back()));
        L.pb(curL);
        
        while (ld(xs.back().ft) / ld(xs.back().sc) > 2 * INF)
        {
            L.pop_back();
            xs.pop_back();
        }
    }
    
    cout << d[n - 1] << endl;
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}