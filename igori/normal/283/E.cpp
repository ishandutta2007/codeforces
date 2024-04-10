const int LG = 21;
const int N = 100005;
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

int n, q;
int cnt0[4 * N], cnt1[4 * N];
int push[4 * N];
int a[N];

void Push(int V)
{
    if (push[V] == 1)
    {
        swap(cnt0[2 * V + 1], cnt1[2 * V + 1]);
        swap(cnt0[2 * V + 2], cnt1[2 * V + 2]);
        push[2 * V + 1] ^= 1;
        push[2 * V + 2] ^= 1;
        push[V] = 0;
    }
}

void init(int l = 0, int r = n, int v = 0)
{
    if (l + 1 == r)
    {
        cnt0[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * v + 1);
    init(m, r, 2 * v + 2);
    cnt0[v] = cnt0[2 * v + 1] + cnt0[2 * v + 2];
}

void ch(int L, int R, int l = 0, int r = n, int v = 0)
{
    if (R <= l || r <= L) return;
    if (L <= l && r <= R)
    {
        swap(cnt0[v], cnt1[v]);
        push[v] ^= 1;
        return;
    }
    int m = (l + r) / 2;
    Push(v);
    ch(L, R, l, m, 2 * v + 1);
    ch(L, R, m, r, 2 * v + 2);
    cnt0[v] = cnt0[2 * v + 1] + cnt0[2 * v + 2];
    cnt1[v] = cnt1[2 * v + 1] + cnt1[2 * v + 2];
}

int get(int L, int R, int l = 0, int r = n, int v = 0)
{
    if (R <= l || r <= L) return 0;
    if (L <= l && r <= R) return cnt1[v];
    int m = (l + r) / 2;
    Push(v);
    return get(L, R, l, m, 2 * v + 1) + get(L, R, m, r, 2 * v + 2);
}

int bs(int x)
{
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (a[m] > x) r = m;
        else l = m;
    }
    return r;
}

vector<pair<int, int> > qat[N];

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    init();
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        int l = bs(x - 1), r = bs(y);
        //cout << "l r " << l << " " << r << endl;
        qat[l].push_back({l, r});
        qat[r].push_back({l, r});
    }
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++)
    {
        for (auto p : qat[i])
        {
            ch(p.fi, p.se);
        }
        ll dg = get(0, i) + n - i - 1 - get(i + 1, n);
        /*for (int j = 0; j < n; j++)
        {
            cout << get(j, j + 1) << " ";
        }
        cout << "\n";
        cout << dg << "\n";*/
        ans -= dg * (dg - 1) / 2;
    }
    cout << ans;
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