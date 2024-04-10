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

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
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

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
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

ll gcdex(ll a, ll b, ll &x, ll &y)
{
    // Solves the equation ax + by = gcd(a, b)
    // returns gcd(a, b)
    // save x and y in given values
    //
    // Correctness tested on random tests.
    // Correctness tested on the following problem:
    // https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_f
    //
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll g = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

pair<ll, ll> crt(vector<ll> r, vector<ll> m)
{
    // Finds such x, that x mod m[i] = r[i] for each i
    // if such x does not exist returns {0, 0}
    //
    // Correctness tested on random tests.
    // Correctness tested on the following problem:
    // https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_f
    //
    int n = r.size();
    for (int i = 0; i < n; i++) r[i] %= m[i];
    ll r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++)
    {
        ll r1 = r[i], m1 = m[i];
        if (m0 < m1)
        {
            swap(m0, m1);
            swap(r0, r1);
        }
        if (m0 % m1 == 0)
        {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        ll x, y;
        ll g = gcdex(m0, m1, x, y);
        ll u = m1 / g;
        if ((r0 - r1) % g != 0)
            return {0, 0};
        ll z = (r1 - r0) / g % u * x % u;
        r0 += z * m0;
        m0 *= u;
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

struct dsu
{
    vector<int> root;
    vector<int> sz;

    dsu(int _n)
    {
        root.resize(_n);
        iota(all(root), 0);
        sz.resize(_n, 1);
    }

    dsu()
    {
        dsu(0);
    }

    void Reset(int _n)
    {
        root.resize(_n);
        sz.resize(_n);
        for (int i = 0; i < (int)root.size(); i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }

    void Reset()
    {
        Reset(root.size());
    }

    int Root(int x)
    {
        if (x == root[x]) return x;
        return root[x] = Root(root[x]);
    }

    void Merge(int v, int u)
    {
        v = Root(v), u = Root(u);
        if (v == u) return;
        if (sz[v] < sz[u])
        {
            sz[u] += sz[v];
            root[v] = u;
        }
        else
        {
            sz[v] += sz[u];
            root[u] = v;
        }
    }
};

struct dsu_cut
{
    vector<int> root;
    vector<int> sz;
    stack<int> cuts;

    dsu_cut(int _n)
    {
        root.resize(_n);
        iota(all(root), 0);
        sz.resize(_n, 1);
    }

    dsu_cut()
    {
        dsu_cut(0);
    }

    void Cut()
    {
        if (!cuts.size()) return;
        int v = cuts.top();
        sz[root[v]] -= sz[v];
        root[v] = v;
        cuts.pop();
    }

    void Reset(int _n)
    {
        root.resize(_n);
        sz.resize(_n);
        for (int i = 0; i < (int)root.size(); i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }

    void Reset()
    {
        if (cuts.size() < root.size())
        {
            while (cuts.size())
            {
                Cut();
            }
        }
        else
        {
            Reset(root.size());
        }
    }

    int Root(int x)
    {
        if (x == root[x]) return x;
        return Root(root[x]);
    }

    void Merge(int v, int u)
    {
        v = Root(v), u = Root(u);
        if (v == u) return;
        if (sz[v] < sz[u])
        {
            sz[u] += sz[v];
            root[v] = u;
            cuts.push(v);
        }
        else
        {
            sz[v] += sz[u];
            root[u] = v;
            cuts.push(u);
        }
    }
};

void bfs(int v, vi &dist, vector<vi> &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < (int)q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
}

vector<int> z_func(string &s)
{
    // Calculates z-function of string s
    // z[0] = s.size(), s should not be empty
    //
    // Tested on the following problem:
    // https://codeforces.com/edu/course/2/lesson/3/3/practice/contest/272263/problem/A
    //
    vector<int> z(s.size());
    z[0] = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < (int)s.size(); i++)
    {
        z[i] = max(0, min(z[i - L], R - i));
        while (i + z[i] < (int)s.size() && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > R)
        {
            R = i + z[i];
            L = i;
        }
    }
    return z;
}

vector<int> p_func(string &s)
{
    // Calculates prefix function of string s
    //
    //
    vector<int> p(s.size());
    for (int i = 1; i < (int)s.size(); i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

vector<int> d1_func(string &s)
{
    // Calculates max length of palindrome centered in positions and i for each i
    //
    //
    vector<int> d1(s.size());
    int L = 0, R = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d1[R - i + L]);
        while (i + k < (int)s.size() && i - k >= 0 && s[i - k] == s[i + k])
            k++;
        d1[i] = k--;
        if (i + k > R)
        {
            L = i - k;
            R = i + k;
        }
    }
    return d1;
}

vector<int> d2_func(string &s)
{
    // Calculates max length of palindrome centered in positions i - 1 and i for each i
    //
    //
    vector<int> d2(s.size());
    int L = 0, R = -1;
    for (int i = 1; i < (int)s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d2[R - i + L + 1]);
        while (i + k < (int)s.size() && i - k - 1 >= 0 && s[i - k - 1] == s[i + k])
            k++;
        d2[i] = k--;
        if (i + k > R)
        {
            L = i - k - 1;
            R = i + k;
        }
    }
    return d2;
}

template<class T> void add(int pos, T x, vector<T> &fenw)
{
    // Performs add query on Fenwick tree
    //
    // Tested on the following problem:
    // https://atcoder.jp/contests/practice2/tasks/practice2_b
    //
    while (pos < (int)fenw.size())
    {
        fenw[pos] += x;
        pos |= (pos + 1);
    }
}

template<class T> T get(int pos, vector<T> &fenw)
{
    // Performs get query on Fenwick tree
    //
    // Tested on the following problem:
    // https://atcoder.jp/contests/practice2/tasks/practice2_b
    //
    ll res = 0;
    while (pos >= 0)
    {
        res += fenw[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

template<class T> vector<int> different_on_segment_offline(vector<T> a, vector<int> l, vector<int> r)
{
    // For each segment [l[i], r[i]] of calculates number of different elements in array A
    //
    // Correctness tested on random tests with n <= 25000, q <= 25000, different maxA, T = int
    // Speed tested on random tests with n = 250000, q = 250000, maxA = maxRand, T = int, average = 0.108ms/test (local)
    //
    map<T, int> lst;
    vector<int> ans(l.size());
    vector<vector<int> > ends(a.size());
    vector<int> fenw(a.size());
    for (int i = 0; i < (int)l.size(); i++)
    {
        ends[r[i]].push_back(i);
    }
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (lst.find(a[i]) != lst.end())
        {
            add(lst[a[i]], -1, fenw);
        }
        lst[a[i]] = i;
        add(i, 1, fenw);
        for (auto q : ends[i])
        {
            ans[q] = get(i, fenw) - get(l[q] - 1, fenw);
        }
    }
    return ans;
}

struct dcp_offine{
    // Given n, m and arrays v, u, t of length m
    // -1 <= t[i] <= 1 and 0 <= v[i], u[i] < n satisfied for t[i] != -1
    // t[i] = 0 asks to change state of edge (v[i], u[i])
    // t[i] = -1 asks to calculate number of connected components
    // t[i] = 1 asks to check if v[i] and u[i] are in the same connected component
    // After creating following holds:
    // ans[i] contains -1 for t[i] = 0 and answer for the i-th query otherwise
    //
    // Correctness t[i] <= 0 tested on the following problem:
    // https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/C
    // Correctness tested on random tests with m = 40000
    // Speed tested on random tests with m = 2e6, average = 0.955ms/test (local)
    //
    int n, m;
    dsu_cut dcp;
    vector<int> ans;
    void solve(int l, int r, vi &v, vi &u, vi &t, vi &L, vi &R)
    {
        if (l >= r) return;
        if (l + 1 == r)
        {
            if (t[l] == -1)
            {
                ans[l] = n - dcp.cuts.size();
            }
            if (t[l] == 1)
            {
                ans[l] = dcp.Root(v[l]) == dcp.Root(u[l]);
            }
            return;
        }
        int m = (l + r) / 2;
        int ss = dcp.cuts.size();
        for (int i = l; i < m; i++)
        {
            if (R[i] >= r) dcp.Merge(v[i], u[i]);
        }
        solve(m, r, v, u, t, L, R);
        while ((int)dcp.cuts.size() > ss) dcp.Cut();
        for (int i = r - 1; i >= m; i--)
        {
            if (L[i] < l) dcp.Merge(v[i], u[i]);
        }
        solve(l, m, v, u, t, L, R);
        while ((int)dcp.cuts.size() > ss) dcp.Cut();
    }
    dcp_offine(int _n, int _m, vi v, vi u, vi t)
    {
        n = _n, m = _m;
        dcp.Reset(n);
        ans.resize(m, -1);
        map<pair<int, int>, int> mm;
        vi L(m, INF), R(m, -INF);
        for (int i = 0; i < m; i++)
        {
            if (t[i] != 0) continue;
            if (v[i] > u[i]) swap(v[i], u[i]);
            if (mm.find({v[i], u[i]}) == mm.end())
            {
                mm[{v[i], u[i]}] = i;
            }
            else
            {
                int t = mm[{v[i], u[i]}];
                R[t] = i;
                L[i] = t;
                mm.erase({v[i], u[i]});
            }
        }
        while (mm.size())
        {
            t.push_back(0);
            ans.push_back(-1);
            L.push_back(INF);
            R.push_back(-INF);
            auto it = mm.begin();
            pair<int, int> s = (*it).first;
            int t = (*it).second;
            R[t] = m;
            L[m] = t;
            v.push_back(s.first);
            u.push_back(s.second);
            mm.erase(mm.begin());
            m++;
        }
        solve(0, m, v, u, t, L, R);
    }
};

template<class T> struct sparse_min{
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
        return min(sp[h][l], sp[h][r - (1 << h) + 1]);
    }
    sparse_min(vector<T> a)
    {
        int n = a.size();
        H = vector<int>(n + 1);
        for (int i = 3; i < n + 1; i++)
        {
            H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
        }
        int s = 0;
        while ((1 << s) < n) s++;
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
        while ((1 << s) < n) s++;
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

struct graph_scc{
    // Finds Strongly Connected Components of given graph
    //
    // Correctness tested on the following problem:
    // https://atcoder.jp/contests/arc069/tasks/arc069_d
    //
    int n;
    vector<vector<int> > graph;
    vector<vector<int> > inv_graph;
    vector<int> fr, to;
    vector<int> fn;
    vector<int> vis;
    vector<int> component;
    int col;
    void inv_dfs(int v)
    {
        vis[v] = 1;
        for (auto id : inv_graph[v])
        {
            int u = fr[id];
            if (!vis[u])
            {
                inv_dfs(u);
            }
        }
        fn.push_back(v);
    }
    void dfs(int v)
    {
        component[v] = col;
        for (auto id : graph[v])
        {
            int u = to[id];
            if (component[u] == -1)
            {
                dfs(u);
            }
        }
    }
    graph_scc(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
        inv_graph = vector<vector<int> >(n);
    }
    void add_edge(int v, int u)
    {
        graph[v].push_back(fr.size());
        inv_graph[u].push_back(fr.size());
        fr.push_back(v);
        to.push_back(u);
    }
    vector<vector<int> > scc()
    {
        vis = vector<int>(n);
        component = vector<int>(n, -1);
        fn = {};
        col = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                inv_dfs(i);
            }
        }
        reverse(fn.begin(), fn.end());
        for (auto i : fn)
        {
            if (component[i] == -1)
            {
                dfs(i);
                col++;
            }
        }
        vector<vector<int> > res(col);
        for (int i = 0; i < n; i++)
        {
            res[component[i]].push_back(i);
        }
        return res;
    }
};

struct graph_bridges{
    // Finds bridges of given graph
    // Marks them in array isbridge
    // graph_bridges.dlc() returns doubly linked components of a given graph
    //
    // Correctness (bridges) tested on the following problem:
    // https://informatics.msk.ru/mod/statements/view.php?chapterid=111689#1
    //
    // Correctness (dlc) tested on the following problem:
    // https://judge.yosupo.jp/problem/two_edge_connected_components
    //
    int n;
    vector<vector<int> > graph;
    vector<int> v;
    vector<int> u;
    vector<int> isbridge;
    vector<int> in, out, up;
    vector<int> color;
    vector<int> par;
    int T;
    void dfs(int V, int P, int edge_in)
    {
        par[V] = P;
        in[V] = up[V] = T++;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (in[t] == -1)
            {
                dfs(t, V, id);
                up[V] = min(up[V], up[t]);
            }
            else if (id != edge_in)
            {
                up[V] = min(up[V], in[t]);
            }
        }
        out[V] = T++;
    }
    void dfs_dlc(int V, int P)
    {
        color[V] = T;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (!isbridge[id] && color[t] == -1)
            {
                dfs_dlc(t, V);
            }
        }
    }
    graph_bridges(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
    }
    void add_edge(int V, int U)
    {
        graph[V].push_back(v.size());
        graph[U].push_back(v.size());
        v.push_back(V);
        u.push_back(U);
    }
    void mark_bridges()
    {
        in = vector<int>(n, -1);
        out = vector<int>(n, -1);
        up = vector<int>(n, -1);
        par = vector<int>(n, -1);
        isbridge = vector<int>(v.size(), 0);
        T = 0;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == -1)
            {
                dfs(i, -1, -1);
            }
        }
        int m = v.size();
        for (int i = 0; i < m; i++)
        {
            if (par[u[i]] == v[i] && up[u[i]] == in[u[i]])
            {
                isbridge[i] = 1;
            }
            if (par[v[i]] == u[i] && up[v[i]] == in[v[i]])
            {
                isbridge[i] = 1;
            }
        }
    }
    vector<vector<int> > dlc()
    {
        mark_bridges();
        color = vector<int>(n, -1);
        T = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                dfs_dlc(i, -1);
                T++;
            }
        }
        vector<vector<int> > res(T);
        for (int i = 0; i < n; i++)
        {
            res[color[i]].push_back(i);
        }
        return res;
    }
};

