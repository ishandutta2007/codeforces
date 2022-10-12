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

//......

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];

    if (k == 0)
    {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) cout << i << " ";
        return;
    }

    #ifdef LOCAL
    {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int ok = 1;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if ((a[i] ^ a[j]) < k && inmask(i, mask) && inmask(j, mask))
                        ok = 0;
            if (ok == 1)
                ans = max(ans, popcount(mask));
        }
        cout << ans << "\n";
    }
    #endif

    int tr = 1;
    while (tr <= k)
    {
        tr *= 2;
    }

    cerr << tr << "\n";

    map<int, vector<pair<int, int> > > mm;
    for (int i = 0; i < n; i++)
    {
        mm[a[i] / tr].push_back({a[i] % tr, i});
    }

    vector<int> res;

    for (auto e : mm)
    {
        vector<array<int, 2> > tree;
        tree.push_back({0, 0});

        for (auto f : e.second)
        {
            int pnt = 0;
            int x = f.first;
            for (int j = 30; j >= 0; j--)
            {
                int fl = (x & (1 << j)) > 0;
                if (tree[pnt][fl] == 0)
                {
                    tree[pnt][fl] = tree.size();
                    tree.push_back({0, 0});
                }
                pnt = tree[pnt][fl];
            }
        }

        int S = 0;
        for (auto f : e.second)
        {
            int ok = 0;
            int pnt = 0;
            int x = f.first;
            //cout << x << "\n";
            for (int j = 30; j >= 0; j--)
            {
                int fl = (x & (1 << j)) > 0;
                if ((k & (1 << j)) == 0)
                {
                    if (tree[pnt][1 ^ fl] != 0)
                    {
                        ok = 1;
                        break;
                    }
                    pnt = tree[pnt][fl];
                }
                if ((k & (1 << j)) != 0)
                {
                    if (tree[pnt][1 ^ fl] != 0)
                        pnt = tree[pnt][1 ^ fl];
                    else
                    {
                        ok = -1;
                        break;
                    }
                }
            }
            if (ok != -1)
                ok = 1;

            //cout << x << " ok = " << ok << "\n";
            //cout << k << "\n";

            if (ok == 1)
            {
                S = 1;
                for (auto g : e.second)
                {
                    if ((f.first ^ g.first) >= k && f.second != g.second)
                    {
                        //cout << k << " " << (f.first ^ g.first) << "\n";
                        res.push_back(f.second);
                        res.push_back(g.second);
                        break;
                    }
                }
                break;
            }
        }
        if (S == 0)
        {
            res.push_back(e.second[0].second);
        }
    }

    if (res.size() >= 2)
    {
        cout << res.size() << "\n";
        for (auto e : res) cout << e + 1 << " ";
    }
    else
    {
        cout << -1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}