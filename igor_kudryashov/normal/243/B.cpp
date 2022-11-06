#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for(int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 100 * 1000 + 13;

int n, m, h, t;
vector <int> g[N];

inline bool read()
{
    if (scanf("%d%d%d%d", &n, &m, &h, &t) != 4)
        return false;

    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        //a = rand() % n, b = rand() % n;
        //if (a == b) b = (b + 1) % n;

        g[a].pb(b);
        g[b].pb(a);
    }

    return true;
}

inline bool check (int u, int v)
{
    if (sz(g[u]) - 1 >= h && sz(g[v]) - 1 >= t) return true;
    //if (sz(g[v]) - 1 >= h && sz(g[u]) - 1 >= t) return true;
    return false;
}

int HV, TV;
vector <int> heads, tails;

inline int getCom (int u, int v)
{
    assert(sz(g[u]) <= sz(g[v]));

    int p = 0;
    int ans = 0;

    forn(i, sz(g[u]))
    {
        while (p < sz(g[v]) && g[v][p] < g[u][i]) p++;
        if (p < sz(g[v]) && g[v][p] == g[u][i]) ans++;
    }

    return ans;
}

inline void getAns (int u, int v)
{
    set <int> sv, su;
    forn(i, sz(g[v])) sv.insert(g[v][i]);
    forn(i, sz(g[u])) su.insert(g[u][i]);
    sv.insert(v);
    su.insert(u);

    HV = u, TV = v;

    vector <int> v1, v2, vs;

    forn(i, sz(g[u]))
        if (!sv.count(g[u][i]))
            v1.pb(g[u][i]);
        else if (g[u][i] != v)
            vs.pb(g[u][i]);

    forn(i, sz(g[v]))
        if (!su.count(g[v][i]))
            v2.pb(g[v][i]);

    heads = v1;
    tails = v2;

    forn(i, sz(vs))
        if (sz(heads) < h)
            heads.pb(vs[i]);
        else
            tails.pb(vs[i]);

    while (sz(heads) > h) heads.pop_back();
    while (sz(tails) > t) tails.pop_back();
}

inline bool tryAns (int u, int v)
{
    int com = (sz(g[u]) > sz(g[v]) ? getCom(v, u) : getCom(u, v));

    if (sz(g[u]) - 1 + sz(g[v]) - 1 - com >= h + t)
    {
        getAns(u, v);
        return true;
    }

    return false;
}

inline void solve()
{
    forn(i, n) sort(all(g[i]));

    forn(v, n)
        forn(j, sz(g[v]))
        {
            int u = g[v][j];
            if (!check(v, u)) continue;
            if (tryAns(v, u))
            {
                puts("YES");
                printf("%d %d\n", HV + 1, TV + 1);
                forn(i, sz(heads)) printf("%d ", heads[i] + 1);
                puts("");
                forn(i, sz(tails)) printf("%d ", tails[i] + 1);
                puts("");
                return;
            }
        }

    puts("NO");
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    assert(read());
    solve();

    return 0;
}