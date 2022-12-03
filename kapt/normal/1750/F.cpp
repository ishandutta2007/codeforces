#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 5e3 + 100;
int dp[MAXN][MAXN], sum[2 * MAXN];
int rated[MAXN];

main() {
    int n, m;
    cin >> n >> m;
    rated[1] = rated[2] = 1;
    for (int i = 3; i <= n; ++i) {
        rated[i] = (rated[i - 1] * 2) % m;
    }
    for (int s = 1; s <= 2 * n; ++s) {
        sum[s] = sum[s - 1];
        for (int len = 1; len * 2 <= s; ++len) {
            int i = s - len;
            if (i > n) continue;
            if (i == len) {
                dp[i][len] = rated[len];
                sum[s] += dp[i][len];
                sum[s] %= m;
            } else {
                if (i - 2 * len - 1 >= 0) {
                    dp[i][len] = sum[i - 2 * len - 1] * rated[len];
                    dp[i][len] %= m;
                    rated[i] -= dp[i][len];
                    rated[i] = (rated[i] % m + m) % m;
                    sum[s] += dp[i][len];
                    sum[s] %= m;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n - 2; ++i) {
        ans *= 2;
        ans %= m;
    }
    for (int len = 1; len < n; ++len) {
        ans -= dp[n][len];
        ans = (ans % m + m) % m;
    }
    cout << ans;
    return 0;
}