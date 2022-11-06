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
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }
inline void clocks() {
    #ifdef SU2_PROJ
        cerr << "=== TIME: " << ld(clock()) / CLOCKS_PER_SEC << " sec ===" << endl;
    #endif
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
inline void makeVariablesUsed() { int a = INF; li b = INF64; ld c = EPS, d = PI; d = a * b + c; }

const int N = 300 * 1000 + 13;

int n, m, q;
vector <int> g[N];
int dsu[N], maxlen[N], tocent[N];

int leader (int v) { return dsu[v] == v ? v : dsu[v] = leader(dsu[v]); }

bool merge (int a, int b)
{
    a = leader(a);
    b = leader(b);
    if (a == b) return false;

    if (max(tocent[b], tocent[a] + 1) > max(tocent[a], tocent[b] + 1)) swap(a, b);

    dsu[a] = b;
    maxlen[b] = max(maxlen[b], maxlen[a]);
    maxlen[b] = max(maxlen[b], tocent[a] + tocent[b] + 1);
    tocent[b] = max(tocent[b], tocent[a] + 1);
}

inline bool read()
{
    if (scanf("%d%d%d", &n, &m, &q) != 3) return false;

    forn(i, m) {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    return true;
}

int d[N], p[N];
vector<int> comp;

inline void bfs (int start)
{
    comp.clear();
    queue <int> q;
    q.push(start);
    d[start] = 0;
    comp.pb(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        forn(i, sz(g[v]))
        {
            int to = g[v][i];
            if (d[to] > d[v] + 1)
            {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push(to);
                comp.pb(to);
            }
        }
    }
}

inline void processComp (int start)
{
    bfs(start);

    int v1 = start;

    //forn(i, sz(comp)) cerr << comp[i] + 1 << ' '; cerr << endl;
    //forn(i, sz(comp)) cerr << d[comp[i]] << ' '; cerr << endl;

    forn(i, sz(comp))
        if (d[comp[i]] > d[v1]) v1 = comp[i];

    forn(i, sz(comp)) d[comp[i]] = INF;

    bfs(v1);

    int v2 = v1;
    forn(i, sz(comp)) if (d[comp[i]] > d[v2]) v2 = comp[i];

    //cerr << "v2 = " << v1 + 1 << ' ' << v2 + 1 << endl;

    vector<int> way;
    while (v2 != v1)
    {
        way.pb(v2);
        v2 = p[v2];
    }
    way.pb(v2);

    //forn(i, sz(comp)) cerr << comp[i] + 1 << ' '; cerr << endl;

    //cerr << "w = "; forn(i, sz(way)) cerr << way[i] + 1 << ' '; cerr << endl;

    int center = way[sz(way) / 2];

    forn(i, sz(comp)) dsu[comp[i]] = center;
    maxlen[center] = sz(way) - 1;
    tocent[center] = sz(way) / 2;
}

inline void prepare ()
{
    memset(d, 63, sizeof(d));
    memset(dsu, -1, sizeof(dsu));
    forn(i, n) if (dsu[i] == -1) processComp(i);
}

inline void solve()
{
    prepare();

    //forn(i, n) cerr << maxlen[i] << ' '; cerr << endl;

    forn(iter, q)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        if (type == 1)
        {
            int v;
            assert(scanf("%d", &v) == 1);
            --v;
            printf("%d\n", maxlen[leader(v)]);

        } else
        {
            int v1, v2;
            assert(scanf("%d%d", &v1, &v2) == 2);
            --v1, --v2;
            merge(v1, v2);
        }
    }
}

int main()
{
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();
    clocks();

    return 0;
}