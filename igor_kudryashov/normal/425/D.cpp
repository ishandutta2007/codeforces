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
pt p[N];
vector <int> ys[N];
int hx[N], szhx;
bool heavy[N];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n) assert(scanf("%d%d", &p[i].x, &p[i].y) == 2);
    
    return true;
}

inline int calc (int x1, int y1, int y2)
{
    int res = 0;
    
    int x2 = x1 - (y2 - y1);
    
    if (x2 >= 0 && binary_search(p, p + n, mp(x2, y1)) && binary_search(p, p + n, mp(x2, y2)))
        res++;
        
    x2 = x1 + (y2 - y1);
    
    if (x2 < N && heavy[x2] && binary_search(p, p + n, mp(x2, y1)) && binary_search(p, p + n, mp(x2, y2)))
        res++;
        
    return res;
}

inline int calcH (int x1, int x2, int y2)
{
    if (!binary_search(p, p + n, mp(x1, y2))) return 0;
    
    int res = 0;
    
    int y1 = y2 - (x2 - x1);
    
    if (y1 >= 0 && binary_search(p, p + n, mp(x1, y1)) && binary_search(p, p + n, mp(x2, y1)))
        res++;
        
    /*y1 = y2 + (x2 - x1);
    
    if (y1 < N && binary_search(p, p + n, mp(x1, y1)) && binary_search(p, p + n, mp(x2, y1)))
        res++;*/
        
    return res;
}

inline void solve()
{
    sort(p, p + n);
    
    forn(i, n) ys[p[i].x].pb(p[i].y);
    
    forn(i, N) if (sqr(li(sz(ys[i]))) > n) { hx[szhx++] = i; heavy[i] = true; }
    
    li ans = 0;
    
    forn(x, N) forn(idy, sz(ys[x]))
    {
        int y = ys[x][idy];
        
        if (!heavy[x])
        {
            forn(idy2, idy)
            {
                int y2 = ys[x][idy2];
                ans += calc(x, y2, y);
            }
            
        } else
        {
            forn(idx2, szhx)
            {
                int x2 = hx[idx2];
                if (x2 >= x) break;
                ans += calcH(x2, x, y);
            }
        }
    }
    
    cout << ans << endl;
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
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}