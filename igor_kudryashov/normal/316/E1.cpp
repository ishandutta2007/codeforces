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

const int N = 100 * 1000 + 13;
const int mod = 1000 * 1000 * 1000;

int n, m;
int a[N];
int f[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

inline void solve()
{
    f[0] = f[1] = 1;
    fore(i, 2, N - 1) f[i] = (f[i - 1] + f[i - 2]) % mod;
    
    forn(iter, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        if (type == 1)
        {
            int x, v;
            assert(scanf("%d%d", &x, &v) == 2);
            --x;
            a[x] = v;
            
        } else
        {
            int lf, rg;
            assert(scanf("%d%d", &lf, &rg) == 2);
            --lf, --rg;
            
            int ans = 0;
            
            forn(i, rg - lf + 1)
                ans = (ans + a[lf + i] * 1LL * f[i]) % mod;
                
            printf("%d\n", ans);
        }       
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