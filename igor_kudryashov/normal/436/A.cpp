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

int n, x;
vector <pt> v[2];
vector <int> used[2];

inline bool read()
{
    if (scanf("%d%d", &n, &x) != 2) return false;
    
    forn(i, n)
    {
        int type, a, b;
        assert(scanf("%d%d%d", &type, &a, &b) == 3);
        v[type].pb(mp(b, a));
        used[type].pb(0);
    }
    
    forn(i, 2) sort(all(v[i]));
    
    return true;
}

inline int calc ()
{
    forn(i, 2) forn(j, sz(used[i])) used[i][j] = 0;
    
    int res = 0;
    int iter = 0;
    
    int curx = x;
    
    while (true)
    {
        bool was = false;
        
        ford(i, sz(used[iter]))
        {
            if (used[iter][i] || v[iter][i].sc > curx) continue;
            used[iter][i] = true;
            curx += v[iter][i].ft;
            res++;
            was = true;
            break;
        }
        
        if (!was) break;
        iter ^= 1;
    }
    
    return res;
}

inline void solve()
{
    int ans = 0;
    
    forn(start, 2)
    {
        ans = max(ans, calc());
        swap(v[0], v[1]);
        swap(used[0], used[1]);
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