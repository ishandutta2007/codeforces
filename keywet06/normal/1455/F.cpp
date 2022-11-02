#include <bits/stdc++.h>

int n, k, T;

std::string a, b;

void update(std::string &a, const std::string &b) {
    if (a.empty() || a > b) a = b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        std::cin >> a;
        b = a;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 'a' + k - 1) {
                b[i] = 'a';
            } else if (b[i] != 'a') {
                --b[i];
            }
        }
        std::string dp[2][2];
        dp[0][0] = a;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur ^= 1;
            dp[cur][0] = dp[cur][1] = "";
            if (!dp[!cur][0].empty()) {
                auto &s = dp[!cur][0];
                update(dp[cur][0], s);
                if (i > 0) {
                    std::swap(s[i], s[i - 1]);
                    update(dp[cur][0], s);
                    std::swap(s[i], s[i - 1]);
                }
                if (i + 1 < n) {
                    std::swap(s[i], s[i + 1]);
                    update(dp[cur][1], s);
                    std::swap(s[i], s[i + 1]);
                }
                s[i] = b[i];
                update(dp[cur][0], s);
            }
            if (!dp[!cur][1].empty()) {
                auto &s = dp[!cur][1];
                update(dp[cur][0], s);
                if (i > 1) {
                    std::swap(s[i - 1], s[i - 2]);
                    update(dp[cur][0], s);
                    std::swap(s[i - 1], s[i - 2]);
                }
                s[i - 1] = b[i];
                update(dp[cur][0], s);
            }
        }
        std::cout << dp[cur][0] << "\n";
    }
    return 0;
}