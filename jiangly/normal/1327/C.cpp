#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string ans = std::string(n - 1, 'U') + std::string(m - 1, 'L');
    for (int i = 0; i < n; ++i) {
        ans += std::string(m - 1, "RL"[i % 2]);
        if (i != n - 1)
            ans += 'D';
    }
    std::cout << ans.length() << "\n";
    std::cout << ans << "\n";
    return 0;
}