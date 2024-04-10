#include <iostream>

using int16 = short int;

const int N = 10005;

int16 lcp[N][N];

int dp[N];

bool is_greater(const std::string& s, int x, int y) {
    if (lcp[x][y] == static_cast<int>(s.size()) - x) {
        return false;
    }
    return s[x + lcp[x][y]] > s[y + lcp[x][y]];
}

int get_score(const std::string& s, int x, int y) {
    if (is_greater(s, x, y)) {
        return dp[y] + static_cast<int>(s.size()) - x - lcp[x][y];
    }
    return 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) lcp[i][j] = 0;
        }
        for (int i = n - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                if (i == j) {
                    lcp[i][j] = n - i;
                } else if (s[i] != s[j]) {
                    lcp[i][j] = 0;
                } else {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }
        int ans = n;
        dp[0] = n;
        for (int i = 1; i < n; ++i) {
            dp[i] = n - i;
            for (int j = 0; j < i; ++j) {
                dp[i] = std::max(dp[i], get_score(s, i, j));
            }
            ans = std::max(ans, dp[i]);
        }
        std::cout << ans << '\n';
    }
    return 0;
}