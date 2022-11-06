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
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 * 1000 + 13;

int n;
int a[N];
int maxd[N];
int lf, rg;

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    assert(scanf("%d%d", &rg, &lf) == 2);
    
    return true;
}

int d[N];

inline void solve()
{
    sort(a, a + n);
    n = int(unique(a, a + n) - a);
    
    forn(i, n)
    {
        int t = ((lf + a[i] - 1) / a[i]) * a[i];
        
        while (t <= rg)
        {
            maxd[t - lf] = a[i];
            t += a[i];
        }
    }
    
    //forn(i, rg - lf + 1) cerr << i + lf << ' ' << maxd[i] << endl;
    
    deque <int> q;
    q.pb(0);
    
    memset(d, 63, sizeof(d));
    d[0] = 0;
    
    rg -= lf;
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        
        {
            int nv = min(rg, v + maxd[v] - 1);
            if (maxd[v] == 0) nv = min(rg, v + 1);
            
            if (d[nv] > d[v] + 1)
            {
                d[nv] = d[v] + 1;
                q.pb(nv);
            }
        }
        
        if (v + 1 <= rg && d[v + 1] > d[v] + 1)
        {
            d[v + 1] = d[v] + 1;
            q.pb(v + 1);
        }
        
        if (v > 0 && d[v - 1] > d[v])
        {
            d[v - 1] = d[v];
            q.push_front(v - 1);
        }
    }
    
    printf("%d\n", d[rg]);
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
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}