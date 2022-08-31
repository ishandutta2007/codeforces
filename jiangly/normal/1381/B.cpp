#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(2 * n);
        for (int i = 0; i < 2 * n; ++i)
            std::cin >> p[i];
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < 2 * n; ) {
            int j = i;
            while (j < 2 * n && p[j] <= p[i])
                ++j;
            int s = j - i;
            for (int k = n; k >= s; --k)
                dp[k] |= dp[k - s];
            i = j;
        }
        if (dp[n]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}