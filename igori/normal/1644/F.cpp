const long long MOD = 998244353;
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
    if (__n < 2) __n = 2; // fact(0) in the beginning call can break something
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
    fft_runner F(20);
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << 1 << "\n";
        return;
    }
    fact(n + 1);

    int lc = n + 1, value = 0;
    vector<int> func(n + 1);
    for (int len = 1; len <= n; len++)
    {
        int blocks = (n + len - 1) / len;
        if (lc != blocks)
        {
            lc = blocks;
            value = 0;
            vector<int> a(blocks + 1), b(blocks + 1);
            for (int i = 0; i <= blocks; i++) a[i] = i % 2 == 0 ? __ufact[i] : MOD - __ufact[i];
            for (int i = 0; i <= blocks; i++) b[i] = inq(i, blocks, MOD) * __ufact[i] % MOD;
            vector<int> c = F.fft(a, b);
            for (int i = 0; i <= min(k, blocks); i++)
                value += c[i], value %= MOD;
        }
        //cout << len << " " << blocks << " " << value << "\n";
        func[len] = value;
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = 2 * i; j <= n; j += i)
            func[i] = (func[i] + MOD - func[j]) % MOD;
        if (n % i != 0)
            func[i] = (func[i] + MOD - func[n]) % MOD;
    }

    //for (int i = 1; i <= n; i++)
    //    cout << func[i] << " "; cout << "\n";
    cout << func[1] << "\n";
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