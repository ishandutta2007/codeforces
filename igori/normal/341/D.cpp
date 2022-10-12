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
    if (__n < 2) __n = 2;
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
    const int K = 1;
    int n, q;
    cin >> n >> q;

    vector f(2, vector(2, vector(n + 4, vll(n + 4))));

    auto apply = [&](int x, int y, long long val)
    {
        for (int i = x; i <= n; i |= (i + 1))
        {
            for (int j = y; j <= n; j |= (j + 1))
            {
                f[x % 2][y % 2][i][j] ^= val;
            }
        }
    };

    auto ask = [&](int x, int y)
    {
        ll res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            {
                res ^= f[x % 2][y % 2][i][j];
            }
        }
        return res;
    };

    for (int i = 0; i < q; i++)
    {
        int t, x0, y0, x1, y1;
        cin >> t >> x0 >> y0 >> x1 >> y1;
        if (t == 2)
        {
            long long v;
            cin >> v;
            apply(x0, y0, v);
            apply(x0, y1 + 1, v);
            apply(x1 + 1, y0, v);
            apply(x1 + 1, y1 + 1, v);
        }
        else
        {
            long long res = ask(x1, y1) ^ ask(x1, y0 - 1) ^ ask(x0 - 1, y1) ^ ask(x0 - 1, y0 - 1);
            cout << res << "\n";
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