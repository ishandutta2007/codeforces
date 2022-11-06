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
typedef pair<li, li> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 200 * 1000 + 13;
const int mod = 1000 * 1000 * 1000;

int n, m;
int a[N];
pt t[4 * N];
li add[4 * N];
li f[N];
li s[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forn(i, n)
        assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

void push (int idx, int lf, int rg)
{
    int mid = (lf + rg) >> 1;
    
    forl(i, 2)
    {
        li len = (i == 0 ? mid - lf + 1 : rg - mid);
        
        t[2 * idx + i].ft = li((t[2 * idx + i].ft + ((len < 2 ? 0 : s[len - 2]) + 1) * 1LL * add[idx]) % mod);
        t[2 * idx + i].sc = li((t[2 * idx + i].sc + s[len - 1] * 1LL * add[idx]) % mod);
        add[2 * idx + i] = (add[2 * idx + i] + add[idx]) % mod;
    }
    
    add[idx] = 0;
}

void upd (int idx, int lf, int rg, int pos, li val)
{
    if (lf == rg)
    {
        t[idx] = mp(val, 0);
        return;
    }
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid) upd(2 * idx + 1, lf, mid, pos, val);
    else upd(2 * idx + 2, mid + 1, rg, pos, val);
    
    int len = mid - lf + 1;
    
    t[idx].ft = li((t[2 * idx + 1].ft + f[len - 1] * 1LL * t[2 * idx + 2].ft + f[len] * 1LL * t[2 * idx + 2].sc) % mod);
    t[idx].sc = li((t[2 * idx + 1].sc + f[len] * 1LL * t[2 * idx + 2].ft + f[len + 1] * 1LL * t[2 * idx + 2].sc) % mod);
}

void inc (int idx, int lf, int rg, int l, int r, li val)
{
    if (lf == l && rg == r)
    {
        int len = rg - lf + 1;
        
        t[idx].ft = li((t[idx].ft + ((len < 2 ? 0 : s[len - 2]) + 1) * 1LL * val) % mod);
        t[idx].sc = li((t[idx].sc + s[len - 1] * 1LL * val) % mod);
        add[idx] = (add[idx] + val) % mod;
        return;
    }
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (l <= mid)
        inc(2 * idx + 1, lf, mid, l, min(mid, r), val);
        
    if (r > mid)
        inc(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r, val);
        
    int len = mid - lf + 1;
        
    t[idx].ft = li((t[2 * idx + 1].ft + f[len - 1] * 1LL * t[2 * idx + 2].ft + f[len] * 1LL * t[2 * idx + 2].sc) % mod);
    t[idx].sc = li((t[2 * idx + 1].sc + f[len] * 1LL * t[2 * idx + 2].ft + f[len + 1] * 1LL * t[2 * idx + 2].sc) % mod);
}

li sum (int idx, int lf, int rg, int l, int r, int k)
{
    if (lf == l && rg == r)
        return li((t[idx].ft * 1LL * f[k] + t[idx].sc * 1LL * f[k + 1]) % mod);
        
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (r <= mid) return sum(2 * idx + 1, lf, mid, l, r, k);
    if (mid < l) return sum(2 * idx + 2, mid + 1, rg, l, r, k);
    
    li res = sum(2 * idx + 1, lf, mid, l, mid, k);
    res = (res + sum(2 * idx + 2, mid + 1, rg, mid + 1, r, k + mid - l + 1)) % mod;

    return res; 
}

inline void solve()
{
    forn(i, n) upd(0, 0, n - 1, i, a[i]);
    
    //forn(i, n) cerr << sum(0, 0, n - 1, i, i, 1) << ' '; cerr << endl;
    
    /*forn(i, n)
    {
        fore(j, i, n - 1)
            cerr << sum(0, 0, n - 1, i, j, 1) << ' ';
        cerr << endl;
    }*/
    
    forn(iter, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        if (type == 1)
        {
            int pos, val;
            assert(scanf("%d%d", &pos, &val) == 2);
            --pos;
            upd(0, 0, n - 1, pos, val);
            
        } else if (type == 2)
        {
            int lf, rg;
            assert(scanf("%d%d", &lf, &rg) == 2);
            --lf, --rg;
            printf("%I64d\n", sum(0, 0, n - 1, lf, rg, 1) % mod);
            
        } else if (type == 3)
        {
            int lf, rg, d;
            assert(scanf("%d%d%d", &lf, &rg, &d) == 3);
            --lf, --rg;
            inc(0, 0, n - 1, lf, rg, d);
            
        } else throw;
    }
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    f[1] = s[1] = 1;
    fore(i, 2, N - 1)
    {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
        s[i] = (s[i - 1] + f[i]) % mod;
    }
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}