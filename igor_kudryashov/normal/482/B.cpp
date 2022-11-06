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

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;
const int LOGN = 30 + 3;

int n, m;
int a[LOGN][N];
int s[LOGN][N];
int lfs[N], rgs[N], vals[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    return true;
}

inline void solve()
{
    forn(i, m)
    {
        int lf, rg, val;
        assert(scanf("%d%d%d", &lf, &rg, &val) == 3);
        lf--, rg--;
        lfs[i] = lf;
        rgs[i] = rg;
        vals[i] = val;
        forn(j, 30) if (val & (1 << j))
        {
            a[j][lf]++;
            a[j][rg + 1]--;
        }
    }
    
    forn(j, LOGN)
        forl(i, n - 1)
            a[j][i] += a[j][i - 1];
    
    forn(j, LOGN)
        forn(i, n)
        {
            if (i > 0) s[j][i] = s[j][i - 1];
            s[j][i] += (a[j][i] > 0 ? 1 : 0);
        }
    
    //forn(j, 4) { forn(i, n) cerr << s[j][i] << ' '; cerr << endl; }
    
    forn(i, m)
    {
        int cur = 0;
        
        forn(j, 30)
        {
            int sum = s[j][rgs[i]];
            if (lfs[i] > 0) sum -= s[j][lfs[i] - 1];
            if (sum == rgs[i] - lfs[i] + 1) cur |= (1 << j);
        }
        
        if (cur != vals[i])
        {
            puts("NO");
            return;
        }
    }
    
    puts("YES");
    
    forn(i, n)
    {
        int cur = 0;
        forn(j, 30) if (a[j][i]) cur |= (1 << j);
        printf("%d ", cur);
    }
    
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
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}