const int N = 1e6 + 3;
const int LG = 21;
const long long MOD = 1e6 + 3;
const long long INF = 1e9;

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <bitset>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
}

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(N);
    __ufact.resize(N);
    __rev.resize(N);
    __rev[1] = 1;
    for (int i = 2; i < N; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < N; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

void __fast_IO()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
}

//##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**
//##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**

ll table[11][MOD];

ll a[20][20];
ll c[20];

signed main()
{
    for (int i = 0; i < MOD; i++)
    {
        table[0][i] = 1;
        for (int j = 1; j < 11; j++) table[j][i] = table[j - 1][i] * i % MOD;
    }
    for (int i = 2; i <= 12; i++)
    {
        cout << "? " << i << endl;
        //c[i - 2] = (i * i + 1000002) % MOD;
        cin >> c[i - 2];
        if (c[i - 2] == 0)
        {
            cout << "! " << i << endl;
            return 0;
        }
    }
    for (int i = 2; i <= 12; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            a[i - 2][j] = table[j][i];
        }
    }
    for (int i = 0; i < 11; i++)
    {
        int x = a[i][i];
        ll mp = rev(x);
        for (int j = 0; j < 11; j++) a[i][j] = a[i][j] * mp % MOD;
        c[i] = c[i] * mp % MOD;
        for (int k = i + 1; k < 11; k++)
        {
            ll cnt = a[k][i];
            for (int j = 0; j < 11; j++)
            {
                a[k][j] = (a[k][j] - cnt * a[i][j] + MOD * MOD) % MOD;
            }
            c[k] = (c[k] - cnt * c[i] + MOD * MOD) % MOD;
        }
    }
    for (int i = 10; i >= 0; i--)
    {
        int x = a[i][i];
        ll mp = rev(x);
        for (int j = 0; j < 11; j++) a[i][j] = a[i][j] * mp % MOD;
        c[i] = c[i] * mp % MOD;
        for (int k = 0; k < i; k++)
        {
            ll cnt = a[k][i];
            for (int j = 0; j < 11; j++)
            {
                a[k][j] = (a[k][j] - cnt * a[i][j] + MOD * MOD) % MOD;
            }
            c[k] = (c[k] - cnt * c[i] + MOD * MOD) % MOD;
        }
    }
    #ifdef LOCAL
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++) cout << a[i][j] << " ";
        cout << c[i] << endl;
    }
    #endif // LOCAL
    for (int ch = 0; ch < MOD; ch++)
    {
        ll x = 0;
        for (int j = 0; j < 11; j++) x = (x + table[j][ch] * c[j]) % MOD;
        if (x == 0)
        {
            cout << "! " << ch << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
}

/* Note:
Check constants at the beginning of the code.
N is set to 4e5 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/