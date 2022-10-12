const long long MOD = 1e9 + 9;
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
#define dbg(x) cerr << __LINE__ << " " << #x << " " << (x) << endl
#define ln cerr << __LINE__ << " fine, thanks" << endl
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

ll binpow(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = binpow(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

#define inq binpow

ll rev(ll x)
{
    return binpow(x, MOD - 2);
}

int _comb_precomputed_combinatorics = 0;
vector<ll> _comb_fact, _comb_ufact, _comb_rev;

inline void _comb_precompute_combinatorics(int _comb_n)
{
    if (_comb_n < 2) _comb_n = 2;
    if (_comb_precomputed_combinatorics >= _comb_n)
        return;
    _comb_fact.resize(_comb_n);
    _comb_ufact.resize(_comb_n);
    _comb_rev.resize(_comb_n);
    _comb_rev[1] = 1;
    for (int i = max(2, _comb_precomputed_combinatorics); i < _comb_n; i++)
        _comb_rev[i] = MOD - _comb_rev[MOD % i] * (MOD / i) % MOD;
    _comb_fact[0] = 1, _comb_ufact[0] = 1;
    for (int i = max(1, _comb_precomputed_combinatorics); i < _comb_n; i++)
        _comb_fact[i] = _comb_fact[i - 1] * i % MOD, _comb_ufact[i] = _comb_ufact[i - 1] * _comb_rev[i] % MOD;
    _comb_precomputed_combinatorics = _comb_n;
}

ll fact(int x)
{
    if (_comb_precomputed_combinatorics <= x)
        _comb_precompute_combinatorics(x + 1);
    return _comb_fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (_comb_precomputed_combinatorics <= n)
        _comb_precompute_combinatorics(n + 1);
    return _comb_fact[n] * _comb_ufact[n - k] % MOD * _comb_ufact[k] % MOD;
}

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

void solve()
{
    int xs, ys;
    int n;
    cin >> xs >> ys >> n;
    vi x(n), y(n);
    forn(i, n) cin >> x[i] >> y[i];

    auto dist = [&](int x1, int y1, int x2, int y2)
    {
        auto sqr = [&](int x)
        {
            return x * x;
        };
        return sqr(x1 - x2) + sqr(y1 - y2);
    };

    vi dp(1 << n, INF);
    dp[0] = 0;
    forn(mask, (1 << n))
    {
        forn(i, n)
        {
            if (withBit(mask, i)) continue;
            forn(j, n)
            {
                if (withBit(mask, j)) continue;
                int nmask = mask | (1 << i) | (1 << j);
                dp[nmask] = min(dp[nmask], dp[mask] +
                                dist(xs, ys, x[i], y[i]) +
                                dist(x[i], y[i], x[j], y[j]) +
                                dist(x[j], y[j], xs, ys)
                                );
            }
            break;
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
    cout << 0 << " ";
    int mask = (1 << n) - 1;
    while (mask > 0)
    {
        int go = -1;
        forn(i, n) forn(j, n)
        {
            if (go != -1) break;
            if (withBit(mask, i) && withBit(mask, j))
            {
                int prev = mask - (1 << i) - (1 << j) + (i == j) * (1 << i);
                if (dp[prev] + dist(xs, ys, x[i], y[i]) + dist(x[i], y[i], x[j], y[j]) + dist(x[j], y[j], xs, ys) == dp[mask])
                {
                    mask = prev;
                    go = 0;
                    cout << i + 1 << " ";
                    if (j != i) cout << j + 1 << " ";
                    cout << 0 << " ";
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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