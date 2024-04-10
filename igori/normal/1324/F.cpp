const int N = 405949; // 405949 is my favorite number, but it's less than 5e5
const int LG = 20;
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

int n;
int a[N];
vector<int> graph[N];
int par[N];

int dp[N];
int dpup[N];
int sigma[N];

void dfs1(int v, int p)
{
    par[v] = p;
    dp[v] = a[v];
    for (auto u : graph[v]) if (u != p)
    {
        dfs1(u, v);
        dp[v] += dp[u];
        sigma[v] += dp[u];
    }
    if (dp[v] < 0) dp[v] = 0;
}

void dfs2(int v, int p)
{
    if (p != 0)
    {
        int si = sigma[p] - dp[v] + a[p] + dpup[p];
        dpup[v] = si;
        if (dpup[v] < 0) dpup[v] = 0;
    }
    for (auto u : graph[v]) if (u != p)
    {
        dfs2(u, v);
    }
}

signed main()
{
    srand(time(NULL));
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) a[i] -= 1;
    }
    for (int i = 1, c, d; i < n; i++)
    {
        cin >> c >> d;
        graph[c].push_back(d);
        graph[d].push_back(c);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int ans = a[i];
        for (auto u : graph[i])
        {
            if (u == par[i]) ans += dpup[i];
            else ans += dp[u];
        }
        cout << ans;
        int x = rand() % 10 + 1, y = rand() % 2;
        forn(j, x) cout << " ";
        forn(j, y) cout << "\n";
    }
}

/* Note:
Check constants at the beginning of the code.
Check corner cases.
*/