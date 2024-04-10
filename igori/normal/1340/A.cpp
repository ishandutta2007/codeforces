const int N = 1405949; // 405949 is my favorite number, but it's less than 5e5
const int LG = 21;
const int MOD = 1e9 + 7;
const int INF = 1e9;

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>

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

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll inv(ll x)
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

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    forn(i, n) a[i]--;
    vector<int> pos(n);
    forn(i, n) pos[a[i]] = i;
    vector<int> ma(n);
    for (int i = 0; i < n; )
    {
        int P = pos[i];
        int val = i;
        while (ma[P] == 0)
        {
            if (a[P] != val)
            {
                cout << "No\n";
                return;
            }
            P++;
            val++;
            if (P == n) break;
        }
        ma[pos[i]] = 1;
        i = val;
    }
    cout << "Yes\n";
}

signed main()
{
    srand(time(NULL));
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}

/* Note:
Check constants at the beginning of the code.
N is set to 1.4e6 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/