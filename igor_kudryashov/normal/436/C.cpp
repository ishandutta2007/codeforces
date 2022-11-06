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

const int N = 1000 + 3;
const int M = 10 + 3;

int n, w, h, c;
char f[N][M][M];
int g[N][N];

inline bool read()
{
    if (scanf("%d%d%d%d", &h, &w, &n, &c) != 4) return false;
    
    forn(idx, n)
        forn(i, h) assert(scanf("%s", f[idx][i]) == 1);
    
    return true;
}

inline void prepare ()
{
    forn(idx1, n) forn(idx2, idx1)
    {
        forn(i, h) forn(j, w) g[idx1][idx2] += bool(f[idx1][i][j] != f[idx2][i][j]);
        g[idx1][idx2] *= c;
        //cerr << idx1 << ' ' << idx2 << ' ' << g[idx1][idx2] << endl;
        g[idx1][idx2] = min(g[idx1][idx2], h * w);
        g[idx2][idx1] = g[idx1][idx2];
    }
}

int d[N], p[N];
int used[N];
vector <pt> ansv;

inline void solve()
{
    prepare();
    
    int ans = h * w;
    
    forn(i, n) d[i] = INF;
    d[0] = 0;
    
    memset(p, -1, sizeof(p));
    
    while (true)
    {
        int idx = -1, minv = INF;
        
        forn(i, n) if (!used[i] && d[i] < minv) { minv = d[i], idx = i; }
        
        if (idx == -1) break;
        
        ans += d[idx];
        
        if (d[idx] == h * w)
            ansv.pb(mp(idx, -1));
        else
            ansv.pb(mp(idx, p[idx]));
        
        used[idx] = true;
        
        forn(i, n) if (d[i] > g[idx][i])
        {
            d[i] = g[idx][i];
            p[i] = idx;
        }
    }
    
    printf("%d\n", ans);
    
    forn(i, sz(ansv)) printf("%d %d\n", ansv[i].ft + 1, ansv[i].sc + 1);
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