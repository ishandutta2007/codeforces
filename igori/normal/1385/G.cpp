const int LG = 21;
const int N = 400005;
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
string Yes[2] = {"No", "Yes"};
string YES[2] = {"NO", "YES"};

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

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(N);
    __ufact.resize(N);
    __rev.resize(N);
    __rev[1] = 1;
    for (int i = 2; i < N; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < N; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n) return 0;
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

int Root(int x, vector<int> &root)
{
    if (x == root[x]) return x;
    return root[x] = Root(root[x], root);
}

void Merge(int v, int u, vector<int> &root, vector<int> &sz)
{
    v = Root(v, root), u = Root(u, root);
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

int ok(int x, int n)
{
    return 0 <= x && x < n;
}

void bfs(int v, vi &dist, vector<vi> &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < q.size(); i++)
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
    vector<int> z(s.size());
    z[0] = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < s.size(); i++)
    {
        z[i] = max(0, min(z[i - L], R - i));
        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) z[i]++;
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
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++)
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
    vector<int> d1(s.size());
    int L = 0, R = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d1[R - i + L]);
        while (i + k < s.size() && i - k >= 0 && s[i - k] == s[i + k])
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
    vector<int> d2(s.size());
    int L = 0, R = -1;
    for (int i = 1; i < s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d2[R - i + L + 1]);
        while (i + k < s.size() && i - k - 1 >= 0 && s[i - k - 1] == s[i + k])
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

bool in(int bit, int mask)
{
    return (mask & (1 << bit)) > 0;
}

void Del(vector<int> &v, int pos)
{
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();
}

vector<int> positive, negative;

void dfs(int v, vector<vector<pii> > &g, vi &vis, int x)
{
    vis[v] = 1;
    if (x > 0) positive.push_back(v);
    else negative.push_back(v);
    for (auto u : g[v])
    {
        if (!vis[u.fi])
        {
            dfs(u.fi, g, vis, x * u.se);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vi> pos(n);
    forn(i, n) cin >> a[i], a[i]--, pos[a[i]].push_back(i);
    forn(i, n) cin >> b[i], b[i]--, pos[b[i]].push_back(i);
    vector<vector<pair<int, int> > > graph(n);
    for (int i = 0; i < n; i++)
    {
        if (pos[i].size() != 2)
        {
            cout << -1 << "\n";
            return;
        }
        if (pos[i][0] == pos[i][1])
        {
            continue;
        }
        if (a[pos[i][0]] == a[pos[i][1]] || b[pos[i][0]] == b[pos[i][1]])
        {
            graph[pos[i][0]].push_back({pos[i][1], -1});
            graph[pos[i][1]].push_back({pos[i][0], -1});
        }
        else
        {
            graph[pos[i][0]].push_back({pos[i][1], 1});
            graph[pos[i][1]].push_back({pos[i][0], 1});
        }
    }
    vector<int> ans;
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            positive.clear();
            negative.clear();
            dfs(i, graph, vis, 1);
            if (positive.size() < negative.size())
            {
                for (auto u : positive) ans.push_back(u);
            }
            else
            {
                for (auto u : negative) ans.push_back(u);
            }
        }
    }
    cout << ans.size() << "\n";
    forn(i, ans.size())
    {
        cout << ans[i] + 1 << " ";
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
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/