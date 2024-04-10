#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::tuple<int, int, int> f2[10][10], f3[10][10][10];
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if (j + 2 <= m) {
                f2[s[j] - '0'][s[j + 1] - '0'] = {j + 1, j + 2, i + 1};
            }
            if (j + 3 <= m) {
                f3[s[j] - '0'][s[j + 1] - '0'][s[j + 2] - '0'] = {j + 1, j + 3, i + 1};
            }
        }
    }
    
    std::string s;
    std::cin >> s;
    std::vector<bool> dp(m + 1);
    dp[0] = true;
    for (int i = 0; i < m; i++) {
        if (!dp[i]) {
            continue;
        }
        if (i + 2 <= m && f2[s[i] - '0'][s[i + 1] - '0'] != std::tuple(0, 0, 0)) {
            dp[i + 2] = true;
        }
        if (i + 3 <= m && f3[s[i] - '0'][s[i + 1] - '0'][s[i + 2] - '0'] != std::tuple(0, 0, 0)) {
            dp[i + 3] = true;
        }
    }
    
    if (!dp[m]) {
        std::cout << "-1\n";
    } else {
        int i = m;
        std::vector<std::tuple<int, int, int>> ans;
        while (i) {
            if (i >= 2 && dp[i - 2] && f2[s[i - 2] - '0'][s[i - 1] - '0'] != std::tuple(0, 0, 0)) {
                ans.push_back(f2[s[i - 2] - '0'][s[i - 1] - '0']);
                i -= 2;
            } else {
                ans.push_back(f3[s[i - 3] - '0'][s[i - 2] - '0'][s[i - 1] - '0']);
                i -= 3;
            }
        }
        std::reverse(ans.begin(), ans.end());
        std::cout << ans.size() << "\n";
        for (auto [l, r, i] : ans) {
            std::cout << l << " " << r << " " << i << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}