const int N = 208001;
const int LG = 21;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

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

#define int long long
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    int t = 0;
    forn(i, n) if (a[i] == k) t = 1;
    if (!t)
    {
        cout << "No\n";
        return;
    }
    if (n == 1)
    {
        cout << "Yes\n";
        return;
    }
    t = 0;
    forn(i, n)
    {
        if (a[i] >= k)
        {
            if (i - 1 >= 0 && a[i - 1] >= k) t = 1;
            if (i + 1 < n && a[i + 1] >= k) t = 1;
        }
    }
    forn(i, n - 2)
    {
        if (a[i] >= k && a[i + 2] >= k) t = 1;
    }
    if (t)
    {
        cout << "yes\n";
        return;
    }
    // Simple cases upper
    for (int i = 0; i < n; i++)
    {
        if (a[i] < k) a[i] = -1;
        else a[i] = 1;
    }
    // Can perform some operations before
    // if have any 1 can do

    forn(i, n) if (a[i] == 0) a[i] = 1;
    // We want summ > 0

    int maxsumm = 0, minpref = INF;
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];

    forn(i, n)
    {
        if (i > 1) minpref = min(minpref, pref[i - 2]);
        maxsumm = max(maxsumm, pref[i] - minpref);
    }

    if (maxsumm > 0)
    {
        cout << "yEs\n";
    }
    else
    {
        cout << "nO\n";
    }
}

signed main()
{
    srand(time(NULL));
    //#ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    //#endif // ONLINE_JUDGE
    int t = 1;
    cin >> t;
    for (int _ = 1; _ <= t; _++)
    {
        //cout << "Case #" << _ << ": ";
        solve();
    }
}

/* Note:
Check constants at the beginning of the code.
N is set to 4e5 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/