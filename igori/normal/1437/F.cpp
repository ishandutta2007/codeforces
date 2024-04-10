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

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL

    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    vi cap(n);
    forn(i, n) forn(j, n) if (2 * a[j] <= a[i]) cap[i]++;
    if (cap.back() != n - 1)
    {
        cout << 0;
        return 0;
    }

    vvi dp(n + 1, vi(n + 1));
    vvi suf(n + 1, vi(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = 1;
        suf[i + 1][0] = (suf[i][0] + dp[i + 1][0]) % MOD;
        for (int j = 1; j <= cap[i]; j++)
        {
            dp[i + 1][j] = (dp[i + 1][j] + 1ll * dp[i + 1][j - 1] * (cap[i] - j + 1)) % MOD;
            dp[i + 1][j] = (dp[i + 1][j] + suf[cap[i]][j - 1]) % MOD;
            suf[i + 1][j] = (suf[i][j] + dp[i + 1][j]) % MOD;
        }
    }
    cout << dp[n][n - 1] % MOD << "\n";
}