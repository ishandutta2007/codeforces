const long long INFLL = 1e18;
const long long MOD = 998244353;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2);
    forn(i, n) cin >> a[i + 1];

    if (0)
    {
        vector<int> d;
        forn(i, n) d.push_back(a[i + 1]);
        int ans = 0;
        while (1)
        {
            int ok = 1;
            for (int i = 1; i + 2 < n; i += 2) if (d[i] >= d[i + 2]) ok = 0;
            for (int i = 0; i + 1 < n; i += 2) if (d[i] >= d[i + 1]) ok = 0;
            for (int i = 1; i + 1 < n; i += 2) if (d[i] <= d[i + 1]) ok = 0;
            ans += ok;
            if (ok) {forn(i, n) cout << d[i] << " "; cout << "\n";}
            if (!next_permutation(d.begin(), d.end()))
                break;
        }
        cout << ans << "\n";
    }

    vector<ll> fact(n + 2), ufact(n + 2), rev(n + 2);
    rev[1] = 1;
    for (int i = 2; i <= n; i++) rev[i] = MOD - (MOD / i) * rev[MOD % i] % MOD;
    fact[0] = ufact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD, ufact[i] = ufact[i - 1] * rev[i] % MOD;

    vector<int> cnt(n + 2);
    forn(i, n) cnt[a[i]]++;

    vector<vector<vector<int> > > dp(n + 2, vector<vector<int> >(n / 2 + 2, vector<int>(2)));
    dp[n][1][1] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int c = 1; c <= n / 2; c++)
        {
            if (a[i] < a[i + 1])
            {
                // place this block
                dp[i][c][1] = (dp[i][c][1] + 1ll * (dp[i + 1][c - 1][0] + dp[i + 1][c - 1][1])) % MOD;
                // free this block
                int allpos = c - 1 + (c == n / 2);
                int freepos = allpos - (n - i - c);
                if (freepos >= 0)
                dp[i][c][0] = (dp[i][c][0] + 1ll * (dp[i + 1][c][0] + dp[i + 1][c][1]) * freepos) % MOD;
            }
            else
            {
                // place this block
                dp[i][c][1] = (dp[i][c][1] + dp[i + 1][c - 1][0]) % MOD;
                // free this block
                for (int fl = 0; fl <= 1; fl++)
                {
                    int allpos = c - 1 + (c == n / 2);
                    int freepos = allpos - (n - i - c) - (fl == 1) * (1 + (c == n / 2));
                    if (freepos >= 0)
                    dp[i][c][fl] = (dp[i][c][fl] + 1ll * (dp[i + 1][c][fl]) * freepos) % MOD;
                }
            }
            //cout << i << " " << c << " : " << dp[i][c][0] << " " << dp[i][c][1] << "\n";
        }
    }

    ll ans = (dp[1][n / 2][0] + dp[1][n / 2][1]) % MOD;
    //cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        ans = ans * ufact[cnt[i]] % MOD;
    }
    cout << ans << "\n";
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