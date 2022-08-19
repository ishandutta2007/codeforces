#include <iostream>
#include <vector>
#include <algorithm>
int t, n;
std::string s;
std::pair<std::string, int> ans;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> s;
        ans = {s, 1};
        for (int k = 2; k <= n; ++k) {
            int m = n - k + 1, x = m / 2 * 2;
            std::string t = s.substr(k - 1, x) + s.substr(0, k - 1) + s.substr(k - 1 + x, m % 2);
            if (m % 2 == 1)
                std::reverse(t.begin() + x, t.end());
            ans = std::min(ans, std::make_pair(t, k));
        }
        std::cout << ans.first << "\n";
        std::cout << ans.second << "\n";
    }
    return 0;
}