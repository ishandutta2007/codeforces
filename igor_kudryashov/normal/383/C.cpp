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

const int N = 400 * 1000 + 13;

int n, m;
int a[N];
vector <int> g[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    forn(i, n - 1)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    return true;
}

int fir[N], last[N], dep[N];
int sz;
int t[2][N];

inline void inc (int idx, int i, int val)
{
    for (; i < sz; i = (i | (i + 1)))
        t[idx][i] += val;
}

inline int sum (int idx, int i)
{
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        ans += t[idx][i];
    return ans;
}

void dfs (int v, int pr, int d)
{
    fir[v] = sz++;
    dep[v] = d;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        
        dfs(to, v, d ^ 1);
    }
    
    last[v] = sz++;
}

inline void solve()
{
    dfs(0, 0, 0);
    
    forn(iter, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        if (type == 1)
        {
            int v, val;
            assert(scanf("%d%d", &v, &val) == 2);
            --v;
            inc(dep[v], fir[v], val);
            inc(dep[v], last[v], -val);
            
        } else
        {
            int v;
            assert(scanf("%d", &v) == 1);
            --v;
            
            printf("%d\n", sum(dep[v], fir[v]) - sum(dep[v] ^ 1, fir[v]) + a[v]);
        }
    }
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