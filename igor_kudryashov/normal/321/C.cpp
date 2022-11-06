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

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;

int n;
vector <int> g[N];
int s[N];
int can[N];

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
    
    return true;
}

void dfs (int v, int pr)
{
    int cnt[26];
    forn(i, 26) cnt[i] = 0;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        dfs(to, v);
        can[v] |= can[to];
        forn(j, 26) if (can[to] & (1 << j)) cnt[j]++;
    }
    
    int minv = -1;
    forn(j, 26) if (cnt[j] > 1) minv = j;
    
    fore(i, minv + 1, 25)
        if ((can[v] & (1 << i)) == 0)
        {
            s[v] = i;
            can[v] |= (1 << i);
            forn(j, i) if (can[v] & (1 << j)) can[v] ^= (1 << j);
            return;
        }
    
    throw;
}

inline void solve()
{
    dfs(0, 0);
    
    int maxk = 0;
    forn(i, n) maxk = max(maxk, s[i]);

#ifdef SU2_PROJ
    forn(i, n) printf("%c ", char('A' + s[i]));
#else
    forn(i, n) printf("%c ", char('A' + maxk - s[i]));
#endif
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
    
    return 0;
}