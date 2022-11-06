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

int n, k, p;
vector <int> g[N];
li sum[N], sumk[N];
int dep[N];
int a[N];

void dfs (int v, int pr, int dep)
{
    ::dep[dep]++;
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        dfs(to, v, dep + 1);
    }
}

inline bool read()
{
    if (scanf("%d%d%d", &n, &k, &p) != 3) return false;
    
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

inline li Sum (int lf, int rg)
{
    if (lf > rg) return 0;
    return sum[rg] - (lf == 0 ? 0 : sum[lf - 1]);
}

inline li calc (int start, int len)
{
    if (len == 0) return 0;
    
    li ans = sumk[start + len - 1];
    if (start > 0) ans -= sumk[start - 1];
    
    li cur = Sum(start, start + len - 1);
    ans -= cur * start;
    
    return ans;
}

inline int get (int start)
{
    int lf = 0, rg = n - start;
    
    while (lf != rg)
    {
        int mid = (lf + rg + 1) >> 1;
        
        li val = calc(start, mid);
        if (val <= p) lf = mid;
        else rg = mid - 1;
    }
    
    return lf;
}

inline void solve()
{
    dfs(0, 0, 0);
    forn(i, N) if (dep[i] > 0) n = i;
    n++;
    forn(i, N) a[i] = dep[i];
    reverse(a, a + n);
    n--;
    
    forn(i, n)
    {
        sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
        sumk[i] = (i == 0 ? 0 : sumk[i - 1]) + a[i] * 1LL * i;
    }
    
    //forn(i, n) cerr << a[i] << ' '; cerr << endl;
    
    int ans = 0;
    
    forn(i, n)
    {
        int whole = get(i);
        //cerr << mp(i, whole) << endl;
        int rem = int(p - calc(i, whole));
        //cerr << rem << endl;
        int add = rem / whole;
        //cerr << add << endl;
        if (i + whole >= n) add = 0;
        
        int total = int(Sum(i, i + whole - 1)) + add;
        ans = max(ans, min(k, total));
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