struct graph_AP{
    // Finds articulation points of given graph
    // Marks them in array isAP
    // graph_AP.blocks() returns blocks of a given graph
    //
    // Correctness (AP) tested on the following problem:
    // https://informatics.msk.ru/mod/statements/view.php?chapterid=111690#1
    //
    // Correctness (blocks) tested on the following problem:
    // https://atcoder.jp/contests/arc062/tasks/arc062_d
    //
    int n;
    vector<vector<int> > graph;
    vector<int> v;
    vector<int> u;
    vector<int> isAP;
    vector<int> in, out, up;
    vector<int> par;
    vector<int> color;
    vector<int> vis;
    int T, rd;
    int maxColor;
    void dfs(int V, int P)
    {
        par[V] = P;
        in[V] = up[V] = T++;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (in[t] == -1)
            {
                if (P == -1)
                    rd++;
                dfs(t, V);
                up[V] = min(up[V], up[t]);
            }
            else if (t != P)
            {
                up[V] = min(up[V], in[t]);
            }
        }
        out[V] = T++;
    }
    void dfs_blocks(int V, int P, int c)
    {
        vis[V] = 1;
        for (auto id : graph[V])
        {
            int t = v[id] + u[id] - V;
            if (t == P)
            {
                continue;
            }
            if (!vis[t])
            {
                if (up[t] >= in[V])
                {
                    maxColor++;
                    color[id] = maxColor - 1;
                    dfs_blocks(t, V, maxColor - 1);
                }
                else
                {
                    color[id] = c;
                    dfs_blocks(t, V, c);
                }
            }
            else
            {
                if (in[t] < in[V])
                {
                    color[id] = c;
                }
            }
        }
    }
    graph_AP(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
    }
    void add_edge(int V, int U)
    {
        graph[V].push_back(v.size());
        graph[U].push_back(v.size());
        v.push_back(V);
        u.push_back(U);
    }
    void mark_AP()
    {
        in = vector<int>(n, -1);
        out = vector<int>(n, -1);
        up = vector<int>(n, -1);
        par = vector<int>(n, -1);
        isAP = vector<int>(n, 0);
        T = 0;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == -1)
            {
                rd = 0;
                dfs(i, -1);
                if (rd > 1)
                    isAP[i] = 1;
                else
                    isAP[i] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (isAP[i] == 0)
            {
                for (auto id : graph[i])
                {
                    int t = v[id] + u[id] - i;
                    if (par[t] == i && in[i] <= up[t])
                        isAP[i] = 1;
                }
            }
            else
            {
                if (isAP[i] == -1)
                {
                    isAP[i] = 0;
                }
            }
        }
    }
    vector<vector<int> > blocks()
    {
        mark_AP();
        color = vector<int>(v.size(), -1);
        vis = vector<int>(n, 0);
        maxColor = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs_blocks(i, -1, maxColor);
                maxColor++;
            }
        }
        vector<vector<int> > res = vector<vector<int> >(maxColor);
        for (int i = 0; i < (int)v.size(); i++)
        {
            res[color[i]].push_back(i);
        }
        vector<vector<int> > res2;
        for (int i = 0; i < (int)res.size(); i++)
        {
            if (res[i].size())
            {
                res2.push_back(res[i]);
            }
        }
        return res2;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vi> pos(n);
    forn(i, n)
    {
        pos[i].push_back(-1);
    }
    forn(i, n)
    {
        cin >> a[i];
        a[i]--;

        pos[a[i]].push_back(i);
    }
    forn(i, n)
    {
        pos[i].push_back(n);
    }
    vector<int> kek(n);
    vector<vector<int> > beg(n + 5);
    forn(i, n)
    {
        kek[i] = 0;
        dbg(1);
        for (int j = 0; j + 1 < pos[i].size(); j++)
        {
            kek[i] = max(kek[i], pos[i][j + 1] - pos[i][j]);
        }
        dbg(2);
        dbg(kek[i]);
        dbg(n);
        beg[kek[i]].push_back(i);
        dbg(3);
    }
    //cout << "111" << endl;
    int ans = -2;
    for (int i = 1; i <= n; i++)
    {
        if (beg[i].size())
        {
            if (ans == -2) ans = beg[i][0];
            else ans = min(ans, beg[i][0]);
        }
        cout << ans + 1 << " ";
    }
    cout << "\n";
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

/* Note:
Check constants at the beginning of the code (MOD, INF, INFLL)
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/