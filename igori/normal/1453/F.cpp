#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int> > dp(n, vector<int>(n + 1, n + 1000));
    vector<vector<int> > lc(n, vector<int>(n + 1));
    vector<vector<int> > dpmn(n, vector<int>(n + 1, n + 1000));
    for (int j = 0; j < n; j++)
    {
        int C = 0;
        for (int i = j - 1; i >= 0; i--)
        {
            lc[i][j] = C;
            if (i + a[i] >= j)
                C++;
        }
    }
    dp[n - 1][n] = 0;
    dpmn[n - 1][n] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int to = i + a[i]; to > i; to--)
        {
            int cnt = lc[i][to];
            dp[i][to] = dpmn[to][max(i + a[i] + 1, to + 1)] + cnt;
            dpmn[i][to] = min(dpmn[i][to + 1], dp[i][to]);
        }
    }
    int ans = n + 1000;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, dp[0][i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}