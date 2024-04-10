#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
struct Node {
    int f, g, p;
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length();
    int m = t.length();
    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1, n));
    dp[0][0] = 0;
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + (s[i] == '.' ? -1 : 1);
    int cur = 0;
    for (int x = 0; x < m; ++x) {
        cur ^= 1;
        dp[cur].assign(n + 1, n);
        std::vector<Node> q;
        q.reserve(n);
        for (int i = 0; i < n; ++i) {
            int f = sum[i], g = dp[cur ^ 1][i];
            while (!q.empty() && q.back().f > f) {
                g = std::min(g, q.back().g + q.back().f - f);
                q.pop_back();
            }
            if (q.empty()) {
                q.push_back(Node{f, g, g});
            } else {
                q.push_back(Node{f, g, std::min(g, q.back().p)});
            }
            if (s[i] == t[x])
                dp[cur][i + 1] = q.back().p;
        }
    }
    int ans = n;
    for (int i = n, f = n; i >= 0; --i) {
        f = std::min(f, sum[i]);
        ans = std::min(ans, dp[cur][i] + sum[i] - f);
    }
    std::cout << sum[n] + 2 * ans - m << "\n";
    return 0;
}