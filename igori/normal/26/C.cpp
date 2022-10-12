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
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    if (n % 2 == 1 && m % 2 == 1)
    {
        cout << POSSIBLE[0];
        return;
    }
    if (m % 2 == 1)
    {
        int cnt = n / 2;
        if (b < cnt)
        {
            cout << POSSIBLE[0];
            return;
        }
        b -= cnt;
    }
    if (n % 2 == 1)
    {
        int cnt = m / 2;
        if (a < cnt)
        {
            cout << POSSIBLE[0];
            return;
        }
        a -= cnt;
    }

    int f = c + a / 2 + b / 2;
    if ((n / 2) * (m / 2) > f)
    {
        cout << POSSIBLE[0];
        return;
    }

    vector<string> s(n, string(m, '.'));
    for (int i = 0; i + 1 < n; i += 2)
    {
        for (int j = 0; j + 1 < m; j += 2)
        {
            if (c)
            {
                s[i][j] = 'a' + (i % 5) * 5 + (j % 5);
                s[i][j + 1] = 'a' + (i % 5) * 5 + (j % 5);
                s[i + 1][j] = 'a' + (i % 5) * 5 + (j % 5);
                s[i + 1][j + 1] = 'a' + (i % 5) * 5 + (j % 5);
                c--;
            }
            else if (a >= 2)
            {
                s[i][j] = 'a' + (i % 5) * 5 + (j % 5);
                s[i][j + 1] = 'a' + (i % 5) * 5 + (j % 5);
                s[i + 1][j] = 'a' + ((i + 1) % 5) * 5 + (j % 5);
                s[i + 1][j + 1] = 'a' + ((i + 1) % 5) * 5 + (j % 5);
                a -= 2;
            }
            else if (b >= 2)
            {
                s[i][j] = 'a' + (i % 5) * 5 + (j % 5);
                s[i + 1][j] = 'a' + (i % 5) * 5 + (j % 5);
                s[i][j + 1] = 'a' + (i % 5) * 5 + ((j + 1) % 5);
                s[i + 1][j + 1] = 'a' + (i % 5) * 5 + ((j + 1) % 5);
                b -= 2;
            }
        }
    }
    if (n % 2 == 1)
    {
        for (int j = 0; j + 1 < m; j += 2)
        {
            s[n - 1][j] = 'a' + ((n - 1) % 5) * 5 + (j % 5);
            s[n - 1][j + 1] = 'a' + ((n - 1) % 5) * 5 + (j % 5);
        }
    }
    if (m % 2 == 1)
    {
        for (int i = 0; i + 1 < n; i += 2)
        {
            s[i][m - 1] = 'a' + (i % 5) * 5 + ((m - 1) % 5);
            s[i + 1][m - 1] = 'a' + (i % 5) * 5 + ((m - 1) % 5);
        }
    }
    cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}