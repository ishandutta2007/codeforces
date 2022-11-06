#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;

int n;
int a[N];
int s[N];
pt p[N];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n)
    {
        assert(scanf("%d", &a[i]) == 1);
        s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];
        p[i] = mp(i, s[i]);
    }
    
    return true;
}

li ans;

inline bool cmpY (const pt& a, const pt& b)
{
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

inline void upd (const pt& a, const pt& b)
{
    //cerr << a << ' ' << b << endl;
    ans = min(ans, sqr(li(a.x - b.x)) + sqr(li(a.y - b.y)));
}

pt tmp[N];
int sztmp;

void go (int lf, int rg)
{
    if (rg - lf <= 4)
    {
        fore(i, lf, rg)
            fore(j, i + 1, rg)
                upd(p[i], p[j]);
                
        sort(p + lf, p + rg + 1, &cmpY);
        return;
    }
 
    int mid = (lf + rg) >> 1;
    int midx = p[mid].x;
    
    go(lf, mid);
    go(mid + 1, rg);
    
    inplace_merge(p + lf, p + mid + 1, p + rg + 1, &cmpY);
    
    sztmp = 0;
    
    fore(i, lf, rg)
        if (sqr(li(p[i].x - midx)) < ans)
        {
            for (int j = sztmp - 1; j >= 0 && sqr(li(p[i].y - tmp[j].y)) < ans; j--)
                upd(p[i], tmp[j]);
            tmp[sztmp++] = p[i];
        }
}

inline li naive ()
{
    li res = INF64;
    
    forn(i, n) forn(j, i) res = min(res, sqr(li(i - j)) + sqr(li(s[i] - s[j])));
    
    return res;
}

inline void solve()
{
    ans = INF64;
    go(0, n - 1);
    
    cout << ans << endl;
    //assert(ans == naive());
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
    
    while (true)
    {
        n = 1000;
        forn(i, n)
        {
            a[i] = rand() * ((rand() & 1) ? 1 : -1);
            s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];
            p[i] = mp(i, s[i]);
        }
        
        solve();
    }
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}