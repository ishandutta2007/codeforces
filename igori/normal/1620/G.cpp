const int MOD = 998244353;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<int> > cnt(26, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            forn(ii, s[i].size()) if (s[i][ii] == c) cnt[c - 'a'][i]++;
        }
    }
    vector<int> dp(1 << n);
    for (int mask = 1; mask < (1 << n); mask++)
    {
        dp[mask] = 1;
        for (int c = 0; c < 26; c++)
        {
            int mn = 1e9;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) mn = min(mn, cnt[c][i]);
            dp[mask] = 1ll * dp[mask] * (mn + 1) % MOD;
        }
        if (popcount(mask) % 2 == 0)
            dp[mask] = MOD - dp[mask];
    }
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if ((1 << i) & mask)
            {
                dp[mask] = (dp[mask] + dp[mask - (1 << i)]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ll r = dp[i];
        r = r * popcount(i);
        ll s = 0;
        for (int j = 0; j < n; j++) if ((1 << j) & i)
            s = s + j + 1;
        ans ^= r * s;
    }
    cout << ans << "\n";
}