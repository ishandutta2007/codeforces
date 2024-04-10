#include <bits/stdc++.h>
void chkmax(int &a, int b) {
    a = std::max(a, b);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    char a, b;
    std::cin >> a >> b;
    std::vector<std::vector<std::vector<int>>> dp(n + 1);
    for (int i = 0; i <= n; ++i)
        dp[i].assign(n + 1, std::vector<int>(n + 1, -1e9));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k && j <= i; ++j) {
            for (int c = 0; c <= i; ++c) {
                chkmax(dp[i + 1][j][c + (s[i] == a)], dp[i][j][c] + (s[i] == b) * c);
                if (j < k) {
                    chkmax(dp[i + 1][j + 1][c + 1], dp[i][j][c] + (a == b) * c);    
                    chkmax(dp[i + 1][j + 1][c + (a == b)], dp[i][j][c] + c);
                }
            }
        }
    }
    std::cout << *std::max_element(dp[n][k].begin(), dp[n][k].end()) << "\n";
    return 0;
}