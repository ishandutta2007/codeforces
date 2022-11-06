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

const int SH = 10 * 1000 + 13;
const int M = 2 * SH;
const int N = 1000 + 3;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int a[N];
int d[N][M];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

inline void add (int& a, int b)
{
    a += b;
    while (a >= mod) a -= mod;
}

int solve (int pos, int bal)
{
    int& ans = d[pos][bal];
    if (ans != -1) return ans;
    
    ans = (bal == SH);
    
    //cerr << mp(pos, bal) << ' ' << ans << endl;
    
    if (pos == n) return ans;
    
    add(ans, solve(pos + 1, bal - a[pos]));
    add(ans, solve(pos + 1, bal + a[pos]));
    
    //cerr << mp(pos, bal) << ' ' << ans << endl;
    
    return ans;
}

inline void solve()
{
    memset(d, -1, sizeof(d));
    
    int ans = 0;
    
    ford(i, n)
    {
        add(ans, solve(i + 1, SH - a[i]));
        add(ans, solve(i + 1, SH + a[i]));
    }
    
    cout << ans << endl;
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