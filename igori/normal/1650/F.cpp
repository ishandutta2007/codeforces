const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
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
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

ll log10(ll x)
{
    if (x < 10) re 1;
    re 1 + log10(x / 10);
}

ll ds(ll x)
{
    if (x < 10) return x;
    re x % 10 + ds(x / 10);
}

double sqr(double x)
{
    return x * x;
}

bool inmask(int bit, int mask)
{
    return (mask & (1 << bit)) > 0;
}

void Del(vector<int> &v, int pos)
{
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();
}

long long g(vector<long long> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

int g(vector<int> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

ll binpow(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = binpow(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return binpow(x, MOD - 2);
}

int __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

inline void __precompute_combinatorics(int __n)
{
    if (__precomputed_combinatorics >= __n)
        return;
    __fact.resize(__n);
    __ufact.resize(__n);
    __rev.resize(__n);
    __rev[1] = 1;
    for (int i = max(2, __precomputed_combinatorics); i < __n; i++)
        __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = max(1, __precomputed_combinatorics); i < __n; i++)
        __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
    __precomputed_combinatorics = __n;
}

ll fact(int x)
{
    if (__precomputed_combinatorics <= x)
        __precompute_combinatorics(x + 1);
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (__precomputed_combinatorics <= n)
        __precompute_combinatorics(n + 1);
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

struct prepare{
    ll t, p, id;
};

int dp[101000][201];
int table_prev[101000][201];

vector<prepare> compute(vector<prepare> Set)
{
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= Set.size(); j++)
        {
            dp[j][i] = INF;
            table_prev[j][i] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < Set.size(); i++)
    {
        for (int p = 199; p >= 0; p--)
        {
            if (dp[i][p] != INF)
            {
                if (dp[i][p] < dp[i + 1][p])
                    dp[i + 1][p] = dp[i][p],
                    table_prev[i + 1][p] = -1;

                if (p < 100 && dp[i][p] + Set[i].t < dp[i + 1][p + Set[i].p])
                    dp[i + 1][p + Set[i].p] = dp[i][p] + Set[i].t,
                    table_prev[i + 1][p + Set[i].p] = i;
            }
        }
    }
    vector<prepare> res;
    int fl = -1, lst = Set.size();
    int total = INF;
    for (int i = 100; i <= 200; i++)
    {
        if (dp[Set.size()][i] < total)
        {
            total = dp[Set.size()][i];
            fl = i;
        }
    }
    if (total == INF) return res;
    while (fl > 0)
    {
        int x = table_prev[lst][fl];
        //cout << x << endl;
        if (x != -1)
        {
            res.push_back(Set[x]);
            fl -= Set[x].p;
        }
        lst--;
        //cout << fl << " " << lst << endl;
    }
    return res;
}

void solve()
{
    #define tests

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];

    vector<vector<prepare> > prepare_sets(n);
    for (int i = 0; i < m; i++)
    {
        ll e, t, p;
        cin >> e >> t >> p;
        e--;
        prepare_sets[e].push_back({t, p, i});
    }

    vector<ll> tm(n);
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        vector<prepare> d = compute(prepare_sets[i]);
        if (d.size() == 0)
        {
            cout << -1 << "\n";
            return;
        }
        tm[i] = 0;
        for (auto e : d) tm[i] += e.t, ans.push_back(e.id);
        if (i) tm[i] += tm[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (tm[i] > a[i])
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans.size() << "\n";
    for (auto e : ans) cout << e + 1 << " "; cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}