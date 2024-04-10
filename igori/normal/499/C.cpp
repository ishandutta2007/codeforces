const int LG = 21;
const int FN = 400005;
const long long MOD = 998244353;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > G;

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
    __fact.resize(FN);
    __ufact.resize(FN);
    __rev.resize(FN);
    __rev[1] = 1;
    for (int i = 2; i < FN; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < FN; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
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

double sqr(double x)
{
    return x * x;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    ll ans = 0;
    while (n--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll p = a * x1 + b * y1 + c;
        ll q = a * x2 + b * y2 + c;
        if (p < 0 && q > 0) ans++;
        if (p > 0 && q < 0) ans++;
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