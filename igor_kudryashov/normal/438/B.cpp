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

int n, m;
int a[N];
vector <int> g[N];
int dsu[N], sz[N];

int leader (int v) { return dsu[v] == v ? v : dsu[v] = leader(dsu[v]); }

bool merge (int a, int b)
{
    a = leader(a);
    b = leader(b);
    
    if (a == b) return false;
    
    if (rand() & 1) swap(a, b);
    
    dsu[a] = b;
    sz[b] += sz[a];
    
    return true;
}

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    return true;
}

int used[N];
int was[N], w;

inline void solve()
{
    vector <pt> ord;
    forn(i, n) ord.pb(mp(a[i], i));
    
    sort(all(ord));
    reverse(all(ord));
    
    forn(i, n) dsu[i] = i, sz[i] = 1;
    
    ld ans = 0;
    
    forn(it, sz(ord))
    {
        int v = ord[it].sc;
        
        int sum = 0;
        w++;
        
        forn(i, sz(g[v]))
        {
            int to = g[v][i];
            if (!used[to]) continue;
            to = leader(to);
            if (was[to] == w) continue;
            was[to] = w;
            
            //cerr << v << ' ' << to << ' ' << a[v] << ' ' << sum << ' ' << sz[leader(to)] << endl;
            ans += ld(a[v]) * ld(sum) * ld(sz[to]);
            sum += sz[to];
        }
        
        //cerr << sum << ' ' << a[v] << endl;
        ans += ld(sum) * ld(a[v]);
        
        forn(i, sz(g[v]))
        {
            int to = g[v][i];
            if (!used[to]) continue;
            merge(v, to);
        }
        
        used[v] = true;
    }
    
    ans /= n * 1LL * (n - 1) / 2;
    
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