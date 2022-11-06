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

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

vector <int> a, d;
vector <int> c;

inline bool read()
{
    int k, n;
    if (scanf("%d%d", &k, &n) != 2)
        return false;
        
    forn(i, k)
    {
        char buf[10];
        int val;
        assert(scanf("%s%d", buf, &val) == 2);
        if (buf[0] == 'A') a.pb(val); else d.pb(val);
    }
    
    c.resize(n);
    forn(i, n) assert(scanf("%d", &c[i]) == 1);
    
    return true;
}

inline int calc (vector <int> c, vector <int> a, bool flag)
{
    int ans = 0;
    
    forn(i, sz(a) + 1)
    {
        if (sz(c) < i) break;
        
        bool ok = true;
        int s = 0;
        
        for (int j = i - 1, k = sz(c) - 1; j >= 0; j--, k--)
        {
            if (c[k] < a[j])
            {
                ok = false;
                break;
            }
            
            s += c[k] - a[j];
        }
        
        if (!ok) continue;
        
        if (i == sz(a) && flag)
            forn(j, sz(c) - sz(a)) s += c[j];
            
        ans = max(ans, s);
    }
    
    return ans;
}

inline bool canBeat (vector <int> c, vector <int> d, vector <int>& rem)
{
    reverse(all(d));
    
    forn(i, sz(c))
    {
        bool taken = false;
        
        forn(j, sz(d))
            if (c[i] > d[j])
            {
                d.erase(d.begin() + j);
                taken = true;
                break;
            }
            
        if (!taken) rem.pb(c[i]);
    }
    
    if (d.empty()) return true;
    return false;
}

inline void solve()
{
    sort(all(a));
    sort(all(d));
    sort(all(c));
    
    int ans = calc(c, a, false);
    
    vector <int> v;
    if (canBeat(c, d, v))
        ans = max(ans, calc(v, a, true));
        
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
    
    return 0;
}