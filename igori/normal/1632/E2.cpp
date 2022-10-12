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

void dfs(int v, int p, vvi &g, vector<int> &dist)
{
    if (v == 0) dist[v] = 0;
    else dist[v] = dist[p] + 1;
    for (auto u : g[v]) if (u != p)
    {
        dfs(u, v, g, dist);
    }
}

void dfs2(int v, int p, vvi &g, vector<int> &cnt)
{
    for (auto u : g[v]) if (u != p)
    {
        dfs2(u, v, g, cnt);
        cnt[v] += cnt[u];
    }
}

void dfs3(int v, int p, vvi &g, vector<int> &par)
{
    par[v] = p;
    for (auto u : g[v]) if (u != p)
    {
        dfs3(u, v, g, par);
    }
}

int dfs_depth(int v, int p, vvi &g, vi &mark)
{
    int ans = 0;
    for (auto u : g[v]) if (u != p && mark[u] == 0)
    {
        ans = max(ans, dfs_depth(u, v, g, mark) + 1);
    }
    return ans;
}

template<class T> struct sparse_max{
    // Returns min on segment [l, r] of predefined array a
    //
    // Correctness tested on the following problem:
    // https://codeforces.com/contest/1304/problem/E
    // Speed tested on random tests with n = 4e6, q = 4e6, T = int, average = 0.508ms/test (local)
    // Speed tested on random tests with n = 4e6, q = 4e7, T = int, average = 1.778ms/test (local)
    //
    vector<vector<T> > sp;
    vector<int> H;
    T get(int l, int r)
    {
        int h = H[r - l + 1];
        return max(sp[h][l], sp[h][r - (1 << h) + 1]);
    }
    sparse_max(vector<T> a)
    {
        int n = a.size();
        H = vector<int>(n + 1);
        for (int i = 3; i < n + 1; i++)
        {
            H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
        }
        int s = 0;
        while ((1 << s) <= n) s++;
        sp = vector<vector<T>>(s, vector<T>(n));
        for (int i = 0; i < n; i++)
        {
            sp[0][i] = a[i];
        }
        for (int j = 1; j < s; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                sp[j][i] = get(i, i + (1 << j) - 1);
            }
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    vector<int> dist(n);
    dfs(0, 0, g, dist);

    vector<int> cnts(n);
    int D = *max_element(all(dist));
    for (int i = 0; i < n; i++) if (dist[i] == D) cnts[i] = 1;

    dfs2(0, 0, g, cnts);

    int node = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnts[i] == cnts[node] && dist[i] > dist[node]) node = i;
    }
    vector<int> p(n);
    dfs3(0, 0, g, p);

    vector<int> mark(n);
    mark[node] = 1;
    dfs2(0, 0, g, mark);

    vector<int> path = {node};
    while (path.back() != 0)
        path.push_back(p[path.back()]);

    reverse(path.begin(), path.end());

    vector<int> H(path.size());
    for (int i = 0; i < path.size(); i++)
    {
        H[i] = dfs_depth(path[i], path[i], g, mark);
    }
    vector<int> pH(H.size());
    vector<int> sH(H.size());
    for (int i = 0; i < H.size(); i++)
    {
        pH[i] = H[i] + i;
        sH[i] = H[i] + i;
        if (i && pH[i - 1] > pH[i]) pH[i] = pH[i - 1];
    }
    for (int i = (int)H.size() - 2; i >= 0; i--)
    {
        sH[i] = max(sH[i], sH[i + 1]);
    }
    vector<int> dH(H.size());
    for (int i = 0; i < H.size(); i++) dH[i] = H[i] - i;
    sparse_max<int> sp(dH);

    vector<int> out(n + 1, D);
    for (int ans = 1, x = 1; ans <= D; ans++)
    {
        int t = 0;
        for (; x <= n; x++)
        {
            int i = D + x - ans;

            if (i >= H.size() || i < x) break;
            int res = pH[(i + x) / 2];
            if ((i + x) / 2 + 1 <= i)
                res = max(res, sp.get((i + x) / 2 + 1, i) + i + x);
            res = max(res, sH[i] + x - i);
            if (res > ans)
            {
                t = 0;
                break;
            }
            else
            {
                out[x] = min(out[x], ans);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) out[i] = min(out[i], out[i + 1]);
    for (int i = 1; i <= n; i++) cout << out[i] << " "; cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}