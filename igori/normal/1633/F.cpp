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

ll inq(ll x, ll y, ll mod)
{
    if (y == 0) return 1 % mod;
    ll l = inq(x, y / 2, mod);
    if (y % 2) return l * l % mod * x % mod;
    return l * l % mod;
}

void dfs(int v, int p, vector<vector<pii> > &g, vector<int> &id_of_par_edge, vector<int> &papa, vector<int> &sz)
{
    for (auto e : g[v]) if (e.first != p)
    {
        dfs(e.first, v, g, id_of_par_edge, papa, sz);
        sz[v] += sz[e.first];
    }
    else
    {
        id_of_par_edge[v] = e.second;
        papa[v] = e.first;
    }
}

void build(int v, int p, vector<vector<pii> > &g, vector<vector<int> > &paths, vector<pair<int, int> > &path_id, vector<int> &grandpapa, vector<int> &sz, vector<int> &val)
{
    if (grandpapa[v] == 0)
    {
        grandpapa[v] = p;
        path_id[v] = {paths.size(), 0};
        paths.push_back({val[v]});
    }
    if (g[v].size() == 1 && v != p) return;
    int mx_size = 0, id = 0;
    for (auto e : g[v]) if (e.first != p)
    {
        if (sz[e.first] > mx_size)
        {
            mx_size = sz[e.first];
            id = e.first;
        }
    }
    grandpapa[id] = grandpapa[v];
    path_id[id] = {path_id[v].first, path_id[v].second + 1};
    paths[path_id[v].first].push_back(val[id]);
    for (auto e : g[v]) if (e.first != p)
    {
        build(e.first, v, g, paths, path_id, grandpapa, sz, val);
    }
}

void solve()
{
    struct Node{
        array<ll, 2> sum;
        int fl;
    };
    struct SegTree{
        vector<Node> tree;
        void push(int V)
        {
            if (tree[V].fl)
            {
                swap(tree[2 * V + 1].sum[0], tree[2 * V + 1].sum[1]);
                tree[2 * V + 1].fl ^= 1;
                swap(tree[2 * V + 2].sum[0], tree[2 * V + 2].sum[1]);
                tree[2 * V + 2].fl ^= 1;
                tree[V].fl = 0;
            }
        }
        void merge(int V)
        {
            tree[V].sum[0] = tree[2 * V + 1].sum[0] + tree[2 * V + 2].sum[0];
            tree[V].sum[1] = tree[2 * V + 1].sum[1] + tree[2 * V + 2].sum[1];
        }
        void build(int L, int R, int V, vector<int> &a)
        {
            if (L + 1 == R)
            {
                tree[V].sum[1] = a[L];
                return;
            }
            int M = (L + R) / 2;
            build(L, M, 2 * V + 1, a);
            build(M, R, 2 * V + 2, a);
            merge(V);
        }
        SegTree(vector<int> a)
        {
            tree.resize(4 * a.size());
            build(0, a.size(), 0, a);
        }
        void invert(int l, int r, int L, int R, int V)
        {
            if (l <= L && R <= r)
            {
                swap(tree[V].sum[0], tree[V].sum[1]);
                tree[V].fl ^= 1;
                return;
            }
            if (R <= l || r <= L) return;
            int M = (L + R) / 2;
            push(V);
            invert(l, r, L, M, 2 * V + 1);
            invert(l, r, M, R, 2 * V + 2);
            merge(V);
        }
        void invert(int l, int r)
        {
            invert(l, r, 0, tree.size() / 4, 0);
        }
        long long get(int l, int r, int L, int R, int V)
        {
            if (l <= L && R <= r)
                return tree[V].sum[0];
            if (R <= l || r <= L)
                return 0;
            int M = (L + R) / 2;
            push(V);
            ll ans = get(l, r, L, M, 2 * V + 1) + get(l, r, M, R, 2 * V + 2);
            merge(V);
            return ans;
        }
        long long get(int l, int r)
        {
            return get(l, r, 0, tree.size() / 4, 0);
        }
    };

    int n;
    cin >> n;
    vector<vector<pair<int, int> > > g(n + 1);
    vector<int> id_of_parent_edge(n + 1);
    vector<int> papa(n + 1);
    vector<int> sz(n + 1, 1);
    for (int i = 1; i < n; i++)
    {
        int f, t;
        cin >> f >> t;
        g[f].push_back({t, i});
        g[t].push_back({f, i});
    }
    dfs(1, 1, g, id_of_parent_edge, papa, sz);
    vector<vector<int> > paths;
    vector<int> grandpapa(n + 1);
    vector<pair<int, int> > path_id(n + 1);
    build(1, 1, g, paths, path_id, grandpapa, sz, id_of_parent_edge);
    for (int i = 1; i <= n; i++) if (path_id[i].first == 0) grandpapa[i] = 0;

    long long cur_sum = 0, cur_count = 0;
    vector<SegTree> Sum, Count;
    for (int i = 0; i < paths.size(); i++)
    {
        Sum.push_back(SegTree(paths[i]));
        Count.push_back(SegTree(vector<int>(paths[i].size(), 1)));
    }

    auto activate = [&](int v){
        while (v != 0)
        {
            cur_sum -= Sum[path_id[v].first].get(0, path_id[v].second + 1);
            Sum[path_id[v].first].invert(0, path_id[v].second + 1);
            cur_sum += Sum[path_id[v].first].get(0, path_id[v].second + 1);

            cur_count -= Count[path_id[v].first].get(0, path_id[v].second + 1);
            Count[path_id[v].first].invert(0, path_id[v].second + 1);
            cur_count += Count[path_id[v].first].get(0, path_id[v].second + 1);

            v = grandpapa[v];
        }
    };

    activate(1);
    int c = 1;
    while (1)
    {
        int t;
        cin >> t;
        if (t == 0) return;
        if (t == 3) return;
        if (t == 1)
        {
            int v;
            cin >> v;
            activate(v);
            c++;
            if (c == 2 * cur_count) cout << cur_sum << endl;
            else cout << 0 << endl;
        }
        if (t == 2)
        {
            if (c != 2 * cur_count)
            {
                cout << 0 << endl;
            }
            else
            {
                vector<int> ans;
                for (int i = 1; i <= n; i++)
                {
                    int x = Sum[path_id[i].first].get(path_id[i].second, path_id[i].second + 1);
                    if (x != 0) ans.push_back(x);
                }
                sort(ans.begin(), ans.end());
                cout << ans.size() << " ";
                for (auto e : ans) cout << e << " ";
                cout << endl;
            }
        }
        //cout << "! " << cur_count << " " << cur_sum << endl;
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}