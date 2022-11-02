#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n;
int a[N];
int dp[1 << 21][2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = n; i >= 1; --i) {
        if (dp[a[i]][0] == 0) {
            dp[a[i]][0] = i;
        } else if (dp[a[i]][1] == 0) {
            dp[a[i]][1] = i;
        }
    }
    for (int i = (1 << 21) - 1; i >= 0; --i) {
        for (int j = 0; j < 21; ++j) {
            if (i & (1 << j)) {
                int t = i ^ (1 << j);
                int x = dp[i][0];
                if (x > dp[t][0]) std::swap(x, dp[t][0]);
                dp[t][1] = std::max(dp[t][1], dp[i][1]);
                if (x != dp[t][0]) dp[t][1] = std::max(dp[t][1], x);
            }
        }
    }
    int ans = 0;
    for (int k = 20; k >= 0; --k) {
        bool ok = false;
        ans |= 1 << k;
        for (int i = 1; i <= n; ++i) ok |= dp[ans & ~a[i]][1] > i;
        if (!ok) ans ^= 1 << k;
    }
    std::cout << ans << std::endl;
    return 0;
}