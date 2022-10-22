#include<bits/stdc++.h>

using namespace std;

int K = 140, x[20000], y[20000];
int dp[20000], dp2[20000], DP[20000][143];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    n--;
    m--;
    int SZ = 0;
    for (int i = 0; i <= m; i++) if (i % K == 0) SZ++;
    for (int i = 0; i <= n; i++) cin >> x[i];
    for (int i = 0; i <= m; i++) cin >> y[i];
    auto get = [&] (int a, int b) {
        return (x[a] + y[b]) % p;
    };
    dp[0] = get(0, 0);
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + get(i, 0);
    int L[SZ];
    int g[SZ][n + 1];
    L[0] = 0;
    for (int i = 0; i <= n; i++) g[0][i] = dp[i];
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) dp2[j] = dp[j] + get(j, i);
            else dp2[j] = max(dp2[j - 1], dp[j]) + get(j, i);
        }
        for (int j = 0; j <= n; j++) dp[j] = dp2[j];
        if (i % K == 0) {
            L[i / K] = i;
            for (int j = 0; j <= n; j++) g[i / K][j] = dp[j];
        }
    }
    cout << dp[n] << endl;
    string ans = "";
    int N = n, M = m;
    for (int c = SZ - 1; c >= 0; c--) {
        for (int i = 0; i <= n; i++) DP[i][0] = g[c][i];
        for (int j = 1; j < m - L[c] + 1; j++) {
            for (int i = 0; i <= n; i++) {
                if (i == 0) DP[i][j] = DP[i][j - 1] + get(i, j + L[c]);
                else DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]) + get(i, j + L[c]);
            }
        }
        //cout << "START\n";
        //for (int i = 0; i <= n; i++) {
        //    for (int j = 0; j < m - L[c] + 1; j++) {
        //        cout << DP[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        while (m != L[c]) {
            if (n == 0 || DP[n][m - L[c] - 1] >= DP[n - 1][m - L[c]]) {
                ans += 'S';
                m--;
            }
            else {
                ans += 'C';
                n--;
            }
        }
    }
    while (ans.size() < N + M) ans += 'C';
    reverse(ans.begin(), ans.end());
    cout << ans;
}