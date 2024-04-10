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

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

void solve()
{
    int n;
    cin >> n;
    vector<int> t(n);
    forn(i, n)
    {
        cin >> t[i];
    }
    sort(all(t));
    vector<vector<int> > dp(n + 1, vector<int>(2 * n + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            for (int p = 0; p < j; p++)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][p] + abs(t[i] - j));
            }
        }
    }
    int ans = INF;
    for (int l = 0; l <= 2 * n; l++)
    {
        ans = min(ans, dp[n][l]);
    }
    cout << ans << "\n";
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