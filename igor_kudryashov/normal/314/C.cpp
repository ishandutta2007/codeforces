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
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int a[N];
int t[N];
int prev[N];
map <int, int> idx;
vector <pt> p;
int d[N];

inline void inc (int i, int val)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] = (t[i] + val) % mod;
}

inline int sum (int i)
{
    int ans = 0;
    
    for (; i >= 0; i = (i & (i + 1)) - 1)
        ans = (ans + t[i]) % mod;
        
    return ans;
}

inline int sum (int lf, int rg)
{
    return (sum(rg) - sum(lf - 1) + mod) % mod;
}

inline bool read()
{
    cin >> n;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

inline void solve()
{
    forn(i, n)
    {
        if (idx.count(a[i])) prev[i] = idx[a[i]]; else prev[i] = -1;
        idx[a[i]] = i;
    }
    
    forn(i, n) p.pb(mp(a[i], i));
    
    sort(all(p));
    
    int ans = 0;
    
    forn(it, n)
    {
        int i = p[it].sc;
        
        int lf = (prev[i] == -1 ? 0 : prev[i]);
        int cur = sum(lf, i);
        if (prev[i] == -1) cur++;
        
        cur = (cur * 1LL * a[i]) % mod;
        inc(i, cur);
        
        ans = (ans + cur) % mod;
    }
    
    cout << ans << endl;
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