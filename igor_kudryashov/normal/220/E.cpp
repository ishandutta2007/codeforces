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

int n;
li k;
int a[N];
int x[N], szx;
li pinv[N], sinv[N];
int t1[N], t2[N];

inline bool read()
{
    if (scanf("%d%I64d", &n, &k) != 2)
        return false;
        
    forn(i, n)
    {
        assert(scanf("%d", &a[i]) == 1);
        x[szx++] = a[i];
    }
    
    return true;
}

inline void inc (int t[N], int i, int val)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] += val;
}

inline int sum (int t[N], int i)
{
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        ans += t[i];
    return ans;
}

void prepare ()
{
    sort(x, x + szx);
    szx = int(unique(x, x + szx) - x);
    
    forn(i, n)
    {
        int idx = int(lower_bound(x, x + szx, a[i]) - x);
        pinv[i] = (i == 0 ? 0 : pinv[i - 1]) + i - sum(t1, idx);
        inc(t1, idx, 1);
    }
    
    ford(i, n)
    {
        int idx = int(lower_bound(x, x + szx, a[i]) - x);
        sinv[i] = (i == n - 1 ? 0 : sinv[i + 1]) + sum(t2, idx - 1);
        inc(t2, idx, 1);
    }
}

inline void solve()
{
    prepare();
    
    li ans = 0;
    
    memset(t1, 0, sizeof(t1));
    memset(t2, 0, sizeof(t2));
    
    int rg = 1;
    li cur = sinv[rg];
    
    forl(i, n - 1)
        inc(t2, int(lower_bound(x, x + szx, a[i]) - x), 1);
        
    forn(lf, n - 1)
    {
        assert(rg >= lf);
        
        if (rg == lf)
        {
            cur -= sinv[rg] - sinv[rg + 1];
            cur -= rg - sum(t1, int(lower_bound(x, x + szx, a[rg]) - x));
            inc(t2, int(lower_bound(x, x + szx, a[rg]) - x), -1);
            rg++;
        }
        
        cur += (lf == 0 ? 0 : pinv[lf] - pinv[lf - 1]);
        cur += sum(t2, int(lower_bound(x, x + szx, a[lf]) - x) - 1);
        inc(t1, int(lower_bound(x, x + szx, a[lf]) - x), 1);
        
        while (rg < n && cur > k)
        {
            cur -= sinv[rg] - sinv[rg + 1];
            cur -= lf + 1 - sum(t1, int(lower_bound(x, x + szx, a[rg]) - x));
            inc(t2, int(lower_bound(x, x + szx, a[rg]) - x), -1);
            rg++;
        }
        
        if (rg == n) break;
        ans += n - rg;
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