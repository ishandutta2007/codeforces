const long long MOD = 998244353;
const long long INF = 1e9;
const long long INFLL = 1e12 + 22;

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

const int N = 203040;

int n;
ll t[N], h[N];
vector<int> g[N];
ll dp[N][2];

void dfs(int v, int p)
{
    vector<ll> s;
    ll si = 0;
    for (auto u : g[v]) if (u != p)
    {
        dfs(u, v);
        s.push_back(dp[u][1] - dp[u][0]);
        si += dp[u][0];
    }
    sort(all(s));
    dp[v][0] = INFLL;
    dp[v][1] = INFLL;
    int deg = g[v].size();
    for (int r = 0; r <= s.size(); r++)
    {
        dp[v][0] = min(dp[v][0], si + max(r + 1, deg - r - 1) * t[v]);
        dp[v][1] = min(dp[v][1], si + max(r, deg - r) * t[v]);
        if (r < s.size())
            si += s[r];
    }
    if (h[v] > h[p]) dp[v][1] = INFLL;
    if (h[v] < h[p]) dp[v][0] = INFLL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<ll> s;
    ll si = 0;
    for (auto u : g[0])
    {
        dfs(u, 0);
        s.push_back(dp[u][1] - dp[u][0]);
        si += dp[u][0];
    }
    sort(all(s));
    ll res = INFLL;
    int deg = g[0].size();
    for (int r = 0; r <= s.size(); r++)
    {
        res = min(res, si + max(r, deg - r) * t[0]);
        if (r < s.size())
            si += s[r];
    }
    cout << res;
}