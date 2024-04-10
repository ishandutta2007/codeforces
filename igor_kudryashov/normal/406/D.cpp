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
typedef pair<li, li> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;
const int LOGN = 20;

int n;
pt p[N];
int pr[N][LOGN];
vector <int> g[N];
int T, tin[N], tout[N];

inline bool parent (int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

inline int lca (int a, int b)
{
    if (parent(a, b)) return a;
    if (parent(b, a)) return b;
    
    ford(i, LOGN)
        if (!parent(pr[a][i], b))
            a = pr[a][i];
            
    assert(!parent(a, b) && parent(pr[a][0], b));
    return pr[a][0];
}

void dfs (int v)
{
    tin[v] = T++;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        dfs(to);
    }
    
    tout[v] = T++;
}

inline li cross (const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }

inline pt operator - (const pt& a, const pt& b) { return mp(a.x - b.x, a.y - b.y); }

inline bool turnLeft (int a, int b, int c)
{
    return cross(p[b] - p[a], p[c] - p[b]) > 0;
}

inline int getp (int v) { return v == n - 1 ? n : pr[v][0]; }

inline void prepare ()
{
    forn(i, LOGN)
        pr[n - 1][i] = n - 1;
    
    ford(i, n - 1)
    {
        int v = i + 1;
        
        ford(j, LOGN)
        {
            int vv = pr[v][j], pv = getp(vv); //(vv == n - 1 ? n : pr[vv][0]);
            
            //if (i == 3) cerr << vv << ' ' << pv << ' ' << turnLeft(i, vv, pv) << endl;
            
            if (turnLeft(i, vv, pv))
                v = pv;
        }
        
        while (turnLeft(i, v, getp(v))) v = getp(v);
        
        g[v].pb(i);
        pr[i][0] = v;
        forl(j, LOGN - 1) pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
    
    dfs(n - 1);
    
    //forn(i, n) cerr << pr[i][0] << ' '; cerr << endl;
}

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n) assert(scanf("%I64d%I64d", &p[i].x, &p[i].y) == 2);
    p[n] = mp(p[n - 1].x, 0);
    
    return true;
}

inline void solve()
{
    prepare();
    
    int m;
    assert(scanf("%d", &m) == 1);
    
    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        printf("%d ", lca(a, b) + 1);
    }
    puts("");
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