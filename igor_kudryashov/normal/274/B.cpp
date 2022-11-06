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

int n;
vector <int> g[N];
li v[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;

    forn(i, n - 1)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    forn(i, n)
    {
        int tmp;
        assert(scanf("%d", &tmp) == 1);
        v[i] = tmp;
    }

    return true;
}

li minv[N], maxv[N];

void dfs (int v, int pr)
{
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        dfs(to, v);
        minv[v] = min(minv[v], minv[to]);
        maxv[v] = max(maxv[v], maxv[to]);
    }

    li cur = ::v[v] + maxv[v] + minv[v];
    if (cur >= 0) minv[v] -= cur; else maxv[v] -= cur;

    //cerr << v << ' ' << minv[v] << ' ' << maxv[v] << endl;
}

inline void solve()
{
    dfs(0, 0);
    cout << -minv[0] + maxv[0] << endl;
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