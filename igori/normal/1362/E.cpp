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

const int N = 1000050;
int TEST = 0;
vector<int> TOUCHED;

struct cover{
    vector<int> a;
    vector<int> b;

    cover()
    {
        a.resize(N), b.resize(N);
    }

    void set(int pos, int x)
    {
        a[pos] = x;
        b[pos] = TEST;
        TOUCHED.push_back(pos);
    }
    int get(int pos)
    {
        if (b[pos] != TEST)
        {
            b[pos] = TEST;
            a[pos] = 0;
            return 0;
        }
        return a[pos];
    }
};

vector<cover> a(2);

void solve()
{
    TEST++;
    TOUCHED.resize(0);

    #define tests

    int n, p;
    cin >> n >> p;
    vi k(n);
    cin >> k;
    if (p == 1)
    {
        cout << n % 2 << "\n";
        re;
    }

    sort(rall(k));

    int fix = 0;
    for (int i = 0; i < n; i++)
    {
        a[0].set(k[i], a[0].get(k[i]) + 1);
        int id = k[i];
        while (a[0].get(id) == p)
        {
            a[0].set(id, 0);
            a[0].set(id + 1, a[0].get(id + 1) + 1);
            id++;
        }

        int sw = 0;
        int pos = -1;
        for (int j = k[i] + 40; j >= k[i]; j--)
        {
            if (a[0].get(j) > a[1].get(j))
            {
                sw = 1;
                pos = j;
                break;
            }
            if (a[0].get(j) < a[1].get(j))
            {
                pos = j;
                break;
            }
        }

        if (!fix && sw) swap(a[0], a[1]);
        if (pos != -1 && i + 1 < n && pos > k[i + 1] + 40)
            fix = 1;
    }

    int ans = 0;
    uniq(TOUCHED);
    for (auto e : TOUCHED)
    {
        //cout << e << " " << a[0].get(e) << " " << a[1].get(e) << "\n";
        ans += (binpow(p, e) * (a[1].get(e) - a[0].get(e))) % MOD;
        ans %= MOD;
    }
    cout << (ans + MOD) % MOD << "\n";
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