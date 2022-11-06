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

const int N = 200 + 3;

int n, k;
int a[N];

inline bool read()
{
    if (scanf("%d%d", &n, &k) != 2) return false;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

inline void solve()
{
    int ans = -INF;
    
    forn(lf, n)
    {
        vector <int> v[2];
        v[0].pb(a[lf]);
        forn(i, n) if (i != lf) v[1].pb(a[i]);
        sort(all(v[1]));
        
        int sum = a[lf];
        
        fore(rg, lf, n - 1)
        {
            /*if (lf == 1 && rg == 8)
            {
                forn(i, 2) { forn(j, sz(v[i])) cerr << v[i][j] << ' '; cerr << endl; }
            }*/
        
            int cur = sum;
            forn(i, sz(v[0]))
            {
                if (i >= k || i >= sz(v[1])) break;
                if (v[0][i] >= v[1][sz(v[1]) - 1 - i]) break;
                cur -= v[0][i];
                cur += v[1][sz(v[1]) - 1 - i];
            }
            ans = max(ans, cur);
            
            if (rg + 1 == n) break;
            
            v[1].erase(find(all(v[1]), a[rg + 1]));
            v[0].pb(a[rg + 1]);
            int pos = sz(v[0]) - 1;
            while (pos > 0 && v[0][pos] < v[0][pos - 1])
            {
                swap(v[0][pos], v[0][pos - 1]);
                pos--;
            }
            sum += a[rg + 1];
        }
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