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

const int N = 100 * 1000 + 13;

struct edge
{
    int to, w, idx;
    edge () {}
    edge (int to, int w, int idx) : to(to), w(w), idx(idx) {}
};

int n, m, k;
vector <edge> g[N];

inline bool read()
{
    if (scanf("%d%d%d", &n, &m, &k) != 3) return false;

    forn(i, m)
    {
        int a, b, c;
        assert(scanf("%d%d%d", &a, &b, &c) == 3);
        --a, --b;
        g[a].pb(edge(b, c, i));
        g[b].pb(edge(a, c, i));
    }

    forn(i, k)
    {
        int to, w;
        assert(scanf("%d%d", &to, &w) == 2);
        --to;
        g[0].pb(edge(to, w, m + i));
        g[to].pb(edge(0, w, m + i));
    }

    return true;
}

typedef pair <li, int> ptl;

li d[N];
int p[N], pe[N];
set <ptl> s;
int used[N];

inline void solve()
{
    forn(i, N) d[i] = INF64;
    memset(p, -1, sizeof(p));
    memset(pe, -1, sizeof(pe));

    d[0] = 0;
    s.insert(mp(0LL, 0));

    while (!s.empty())
    {
        int v = s.begin()->sc;
        s.erase(s.begin());

        if (used[v]) continue;
        used[v] = true;

        forn(i, sz(g[v]))
        {
            int to = g[v][i].to, w = g[v][i].w, idx = g[v][i].idx;

            if (d[to] > d[v] + w || (d[to] == d[v] + w && pe[to] > idx))
            {
                s.erase(mp(d[to], to));
                d[to] = d[v] + w;
                p[to] = v;
                pe[to] = idx;
                s.insert(mp(d[to], to));
            }
        }
    }

    int ans = k;

    forn(i, n) if (pe[i] >= m) ans--;

    cout << ans << endl;
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