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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 2000 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int a[N];
int have[N];
int d[N][N];
int f[N];

int solve (int c1, int c2)
{
    int& ans = d[c1][c2];
    if (ans != -1) return ans;
    
    if (c1 == 0) return ans = f[c2];
    
    ans = int((solve(c1 - 1, c2) * 1LL * c2) % mod);
    
    if (c1 > 1)
    {
        ans += int((solve(c1 - 2, c2 + 1) * 1LL * (c1 - 1)) % mod);
        if (ans >= mod) ans -= mod;
    }
    
    return ans;
}

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {
        assert(scanf("%d", &a[i]) == 1);

        if (a[i] > 0)
        {
            a[i]--;
            have[a[i]] = true;
        }
    }
    
    return true;
}

inline void solve()
{
    f[0] = 1;
    forl(i, N - 1) f[i] = int((f[i - 1] * 1LL * i) % mod);
    
    int c1 = 0, c2 = 0;
    
    forn(i, n)
        if (!have[i])
        {
            if (a[i] == -1) c1++; else c2++;
        }
        
    //cerr << c1 << ' ' << c2 << endl;
    
    memset(d, -1, sizeof(d));
    
    cout << solve(c1, c2) << endl;
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
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}