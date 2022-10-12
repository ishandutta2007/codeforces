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

void dfs1(int v, vvi &g, vi &vis, vi &order)
{
    vis[v] = 1;
    for (auto u : g[v]) if (vis[u] == 0)
        dfs1(u, g, vis, order);
    order.push_back(v);
}

void dfs2(int v, vvi &g, vi &vis, vi &col, int fl)
{
    vis[v] = 0;
    col[v] = fl;
    for (auto u : g[v]) if (vis[u])
        dfs2(u, g, vis, col, fl);
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s; s--;
    vector<vector<int> > g(n), rg(n);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].push_back(t);
        rg[t].push_back(f);
    }
    vector<int> order, vis(n), col(n);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            dfs1(i, g, vis, order);
    }
    int fl = 0;
    reverse(all(order));
    for (auto e : order)
    {
        //cout << e + 1 << " ";
        if (vis[e] == 1)
            dfs2(e, rg, vis, col, fl), fl++;
    }
    //cout << endl;
    vector<int> cnt_in(fl);
    for (int i = 0; i < n; i++)
    {
        for (auto u : g[i])
        {
            //cout << i << " -> " << u << " : " << col[i] << " -> " << col[u] << endl;
            if (col[i] != col[u]) cnt_in[col[u]]++;
        }
    }
//    for (int i = 0; i < n; i++) cout << col[i] << " ";
//    cout << endl;
//    for (int i = 0; i < fl; i++) cout << cnt_in[i] << " ";
//    cout << endl;
    int ans = 0;
    for (int i = 0; i < fl; i++) if (cnt_in[i] == 0) ans++;
    cout << ans - (cnt_in[col[s]] == 0);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
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