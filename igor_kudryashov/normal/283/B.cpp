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

const int N = 500 * 1000 + 13;

int n;
int a[N];
vector <int> g[N];
int deg[N];
li d[N];
bool ok[N];

inline bool correct (int x)
{
    return 0 <= x && x < n;
}

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;

    forl(i, n - 1) assert(scanf("%d", &a[i]) == 1);

    return true;
}

inline void solve()
{
    forl(i, n - 1)
    {
        if (correct(i + a[i])) g[i + a[i] + n].pb(i), deg[i]++;
        if (correct(i - a[i])) g[i - a[i]].pb(i + n), deg[i + n]++;
    }

    set <int> s;

    forn(i, 2 * n)
        if (i != 0 && i != n && deg[i] == 0)
            s.insert(i);

    while (!s.empty())
    {
        int v = *s.begin();
        s.erase(s.begin());
        ok[v] = true;

        d[v] = a[v % n];

        //cerr << v << endl;

        if (v < n && correct(v + a[v]))
        {
            assert(ok[v + a[v] + n]);
            d[v] += d[v + a[v] + n];
        }
        if (v >= n && correct(v - n - a[v - n]))
        {
            //cerr << v - n << ' ' << v - n - a[v - n] << endl;
            assert(ok[v - n - a[v - n]]);
            d[v] += d[v - n - a[v - n]];
        }

        forn(i, sz(g[v]))
        {
            int to = g[v][i];
            if (--deg[to] == 0)
                s.insert(to);
            assert(deg[to] >= 0);
        }
    }

    forl(i, n - 1)
    {
        if (!ok[i + n]) puts("-1");
        else cout << d[i + n] + i << endl;//printf("%I64d\n", d[i] + i);
    }
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