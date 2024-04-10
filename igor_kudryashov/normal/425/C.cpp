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

const int N = 100 * 1000 + 13;
const int M = 300 + 3;

int n[2], S, E;
int a[2][N];
vector <int> pos[N];
int d[N][M];

inline bool read()
{
    if (scanf("%d%d%d%d", &n[0], &n[1], &S, &E) != 4) return false;
    
    forn(iter, 2) forn(i, n[iter])
    {
        assert(scanf("%d", &a[iter][i]) == 1);
        if (iter == 1) pos[a[iter][i]].pb(i);
    }
    
    return true;
}

inline void solve()
{
    memset(d, 63, sizeof(d));
    d[0][0] = 0;
    
    forn(i, n[0]) forn(cnt, M)
    {
        const int& dv = d[i][cnt];
        if (dv > (INF >> 1)) continue;
        
        d[i + 1][cnt] = min(d[i + 1][cnt], dv);
        
        int idx = int(lower_bound(all(pos[a[0][i]]), dv) - pos[a[0][i]].begin());
        
        if (idx < sz(pos[a[0][i]]))
            d[i + 1][cnt + 1] = min(d[i + 1][cnt + 1], pos[a[0][i]][idx] + 1);
    }
    
    int ans = 0;
    
    forn(i, n[0] + 1) forn(cnt, M)
    {
        const int& dv = d[i][cnt];
        if (dv > (INF >> 1)) continue;
        
        li cur = cnt * 1LL * E + i + dv;
        if (cur <= S)
            ans = max(ans, cnt);
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