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

inline bool operator < (const pt& a, const pt& b)
{
    if (abs(a.x - b.x) > EPS) return a.x < b.x;
    if (abs(a.y - b.y) > EPS) return a.y < b.y;
    return false;
}

inline pt rotate (const pt& v, const ld& ang) { return pt(v.x * cos(ang) - v.y * sin(ang), v.x * sin(ang) + v.y * cos(ang)); }

const int N = 100 * 1000 + 13;

int n;
pt p[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {
        int x, y;
        assert(scanf("%d%d", &x, &y) == 2);
        p[i] = rotate(pt(x, y), PI / 4);
    }
    
    return true;
}

pt pref[N], suf[N];

inline bool can (const ld& d)
{
    int rg = 0;
    
    forn(i, n)
    {
        while (rg < n && p[rg].x - p[i].x <= 2 * d/* + EPS*/) rg++;
        
        ld miny = 1e18, maxy = -1e18;
        if (i > 0) miny = min(miny, pref[i - 1].x), maxy = max(maxy, pref[i - 1].y);
        if (rg < n) miny = min(miny, suf[rg].x), maxy = max(maxy, suf[rg].y);
        
        //cerr << i << ' ' << rg << ' ' << maxy << ' ' << miny << endl;
        
        if (maxy - miny <= 2 * d/* + EPS*/) return true;
    }
    return false;
}

inline void solve()
{
    sort(p, p + n);
    
    //forn(i, n) cerr << p[i].x << ' ' << p[i].y << endl;
    
    forn(i, n)
    {
        if (i > 0) pref[i] = pref[i - 1]; else pref[i] = pt(p[i].y, p[i].y);
        pref[i].x = min(pref[i].x, p[i].y);
        pref[i].y = max(pref[i].y, p[i].y);
    }
    
    ford(i, n)
    {
        if (i + 1 < n) suf[i] = suf[i + 1]; else suf[i] = pt(p[i].y, p[i].y);
        suf[i].x = min(suf[i].x, p[i].y);
        suf[i].y = max(suf[i].y, p[i].y);
    }
    
    //forn(i, n) cerr << pref[i].x << ' ' << pref[i].y << endl; cerr << endl;
    //forn(i, n) cerr << suf[i].x << ' ' << suf[i].y << endl; cerr << endl;
    
    ld lf = 0, rg = 1e12;
    
    forn(iter, 300)
    {
        ld mid = (lf + rg) / 2;
        if (can(mid)) rg = mid; else lf = mid;
    }
    
    lf *= sqrt(2.0);
    
    cout << setprecision(10) << fixed;
    cout << lf << endl;
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