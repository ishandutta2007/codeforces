#include <bits/stdc++.h>
constexpr int N = 1e5;
int n;
int s[N + 1], dp[N + 1];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> s[i];
        for (int i = 1; i <= n; ++i)
            dp[i] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 2 * i; j <= n; j += i)
                if (s[i] < s[j] && dp[i] >= dp[j])
                    dp[j] = dp[i] + 1;
        std::cout << *std::max_element(dp + 1, dp + n + 1) << "\n";
    }
    return 0;
}