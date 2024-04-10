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

li mod, L, R, k;

inline bool read()
{
    return cin >> mod >> L >> R >> k;
}

typedef int matr[2][2];

inline li calc (li x, li R)
{
    return R / x + 1;
}

inline bool check (li x)
{
    if (x == 0) return false;
    return (calc(x, R) - calc(x, L - 1)) >= k;
}

void mul (matr a, matr b)
{
    matr c;
    
    forn(i, 2)
        forn(j, 2)
        {
            li cur = 0;
            forn(k, 2) cur += a[i][k] * 1LL * b[k][j];
            c[i][j] = cur % mod;
        }
        
    forn(i, 2) forn(j, 2) a[i][j] = c[i][j];
}

inline void binPow (matr a, li b)
{
    matr res;
    forn(i, 2) forn(j, 2) res[i][j] = (i == j);
    
    while (b)
    {
        if (b & 1) mul(res, a);
        b >>= 1;
        mul(a, a);
    }
    forn(i, 2) forn(j, 2) a[i][j] = res[i][j];
}

inline void solve()
{
    li ans = 0;
    
    for (li x = 1; x <= 1000 * 1000; x++)
    {
        if (check(x)) ans = max(ans, x);
        if (check(R / x)) ans = max(ans, R / x);
    }
    
    cerr << ans << endl;
    
    if (ans <= 2)
    {
        cout << 1 % mod << endl;
        return;
    }
    
    matr a;
    a[0][0] = a[0][1] = a[1][0] = 1, a[1][1] = 0;
    
    binPow(a, ans - 2);
    
    cout << (a[0][0] + a[0][1]) % mod << endl;  
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