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

const int mod = 1000 * 1000 * 1000 + 7;

int w, h;

inline bool read()
{
    return cin >> w >> h;
}

int naive ()
{
    int cur = 0;
    forn(ax, w + 1) forn(ay, h + 1)
    forn(bx, w + 1) forn(by, h + 1)
    forn(cx, w + 1) forn(cy, h + 1)
    {
        int s = abs((cx - ax) * (by - ay) - (cy - ay) * (bx - ax));
        if (s > 0 && (s & 1) == 0) cur++;   
    }
    return cur;
}

int gcd (int a, int b) { return a == 0 ? b : gcd(b % a, a); }

inline void solve()
{
    int ans = 0;
    
    forn(ax, 2) forn(ay, 2)
    forn(bx, 2) forn(by, 2)
    forn(cx, 2) forn(cy, 2)
    {
        int s = (cx - ax) * (by - ay) - (cy - ay) * (bx - ax);
        if (abs(s) % 2 == 1) continue;
        
        int a[] = {(w + 2 - ax) / 2, (h + 2 - ay) / 2, (w + 2 - bx) / 2, (h + 2 - by) / 2, (w + 2 - cx) / 2, (h + 2 - cy) / 2 };
        
        int cur = 1;
        
        forn(i, 6) cur = (cur * 1LL * a[i]) % mod;
        
        /*if (cur > 0)
        {
            cerr << cur << ": ";
            forn(i, 6) cerr << a[i] << ' ';
            cerr << endl;
        }*/
        
        ans += cur;
        if (ans >= mod) ans -= mod;
    }
    
    /*cerr << ans << endl;
    
    {
        int cur = 0;
        
        forn(ax, w + 1) forn(ay, h + 1)
        forn(bx, w + 1) forn(by, h + 1)
        forn(cx, w + 1) forn(cy, h + 1)
        {
            int s = (cx - ax) * (by - ay) - (cy - ay) * (bx - ax);
            if (abs(s) % 2 == 0) cur++;         
        }
        cerr << cur << endl;
        assert(cur == ans);
    }*/
    
    int total = (w + 1) * (h + 1);
    
    int sub0 = (3LL * (total * 1LL * (total - 1))) % mod;
    ans -= sub0;
    if (ans < 0) ans += mod;
    
    int sub1 = total;
    ans -= sub1;
    if (ans < 0) ans += mod;
    
    int sub2 = (li(h + 1) * li(w + 1) * li(w) * li(w - 1)) % mod;
    ans -= sub2;
    if (ans < 0) ans += mod;
    
    int sub3 = ((w + 1) * 1LL * (h + 1) * h * (h - 1)) % mod;
    ans -= sub3;
    if (ans < 0) ans += mod;
    
    int sub4 = 0;
    
    forl(dx, w)
        forl(dy, h)
        {
            int g = gcd(dx, dy);
            
            int cur = ((w - dx + 1) * 1LL * (h - dy + 1)) % mod;
            cur = (cur * 1LL * (g - 1)) % mod;
            
            sub4 += cur;
            if (sub4 >= mod) sub4 -= mod;
        }
        
    sub4 = (sub4 * 12LL) % mod;
    
    ans -= sub4;
    if (ans < 0) ans += mod;
    
    cout << ans << endl;
    
    //int t = naive();
    //cerr << ans << ' ' << t << endl;
    /*if (ans != t)
    {
        cerr << w << ' ' << h << endl;
        cerr << ans << ' ' << t << endl;
        throw;
    }*/
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    /*const int M = 10;
    int test = 0;
    
    while (true)
    {
        if (++test % 100 == 0) cerr << test << endl;
        
        w = rand() % M + 1;
        h = rand() % M + 1;
        solve();
    }*/
    
    return 0;
}