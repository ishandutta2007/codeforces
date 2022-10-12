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

struct fft_runner{
    // Computes the product of two polynomials modulo 998244353
    // Change G for other modules.
    //
    // Correctness tested on the following problem:
    // https://codeforces.com/contest/1473/problem/G
    //
    const int G = 3;
    const int G_REV = binpow(G, MOD - 2);
    vector<vector<vector<int> > > wes;
    int bitreverse(int x, int lg)
    {
        int y = 0;
        for (int i = 0; i < lg; i++)
        {
            y = 2 * y + (((1 << i) & x) > 0);
        }
        return y;
    }
    vector<int> dft(vector<int> a, int fl, int lg)
    {
        for (int i = 0; i < (int)a.size(); i++)
        {
            int j = bitreverse(i, lg);
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2, io = 1; len <= (int)a.size(); len <<= 1, io++)
        {
            for (int i = 0; i < (int)a.size(); i += len)
            {
                for (int j = 0; j < len / 2; j++)
                {
                    int v = a[i + j], u = 1ll * a[i + j + len / 2] * wes[fl == 1 ? 1 : 0][io][j] % MOD;
                    a[i + j] = v + u >= MOD ? v + u - MOD : v + u;
                    a[i + j + len / 2] = v - u < 0 ? v - u + MOD : v - u;
                }
            }
        }
        return a;
    }

    void simulate_dft(int lg, int fl)
    {
        for (int len = 2, io = 1; len <= (1 << lg); len <<= 1, io++)
        {
            ll wlen = fl == 1 ? G : G_REV;
            wlen = binpow(wlen, (MOD - 1) / len);
            ll w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                wes[fl == 1 ? 1 : 0][io][j] = w;
                w = w * wlen % MOD;
            }
        }
    }

    vector<int> fft(vector<int> &a, vector<int> &b)
    {
        if (max(a.size(), b.size()) <= 1000)
        {
            vector<int> c(a.size() + b.size() - 1);
            for (int i = 0; i < (int)a.size(); i++)
            {
                for (int j = 0; j < (int)b.size(); j++)
                {
                    c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % MOD;
                }
            }
            return c;
        }
        ll sz = a.size() + b.size() - 1;
        ll dg = 1, z = 0;
        while (dg < sz)
            dg *= 2, z++;
        vector<int> a0(dg), b0(dg);
        for (int i = 0; i < (int)a.size(); i++)
            a0[i] = a[i];
        for (int i = 0; i < (int)b.size(); i++)
            b0[i] = b[i];
        a0 = dft(a0, 1, z);
        b0 = dft(b0, 1, z);
        for (int i = 0; i < (int)a0.size(); i++)
            a0[i] = 1ll * a0[i] * b0[i] % MOD;
        a0 = dft(a0, -1, z);
        int x = binpow(dg, MOD - 2) % MOD;
        for (int i = 0; i < (int)a0.size(); i++)
            a0[i] = 1ll * a0[i] * x % MOD;
        while ((int)a0.size() != sz)
            a0.pop_back();
        return a0;
    }

    fft_runner(int lg)
    {
        wes = vector<vector<vector<int> > >(2, vector<vector<int> >(lg + 1, vector<int>(1 << (lg - 1))));
        simulate_dft(lg, 1);
        simulate_dft(lg, -1);
    }
};

void solve()
{
    int n, k, f;
    cin >> n >> k >> f;

    if (f > 2 * k)
    {
        cout << 0 << "\n";
        return;
    }

    vector<int> comp(2 * k + 1);
    comp[2 * k] = 1;

    fft_runner run(19);

    for (int j = 1; j <= n; j++)
    {
        for (int a = 2 * k - 1; a >= 0; a--) comp[a] = (comp[a] + comp[a + 1]) % MOD;
        vector<int> with_mn(2 * k + 1);
        for (int val = 0; val <= k; val++)
        {
            with_mn[val] = (comp[val + 1] + 1ll * (comp[val] - (val + 1 <= 2 * k ? comp[val + 1] : 0)) * max(0, k - val + 1)) % MOD;
            with_mn[val] = (with_mn[val] + MOD) % MOD;
        }
        with_mn.resize(k + 1);
        comp = run.fft(with_mn, with_mn);
    }

    cout << comp[f] << "\n";
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