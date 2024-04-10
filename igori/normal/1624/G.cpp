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

void dfs(int v, vector<vector<pii> > &g, vector<int> &vis, int W)
{
    vis[v] = 1;
    for (auto e : g[v]) if ((e.second & W) == e.second)
    {
        if (vis[e.first] == 0) dfs(e.first, g, vis, W);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > g(n);
    forn(i, m)
    {
        int f, t, w;
        cin >> f >> t >> w;
        f--, t--;
        g[f].pb({t, w});
        g[t].pb({f, w});
    }
    ll ans = (1 << 30) - 1;
    for (int b = 29; b >= 0; b--)
    {
        ll W = ans - (1 << b);
        vector<int> vis(n);
        dfs(0, g, vis, W);
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 0)
            {
                W += (1 << b);
                break;
            }
        }
        ans = W;
    }
    cout << ans << "\n";
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