#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::string s;
std::vector<int> dp, f;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> s;
    f.assign(26, 0);
    dp.resize(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = s[i] - 'a' + 1; j < 26; ++j)
            dp[i] = std::max(dp[i], f[j] + 1);
        f[s[i] - 'a'] = dp[i];
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << dp[i] << " \n"[i == n - 1];
    return 0;
}