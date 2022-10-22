#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int a[n][m], dp[n][m], dp2[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 1e18;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                for (int i = x; i < n; i++) {
                    for (int j = y; j < m; j++) {
                        dp2[i][j] = 1e18;
                        if (i == x && j == y) {
                            dp2[i][j] = 0;
                            continue;
                        }
                        int k = a[x][y] + i - x + (j - 1) - y;
                        if (j != y && a[i][j] >= k + 1) {
                            dp2[i][j] = min(dp2[i][j - 1] + a[i][j] - (k + 1), dp2[i][j]);
                        }
                        if (i != x && a[i][j] >= k + 1) {
                            dp2[i][j] = min(dp2[i - 1][j] + a[i][j] - (k + 1), dp2[i][j]);
                        }
                    }
                }
                for (int i = x; i >= 0; i--) {
                    for (int j = y; j >= 0; j--) {
                        dp[i][j] = 1e18;
                        if (i == x && j == y) {
                            dp[i][j] = 0;
                            continue;
                        }
                        int k = a[x][y] + i - x + (j + 1) - y;
                        if (j != y && a[i][j] >= k - 1) {
                            dp[i][j] = min(dp[i][j + 1] + a[i][j] - (k - 1), dp[i][j]);
                        }
                        if (i != x && a[i][j] >= k - 1) {
                            dp[i][j] = min(dp[i + 1][j] + a[i][j] - (k - 1), dp[i][j]);
                        }
                    }
                }
                ans = min(ans, dp[0][0] + dp2[n - 1][m - 1]);
            }
        }
        cout << ans << endl;
    }
}