#include <bits/stdc++.h>

using int64 = long long;

const int N = 2005;

int T, n, k, x, y, z, ans;
int a[N];
int dp[N][N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + (a[i] == i);
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = 
                    std::max(dp[i - 1][j] + (a[i] == i - j), dp[i - 1][j - 1]);
            }
        }
        ans = n + 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i][j] >= k) {
                    ans = std::min(ans, j);
                }
            }
        }
        std::cout << (ans == n + 1 ? -1 : ans) << '\n';
    }
    return 0;
}