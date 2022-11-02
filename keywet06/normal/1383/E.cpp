#include <bits/stdc++.h>

constexpr int P = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::vector<int> p{-1};
    int n = s.length();
    for (int i = 0; i < n; ++i)
        if (s[i] == '1') p.push_back(i);
    p.push_back(n);
    std::vector<int> c;
    for (int i = 0; i + 1 < int(p.size()); ++i)
        c.push_back(p[i + 1] - p[i] - 1);
    if (c.size() == 1) {
        std::cout << n << "\n";
        return 0;
    }
    int ans = 1ll * (c[0] + 1) * (c.back() + 1) % P;
    c.pop_back();
    c.erase(c.begin());
    int m = c.size();
    std::vector<int> dp(m + 1), pre(m + 1);
    dp[0] = pre[0] = 1;
    std::vector<int> stk;
    for (int i = 0; i < m; ++i) {
        dp[i + 1] = 1ll * dp[i] * (c[i] + 1) % P;
        while (!stk.empty() && c[i] > c[stk.back()]) {
            int v = c[stk.back()];
            int sum = pre[stk.back()];
            stk.pop_back();
            if (!stk.empty()) sum = (sum - pre[stk.back()] + P) % P;
            dp[i + 1] = (dp[i + 1] + 1ll * sum * (c[i] - v)) % P;
        }
        pre[i + 1] = (pre[i] + dp[i + 1]) % P;
        stk.push_back(i);
    }
    std::cout << 1ll * ans * pre[m] % P << "\n";
    return 0;
}