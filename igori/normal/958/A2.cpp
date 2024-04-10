const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = INF * INF;

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
    int n, m;
    cin >> n >> m;

    vector<string> s(n), t(m);
    cin >> s >> t;

    const ll P = 207007;
    const ll Q = 1000003;

    vector<vector<ll> > a(n + 1, vll(m + 1));
    vector<vector<ll> > b(m + 1, vll(n + 1));

    vector<ll> degp(n + m), degq(n + m);
    vector<ll> rdegp(n + m), rdegq(n + m);
    degp[0] = degq[0] = 1;
    rdegp[0] = rdegq[0] = 1;
    forn(i, n + m - 1) degp[i + 1] = 1ll * degp[i] * P % MOD;
    forn(i, n + m - 1) rdegp[i + 1] = 1ll * rdegp[i] * rev(P) % MOD;
    forn(i, n + m - 1) degq[i + 1] = 1ll * degq[i] * Q % MOD;
    forn(i, n + m - 1) rdegq[i + 1] = 1ll * rdegq[i] * rev(Q) % MOD;

    forn(i, n) forn(j, m) a[i + 1][j + 1] = 1ll * s[i][j] * degp[i] % MOD * degq[j] % MOD;
    forn(i, m) forn(j, n) b[i + 1][j + 1] = 1ll * t[i][j] * degp[i] % MOD * degq[j] % MOD;

    forn(i, n) forn(j, m) a[i + 1][j + 1] = (a[i + 1][j + 1] + a[i][j + 1] + a[i + 1][j] - a[i][j]) % MOD;
    forn(i, m) forn(j, n) b[i + 1][j + 1] = (b[i + 1][j + 1] + b[i][j + 1] + b[i + 1][j] - b[i][j]) % MOD;

    forn(i, n + 1) forn(j, m + 1) a[i][j] = (a[i][j] + MOD) % MOD;
    forn(i, m + 1) forn(j, n + 1) b[i][j] = (b[i][j] + MOD) % MOD;

    auto get = [&](vector<vll> &g, int x, int y)
    {
        ll val = g[x + m - 1][y + m - 1] - g[x - 1][y + m - 1] - g[x + m - 1][y - 1] + g[x - 1][y - 1];
        val = (val % MOD + MOD) % MOD;
        val = val * rdegp[x - 1] % MOD;
        val = val * rdegq[y - 1] % MOD;
        return val;
    };

    for (int i = 1; i + m - 1 <= n; i++)
    {
        for (int j = 1; j + m - 1 <= n; j++)
        {
            if (get(a, i, 1) == get(b, 1, j))
            {
                int yes = 1;
                forn(x, m) forn(y, m)
                {
                    if (!yes) break;
                    if (s[i + x - 1][y] != t[x][j + y - 1])
                        yes = 0;
                }
                if (yes)
                {
                    cout << i << " " << j << "\n";
                    return;
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
    #endif
    while (t--)
    {
        solve();
    }
}