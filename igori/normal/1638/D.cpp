const long long MOD = 1e9 + 7;
const long long INF = 1e9;
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

int ok(int x, int n)
{
    return 0 <= x && x < n;
}

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

ll inq(ll x, ll y, ll mod)
{
    if (y == 0) return 1 % mod;
    ll l = inq(x, y / 2, mod);
    if (y % 2) return l * l % mod * x % mod;
    return l * l % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vvi used(n, vi(m));
    forn(i, n) forn(j, m) cin >> a[i][j];

    auto is_valid = [&](int i, int j) {
        if (i < 0 || j < 0 || i + 1 >= n || j + 1 >= m) return 0;
        int c = max({a[i][j], a[i + 1][j], a[i][j + 1], a[i + 1][j + 1]});
        if (c == 0) return 0;
        if (a[i][j] != 0 && a[i][j] != c) return 0;
        if (a[i + 1][j] != 0 && a[i + 1][j] != c) return 0;
        if (a[i][j + 1] != 0 && a[i][j + 1] != c) return 0;
        if (a[i + 1][j + 1] != 0 && a[i + 1][j + 1] != c) return 0;
        return c;
    };
    vector<pair<int, int> > ex;
    struct item{
        int i, j, k;
    };
    vector<item> ans;

    forn(i, n) forn(j, m) if (is_valid(i, j)) ex.push_back({i, j});
    for (int i = 0; i < ex.size(); i++)
    {
        int ni = ex[i].first, nj = ex[i].second;
        if (used[ni][nj] == 2) continue;
        if (is_valid(ni, nj)) ans.push_back({ni, nj, is_valid(ni, nj)});
        used[ni][nj] = 2;
        a[ni][nj] = a[ni][nj + 1] = a[ni + 1][nj] = a[ni + 1][nj + 1] = 0;
        for (int x = ni - 1; x <= ni + 1; x++)
        {
            for (int y = nj - 1; y <= nj + 1; y++)
            {
                if (is_valid(x, y) && !used[x][y]) ex.push_back({x, y}), used[x][y] = 1;
            }
        }
    }
    forn(i, n) forn(j, m)
    {
        if (a[i][j] != 0)
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << ans.size() << "\n";
    reverse(all(ans));
    for (auto e : ans) cout << e.i + 1 << " " << e.j + 1 << " " << e.k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}