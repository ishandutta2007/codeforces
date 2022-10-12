const long long MOD = 998244353;
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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector req(n, vector(n, 0));
    vector free(n, vector(n, 0));
    for (int len = 1; len <= n; len++)
    {
        for (int l = 0; l + len <= n; l++)
        {
            int r = l + len - 1;
            if (s[r] != '?' && s[l] != '?' && s[r] != s[l])
            {
                req[l][r] = -1;
                free[l][r] = -1;
                continue;
            }
            if (len >= 3 && req[l + 1][r - 1] == -1)
            {
                req[l][r] = -1;
                free[l][r] = -1;
                continue;
            }

            if (len >= 3)
            {
                req[l][r] = req[l + 1][r - 1];
                free[l][r] = free[l + 1][r - 1];
            }
            if (s[l] == '?' && s[r] == '?')
            {
                free[l][r]++;
            }
            if (s[l] == '?' && s[r] != '?')
            {
                req[l][r] |= (1 << (s[r] - 'a'));
            }
            if (s[l] != '?' && s[r] == '?')
            {
                req[l][r] |= (1 << (s[l] - 'a'));
            }
        }
    }

    vector<int> pref(n), suff(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?') pref[i] = 1, suff[i] = 1;
    }
    for (int i = 1; i < n; i++) pref[i] += pref[i - 1];
    for (int i = n - 2; i >= 0; i--) suff[i] += suff[i + 1];

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            if (l) free[l][r] += pref[l - 1];
            if (r + 1 < n) free[l][r] += suff[r + 1];
        }
    }

    vector<vector<int> > bpow(18, vector<int>(n + 1));
    for (int i = 1; i < 18; i++)
    {
        for (int j = 0; j <= n; j++)
            bpow[i][j] = binpow(i, j);
    }

    vector<vector<int> > sum(18, vector<int>(1 << 17));
    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            if (req[l][r] != -1)
            {
                for (int cnt = 1; cnt <= 17; cnt++)
                {
                    sum[cnt][req[l][r]] += bpow[cnt][free[l][r]];
                    if (sum[cnt][req[l][r]] >= MOD)
                        sum[cnt][req[l][r]] -= MOD;
                }
            }
        }
    }

    for (int q = 1; q < 18; q++)
    {
        for (int i = 0; i < 17; i++)
        {
            for (int j = 0; j < (1 << 17); j++)
            {
                if (j & (1 << i))
                {
                    sum[q][j] += sum[q][j - (1 << i)];
                    if (sum[q][j] >= MOD)
                        sum[q][j] -= MOD;
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int x = 0;
        for (auto e : s)
            x += (1 << (e - 'a'));

        cout << sum[popcount(x)][x] << "\n";
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