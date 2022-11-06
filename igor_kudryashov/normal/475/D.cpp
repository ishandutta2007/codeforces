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

const int N = 300 * 1000 + 13;

int n, m;
int a[N], b[N];
map <int, li> ans;

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    assert(scanf("%d", &m) == 1);
    forn(i, m)
    {
        assert(scanf("%d", &b[i]) == 1);
        ans[b[i]] = 0;
    }
    return true;
}

inline void solve()
{
    vector<pt> cur;
    
    ford(i, n)
    {
        vector<pt> next;
        next.pb(mp(a[i], i));
        if (ans.count(a[i])) ans[a[i]]++;
        
        forn(j, sz(cur))
        {
            int g = __gcd(next.back().ft, cur[j].ft);
            if (ans.count(g)) ans[g] += cur[j].sc - next.back().sc;
            if (next.back().ft == g) next.back().sc = cur[j].sc;
            else next.pb(mp(g, cur[j].sc));
        }
        
        cur = next;
    }
    
    forn(i, m) printf("%I64d\n", ans[b[i]]);
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