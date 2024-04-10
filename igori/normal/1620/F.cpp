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

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<map<int, int> > dp(n + 1);
    vector<map<int, pii> > papa(n + 1);
    dp[0][2 * n + 2] = 2 * n + 2;
    vector<int> states = {2 * n + 2};
    for (int i = 0; i < n; i++)
    {
        int mx_lx = 0;
        int mx_rx = 0;
        for (auto lst : states)
        {
            if (dp[i][lst] == 0) continue;
            int x = n + 1 + p[i];
            {
                if (lst < x && x < dp[i][lst])
                {
                    if (x > dp[i + 1][lst])
                        dp[i + 1][lst] = x, papa[i + 1][lst] = {lst, x},
                        mx_rx = max(mx_rx, lst);
                }
                if (x < lst)
                {
                    if (dp[i][lst] > dp[i + 1][x])
                         dp[i + 1][x] = dp[i][lst], papa[i + 1][x] = {lst, x};
                }
            }
            x = n + 1 - p[i];
            {
                if (lst < x && x < dp[i][lst])
                {
                    if (x > dp[i + 1][lst])
                        dp[i + 1][lst] = x, papa[i + 1][lst] = {lst, x},
                        mx_lx = max(mx_lx, lst);
                }
                if (x < lst)
                {
                    if (dp[i][lst] > dp[i + 1][x])
                         dp[i + 1][x] = dp[i][lst], papa[i + 1][x] = {lst, x};
                }
            }
        }
        dp[i].clear();
        states = {n + 1 + p[i], n + 1 - p[i]};
        if (mx_lx != 0) states.push_back(mx_lx);
        if (mx_rx != 0) states.push_back(mx_rx);
    }
    int id = -1;
    for (auto e : dp[n])
    {
        id = e.first;
        break;
    }
    if (id == -1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> ans;
    for (int i = n; i > 0; i--)
    {
        ans.push_back(papa[i][id].second);
        id = papa[i][id].first;
    }
    reverse(all(ans));
    forn(i, ans.size()) ans[i] = ans[i] - (n + 1);
    for (auto e : ans) cout << -e << " "; cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}