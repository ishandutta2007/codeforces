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

int n, m;
vector <int> g[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
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

inline bool bus ()
{
    int cnt1 = 0, cnt2 = 0;
    forn(i, n)
        if (sz(g[i]) == 1) cnt1++;
        else if (sz(g[i]) == 2) cnt2++;
        
    return (cnt1 == 2 && cnt2 == n - 2);
}

inline bool ring ()
{
    forn(i, n)
        if (sz(g[i]) != 2)
            return false;
    return true;
}

inline bool star ()
{
    int cnt1 = 0, cntn = 0;
    forn(i, n)
        if (sz(g[i]) == 1) cnt1++;
        else if (sz(g[i]) == n - 1) cntn++;
    return (cnt1 == n - 1 && cntn == 1);
}

inline void solve()
{
    if (bus())
        puts("bus topology");
    else if (ring())
        puts("ring topology");
    else if (star())
        puts("star topology");
    else
        puts("unknown topology");
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}