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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    forn(i, n) cin >> s[i];
    string t;
    cin >> t;
    vector<int> a(t.size());
    for (int i = 0; i < t.size(); i++) a[i] = t[i] - '0';

    struct item{
        int l, r, k;
        item()
        {
            l = -1, r = -1, k = -1;
        }
        item(int _l, int _r, int _k)
        {
            l = _l, r = _r, k = _k;
        }
    };
    vector<item> d2(100);
    vector<item> d3(1000);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            d2[(s[i][j] - '0') * 10 + s[i][j + 1] - '0'] = {j, j + 1, i};
        }
        for (int j = 0; j + 2 < m; j++)
        {
            d3[(s[i][j] - '0') * 100 + (s[i][j + 1] - '0') * 10 + s[i][j + 2] - '0'] = {j, j + 2, i};
        }
    }

    vector<int> dp(m + 1, -1);
    dp[0] = 0;
    vector<int> len(m + 1);
    for (int i = 1; i <= m; i++)
    {
        if (i >= 2)
        {
            int x = (a[i - 2] * 10 + a[i - 1]);
            if (dp[i - 2] != -1 && d2[x].k != -1)
            {
                dp[i] = x;
                len[i] = 2;
            }
        }
        if (i >= 3)
        {
            int x = (a[i - 3] * 100 + a[i - 2] * 10 + a[i - 1]);
            if (dp[i - 3] != -1 && d3[x].k != -1)
            {
                dp[i] = x;
                len[i] = 3;
            }
        }
    }
    if (dp[m] == -1)
    {
        cout << -1 << "\n";
        return;
    }
    vector<item> ans;
    while (m > 0)
    {
        if (len[m] == 3)
        {
            ans.push_back(d3[dp[m]]);
            m -= 3;
        }
        else
        {
            ans.push_back(d2[dp[m]]);
            m -= 2;
        }
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for (auto e : ans) cout << e.l + 1 << " " << e.r + 1 << " " << e.k + 1 << "\n";
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