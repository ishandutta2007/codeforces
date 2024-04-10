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

void dfs(int v, vvi &g, vi &c, int fl, int &res)
{
    if (c[v] != -1)
    {
        if (c[v] != fl) res = 0;
        return;
    }
    c[v] = fl;
    for (auto u : g[v]) dfs(u, g, c, 1 ^ fl, res);
}

void solve()
{
    #define tests

    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i], b[i] = b[i] - a[i];
    vvi g(n);
    forn(i, m)
    {
        int f, t;
        cin >> f >> t, f--, t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    ll tot = accumulate(all(b), 0LL);
    if (tot % 2)
    {
        cout << "NO\n";
        re;
    }
    vector<int> c(n, -1);
    int res = 1;
    dfs(0, g, c, 0, res);
    if (res == 0)
    {
        cout << "YES\n";
        re;
    }
    tot = 0;
    for (int i = 0; i < n; i++) if (c[i] == 1) tot += b[i]; else tot -= b[i];
    cout << YES[tot == 0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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