#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m], pref[n][m + 1];
    for (int i = 0; i < n; i++) {
        pref[i][0] = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pref[i][j + 1] = pref[i][j] + a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for (int i = 0; i < m; i++) {
        if (i + k - 1 >= m) break;
        dp[0][i] = pref[0][i + k] - pref[0][i];
    }
    for (int i = 1; i < n; i++) {
        vector<int> mxl(m, -1), mxr(m, -1);
        for (int j = 0; j + k - 1 < m; j++) {
            if (j) mxl[j] = mxl[j - 1];
            mxl[j] = max(mxl[j], dp[i - 1][j] + pref[i][j + k] - pref[i][j]);
        }
        for (int j = m - k; j >= k - 1; j--) {
            if (j != m - 1) mxr[j] = mxr[j + 1];
            mxr[j] = max(mxr[j], dp[i - 1][j] + pref[i][j + k] - pref[i][j]);
        }
        for (int j = 0; j + k - 1 < m; j++) {
            if (j >= k && mxl[j - k] != -1) {
                dp[i][j] = max(dp[i][j], mxl[j - k] + pref[i][j + k] - pref[i][j]);
            }
            if (j + k < m && mxr[j + k] != -1) {
                dp[i][j] = max(dp[i][j], mxr[j + k] + pref[i][j + k] - pref[i][j]);
            }
            for (int j2 = max(0, j - k + 1); j2 <= j + k - 1 && j2 + k - 1 < m; j2++) {
                int l = min(j, j2), r = max(j, j2) + k - 1;
                if (dp[i - 1][j2] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j2] + pref[i][r + 1] - pref[i][l]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) ans = max(ans, dp[n - 1][i]);
    cout << ans;
}