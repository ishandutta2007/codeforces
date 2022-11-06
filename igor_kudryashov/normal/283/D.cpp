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

const int N = 5000 + 13;

int n;
li a[N];
int d[N];
int degs[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n) assert(scanf("%I64d", &a[i]) == 1);
    
    return true;
}

inline int deg (li a) { int res = 0; while ((a & 1) == 0) res++, a >>= 1; return res; }

inline bool can (int i1, int i2)
{
    if (a[i2] & 1) return a[i1] % a[i2] == 0;
    
    int deg1 = degs[i1], deg2 = degs[i2];
    
    if (deg2 - deg1 != i2 - i1 && deg2 > i2 - i1 - 1) return false;
    
    return (a[i1] >> deg1) % (a[i2] >> deg2) == 0;
}

inline void solve()
{
    forn(i, n) degs[i] = deg(a[i]);
    
    int ans = 0;
    
    forn(i, n)
    {
        int maxv = 0;
        forn(j, i)
            if (can(j, i))
                maxv = max(maxv, d[j]);
                
        d[i] = maxv + 1;
        ans = max(ans, d[i]);
    }
    
    cout << n - ans << endl;
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