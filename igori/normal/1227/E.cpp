const int LG = 21;
const int N = 400005;
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

int n, m;

int g(int i, int j, vvi &p)
{
    if (i < 0 || j < 0) return 0;
    if (i >= n && j >= m) return p[n - 1][m - 1];
    if (i >= n) return p[n - 1][j];
    if (j >= m) return p[i][m - 1];
    return p[i][j];
}

int check(int M, vvi &p, vvi& a)
{
    vvi restore(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int z = g(i + M, j + M, p) - g(i - M - 1, j + M, p) - g(i + M, j - M - 1, p)
                  + g(i - M - 1, j - M - 1, p);
            if (z == (2 * M + 1) * (2 * M + 1))
            {
                int x0 = i - M, y0 = j - M;
                restore[max(x0, 0)][max(y0, 0)]++;
                int x1 = i + M + 1, y1 = j + M + 1;
                if (x1 < n && y1 < m) restore[x1][y1]++;
                int x2 = i + M + 1, y2 = j - M;
                if (x2 < n) restore[x2][max(y2, 0)]--;
                int x3 = i - M, y3 = j + M + 1;
                if (y3 < m) restore[max(x3, 0)][y3]--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            restore[i][j] += g(i - 1, j, restore) + g(i, j - 1, restore) - g(i - 1, j - 1, restore);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0 && restore[i][j] != 0) return 0;
            if (a[i][j] != 0 && restore[i][j] == 0) return 0;
        }
    }
    return 1;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<string> s(n);
    forn(i, n)
    {
        cin >> s[i];
    }
    vector<vector<int> > tb(n, vi(m));
    forn(i, n)
    {
        forn(j, m)
        {
            if (s[i][j] == 'X')
            {
                tb[i][j] = 1;
            }
        }
    }
    vvi p = tb;
    forn(i, n)
    {
        forn(j, m)
        {
            p[i][j] += g(i, j - 1, p) + g(i - 1, j, p) - g(i - 1, j - 1, p);
        }
    }
    int L = 0, R = 511;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (check(M, p, tb))
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    cout << L << "\n";
    vvi fire(n, vi(m));
    int M = L;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int z = g(i + M, j + M, p) - g(i - M - 1, j + M, p) - g(i + M, j - M - 1, p)
                  + g(i - M - 1, j - M - 1, p);
            if (z == (2 * M + 1) * (2 * M + 1))
            {
                fire[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fire[i][j])
            {
                cout << "X";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "\n";
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