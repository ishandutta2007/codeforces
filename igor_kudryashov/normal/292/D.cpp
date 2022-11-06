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

const int N = 500 + 13;
const int M = 10 * 1000 + 13;

int n, m;
int dsup[M][N], dsus[M][N];
pt ed[M];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forl(i, m) assert(scanf("%d%d", &ed[i].ft, &ed[i].sc) == 2), ed[i].ft--, ed[i].sc--;
        
    return true;
}

int leader (int dsu[N], int v) { return dsu[v] == v ? v : dsu[v] = leader(dsu, dsu[v]); }

inline bool merge (int dsu[N], int a, int b)
{
    a = leader(dsu, a);
    b = leader(dsu, b);
    if (a == b) return false;
    if (rand() & 1) dsu[a] = b; else dsu[b] = a;
    return true;
}

void prepare ()
{
    forn(iter, m + 1)
    {
        forn(i, n) dsup[iter][i] = (iter == 0 ? i : dsup[iter - 1][i]);
        merge(dsup[iter], ed[iter].ft, ed[iter].sc);
        forn(i, n) leader(dsup[iter], i);
    }
    
    ford(iter, m + 2)
    {
        forn(i, n) dsus[iter][i] = (iter == m + 1 ? i : dsus[iter + 1][i]);
        merge(dsus[iter], ed[iter].ft, ed[iter].sc);
        forn(i, n) leader(dsus[iter], i);
    }
}

int dsu[N];

inline void solve()
{
    prepare();
    
    int k;
    assert(scanf("%d", &k) == 1);
    
    forn(iter, k)
    {
        int lf, rg;
        assert(scanf("%d%d", &lf, &rg) == 2);
        
        forn(i, n) dsu[i] = dsup[lf - 1][i];
        forn(i, n) merge(dsu, i, dsus[rg + 1][i]);
        
        int ans = 0;
        forn(i, n) if (leader(dsu, i) == i) ans++;
        
        printf("%d\n", ans);
    }
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