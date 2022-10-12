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

void dfs(int V, int p, vvi &g, vll &u, vll &v, vll &w, vll &dp0, vll &dp1, int k)
{
    //cout << V << " <- " << p << endl;
    ll res = 0;
    vector<pair<ll, ll> > W;
    for (auto e : g[V])
    {
        int U = v[e] + u[e] - V;
        if (U != p)
        {
            dfs(U, V, g, u, v, w, dp0, dp1, k);
            W.push_back({dp0[U] + w[e], dp1[U]});
        }
    }
    for (auto e : W)
        res += e.second;
    sort(all(W), [&](pair<ll, ll> A, pair<ll, ll> B){
            return A.fi - A.se > B.fi - B.se;
         });
    dp0[V] = res;
    for (int i = 0; i < W.size() && i < k - 1; i++)
        res += W[i].fi - W[i].se, dp0[V] = max(dp0[V], res);
    dp1[V] = dp0[V];
    if (k - 1 < W.size()) dp1[V] = max(dp1[V], dp0[V] + W[k - 1].fi - W[k - 1].se);
    //cout << dp0[V] << " " << dp1[V] << endl;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> u(n - 1), v(n - 1), w(n - 1), dp0(n), dp1(n);
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
    }
    dfs(0, 0, g, u, v, w, dp0, dp1, k);
    cout << max(dp0[0], dp1[0]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}