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

int solve(vector<int> in)
{
    if (in.size() == 1)
        return 1;
    int n = in.size();

    vector<int> divisor(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (divisor[i] == 0)
        {
            for (int j = i; j <= n; j += i)
            {
                divisor[j] = i;
            }
        }
    }

    vector<vector<int> > groups(n + 1);
    groups[1].push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (divisor[i] == i && 1ll * i * i > n)
        {
            groups[n / i].push_back(i);
        }
    }

    #ifdef LOCAL
    for (int i = 1; i <= n; i++)
    {
        if (groups[i].size())
        {
            cout << i << " : ";
            for (auto e : groups[i]) cout << e << " ";
            cout << "\n";
        }
    }
    cout << endl;

    for (int i = 1; i <= n; i++) cout << divisor[i] << " "; cout << "\n";
    #endif // LOCAL

    vector<int> p(n);
    iota(all(p), 1);
    for (int i = 1; i <= n; i++)
    {
        vector<int> v;
        int x = i;
        while (x > 1)
        {
            v.push_back(divisor[x]);
            x /= divisor[x];
        }
        uniq(v);
        p[i - 1] = 1;
        for (auto e : v) p[i - 1] *= e;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto e : groups[i])
        {
            for (int j = e; j <= e * i; j += e)
                p[j - 1] = 0;
        }
    }
    #ifdef LOCAL
    for (auto e : p) cout << e << " ";
    cout << endl << endl;
    #endif // LOCAL

    int ans_small = 1;
    int ans_big = 1;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
        if (p[i]) cnt[p[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (in[i] != 0 && p[in[i] - 1] != 0)
        {
            int x = p[in[i] - 1];
            if (p[i] != x)
                ans_small = 0;
            else
                cnt[p[i]]--;
        }
    }

    for (int i = 1; i <= n; i++)
        ans_small = ans_small * fact(cnt[i]) % MOD;

    vector<int> g_size(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto e : groups[i])
        {
            g_size[e] = i;
        }
    }

    p[0] = 1;
    divisor[1] = 1;
    vector<int> jj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int offers = groups[i].size();
        for (auto e : groups[i])
        {
            int sep = -1;
            map<int, int> mm;
            for (int j = 1; j <= i; j++)
            {
                int iot = j * e;
                int x = in[iot - 1];
                mm[p[j - 1]]++;
                if (x != 0)
                {
                    int kek = divisor[x];
                    if (sep != -1 && sep != kek)
                        ans_big = 0;
                    sep = kek;

                    int pj = p[j - 1];
                    int pkek = p[x / kek - 1];
                    if (pj != pkek)
                        ans_big = 0;
                    mm[pj]--;
                }
            }
            if (sep != -1)
                offers--, jj[sep]++;
            if (sep != -1 && g_size[sep] != i)
                ans_big = 0;
            for (auto e : mm)
                ans_big = 1ll * ans_big * fact(e.second) % MOD;
        }
        //cerr << i << " " << offers << "\n";
        ans_big = ans_big * fact(offers) % MOD;
    }
    if (*max_element(all(jj)) > 1)
        ans_big = 0;
    dbg(ans_big);
    dbg(ans_small);
    return 1ll * ans_small * ans_big % MOD;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    cout << solve(a) << "\n";
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