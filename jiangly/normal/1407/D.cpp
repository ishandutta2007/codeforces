#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];
    std::vector<int> dp(n, n);
    dp[0] = 0;
    std::vector<int> s{0}, p{0};
    for (int i = 1; i < n; ++i) {
        dp[i] = std::min(dp[i - 1], dp[i - 1]) + 1;
        while (!s.empty() && h[i] >= h[s.back()]) {
            int x = h[s.back()];
            s.pop_back();
            if (h[i] > x && !s.empty())
                dp[i] = std::min(dp[i], dp[s.back()] + 1);
        }
        while (!p.empty() && h[i] <= h[p.back()]) {
            int x = h[p.back()];
            p.pop_back();
            if (h[i] < x && !p.empty())
                dp[i] = std::min(dp[i], dp[p.back()] + 1);
        }
        s.push_back(i);
        p.push_back(i);
    }
    std::cout << dp[n - 1] << "\n";
    return 0;
}