#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int dp[31][31][51];

int solve(int n, int m, int k) {
    if (k > n * m ) return INF;
    if (k == n * m || k == 0) return 0;
    if (dp[n][m][k] != INF) return dp[n][m][k];
    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n - 1; j++) {
            dp[n][m][k] = min(dp[n][m][k], m * m + solve(j, m, i) + solve(n - j, m, k - i));
        }
        for (int j = 1; j <= m - 1; j++) {
            dp[n][m][k] = min(dp[n][m][k], n * n + solve(n, j, i) + solve(n, m - j, k - i));
        }
    }
    return dp[n][m][k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            for (int k = 0; k <= 50; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << '\n';
    }
}