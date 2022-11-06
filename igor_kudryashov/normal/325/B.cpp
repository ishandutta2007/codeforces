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

li gcd (li a, li b) { return a == 0 ? b : gcd(b % a, a); }

inline li myRand()
{
    li ans = 0;
    
    forn(i, 4)
        ans <<= 16, ans ^= rand();
        
    return abs(ans);
}

li mul(li, li, li);

inline li binPow(li a, li b, li mod)
{
    li ans = 1;
    
    while (b)
    {
        if (b & 1) ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    
    return ans;
}

inline li mul(li a, li b, li mod)
{
    li q = li(ld(a) * b / mod);
    li ans = (a * b - q * mod) % mod;
    return ans < 0 ? ans + mod : ans;
}

inline bool isProbablePrime(li n, int cnt)
{
    if (n <= 1) return false;
    
    forn(t, cnt)
    {
        li a = myRand() % (n - 1) + 1;
        li b = n - 1;
        int cnt = 0;
        
        while (!(b & 1)) b >>= 1, cnt++;
        
        li ans = binPow(a, b, n);
        
        forn(i, cnt)
        {
            li next = mul(ans, ans, n);
            if (next == 1 && ans != 1 && ans != n - 1) return false;
            ans = next;
        }
        
        if (ans != 1) return false;
    }
    
    return true;
}

inline vector<li> pollard(li n)
{ // don't forget about srand :-)
    if (n == 1) return vector<li> (0);
    if (isProbablePrime(n, 13)) return vector<li> (1, n);
    
    for (li d = 2; d < 100; d++)
        if (n % d == 0)
        {
            vector<li> ans = pollard(d), rg = pollard(n / d);
            forn(i, sz(rg)) ans.pb(rg[i]);
            return ans;
        }
        
    const int M = 5;
    static li q[M], x[M], y[M];
    
    forn(i, M) q[i] = myRand() % n, x[i] = y[i] = 2;
    q[0] = 1;
    
    for (int i = 1, k = 1; ; i++)
    {
        forn(t, M)
        {
            li d = gcd(abs(y[t] - x[t]), n);
            
            if (d != 1 && d != n)
            {
                vector<li> ans = pollard(d), rg = pollard(n / d);
                forn(i, sz(rg)) ans.pb(rg[i]);
                return ans;
            }
            
            x[t] = (mul(x[t], x[t], n) + q[t]) % n;
            
            if (i == k) y[t] = x[t];
        }
        if (i == k) k *= 2;
    }
}

li n;
vector < pair <li, int> > fact;
vector <li> ans;

inline void checkAns (li x)
{
    if (x % 2 == 0) return;
    
    ld curx = ld(x) * (x - 1) / 2;
    if (curx > n + 1000) return;
    
    li games = x * (x - 1) / 2;
    li cur = x;
    
    while (games < n)
    {
        games += cur;
        cur *= 2;
    }
    
    if (games == n) ans.pb(cur);
}

void go (int idx, li x)
{
    if (idx == sz(fact))
    {
        checkAns(x);
        return;
    }
    
    li cur = 1;
    
    forn(i, fact[idx].sc + 1)
    {
        go(idx + 1, x * cur);
        cur *= fact[idx].ft;
    }
}

inline bool read()
{
    return cin >> n;
}

inline void solve()
{
    vector <li> f = pollard(n);
    
    sort(all(f));
    
    for (int i = 0; i < sz(f); )
    {
        int st = i;
        while (i < sz(f) && f[i] == f[st]) i++;
        fact.pb(mp(f[st], i - st));
    }
    
    go(0, 1);
    
    if (ans.empty())
        puts("-1");
    else
    {
        sort(all(ans));
        forn(i, sz(ans)) cout << ans[i] << endl;
    }
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