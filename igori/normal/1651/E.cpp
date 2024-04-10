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

ll quely(int l, int r)
{
    return 1ll * (r - l + 1) * (r - l + 2) / 2;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int> > g(2 * n);
    forn(i, 2 * n)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }

    vector<int> vis(2 * n);
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            int prev = i;
            int u = g[i][0];
            vector<int> path = {i};
            while (u != i)
            {
                vis[u] = 1;
                path.push_back(u);
                int x = g[u][0] + g[u][1] - prev;
                prev = u;
                u = x;
            }
            int sz = path.size();
            for (int j = 0; j < sz; j++)
                path.push_back(path[j]);

            //for (auto e : path) cout << e << " "; cout << endl;

            struct cutters{
                vector<int> nxt, pr;
                int n;
                cutters(int _n)
                {
                    n = _n;
                    nxt = vector<int>(n + 2);
                    pr = vector<int>(n + 2);
                    iota(all(nxt), 1);
                    iota(all(pr), -1);
                }
                ll get()
                {
                    return (n + 1 - pr[n + 1]) * (nxt[0] - 0);
                }
                ll get(int x)
                {
                    x++;
                    if (pr[x] == 0 && nxt[x] == n + 1) return 0;
                    if (pr[x] == 0) return (nxt[x] - x) * (n + 1 - pr[n + 1]);
                    if (nxt[x] == n + 1) return (x - pr[x]) * (nxt[0] - 0);
                    return 0;
                }
                ll get(int x, int y)
                {
                    x++, y++;
                    if (nxt[x] == y && nxt[y] == n + 1) return (x - pr[x]) * (nxt[0] - 0);
                    if (pr[x] == 0 && nxt[y] == n + 1) return (y - pr[y]) * (nxt[x] - x);
                    if (pr[x] == 0 && pr[y] == x) return (n + 1 - pr[n + 1]) * (nxt[y] - y);
                    return 0;
                }
                void remove(int x)
                {
                    x++;
                    int LL = pr[x], RR = nxt[x];
                    nxt[LL] = RR;
                    pr[RR] = LL;
                }
            };
            cutters left_base(n), right_base(n);

            vector<int> have(2 * n);
            for (auto e : path) have[e] = 1;
            for (int i = 0; i < 2 * n; i++) if (!have[i])
            {
                if (i < n) left_base.remove(i);
                else right_base.remove(i - n);
            }

            ans += 1ll * sz / 2 * left_base.get() * right_base.get();

            //cout << left_base.get() << " " << right_base.get() << endl;

            for (int L = 0; L < sz; L++)
            {
                cutters left = left_base;
                cutters right = right_base;
                ll pans = ans;
                if (path[L] < n) ans += 1ll * (sz / 2 - 1) * left.get(path[L]) * right.get();
                else ans += 1ll * (sz / 2 - 1) * right.get(path[L] - n) * left.get();
                //cout << "single v = " << path[L] << " " << ans - pans << endl;
                for (int R = L + sz - 1; R >= L + 1; R--)
                {
                    int cnt_edges = (R - L - 1) / 2;
                    ll phi = 1;
                    if (path[L] < n && path[R] < n)
                    {
                        phi = right.get();
                        int v = path[L], u = path[R];
                        if (v > u) swap(v, u);
                        phi *= left.get(v, u);
                    }
                    if (path[L] >= n && path[R] >= n)
                    {
                        phi = left.get();
                        int v = path[L] - n, u = path[R] - n;
                        if (v > u) swap(v, u);
                        phi *= right.get(v, u);
                    }
                    if (path[L] < n && path[R] >= n)
                    {
                        phi = left.get(path[L]) * right.get(path[R] - n);
                    }
                    if (path[L] >= n && path[R] < n)
                    {
                        phi = right.get(path[L] - n) * left.get(path[R]);
                    }
                    ans += phi * cnt_edges;
                    if (path[R] < n) left.remove(path[R]); else right.remove(path[R] - n);
                }
            }
        }
    }
    cout << ans << "\n";
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