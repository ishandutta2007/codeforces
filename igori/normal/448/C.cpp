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
    int n;
    cin >> n;
    vector<int> a(n + 2);
    forn(i, n) cin >> a[i + 1];
    vector<int> dp(n + 2);
    for (int i = 1; i <= n + 1; i++)
    {
        dp[i] = 1e9;
        int mn = a[i];
        for (int lst = i - 1; lst >= 0; lst--)
        {
            mn = min(mn, a[lst]);
            dp[i] = min(dp[i], (i - lst - 1) + dp[lst] + a[i] - mn);
        }
    }
    cout << dp[n + 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}