#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        const int n = s.length();
        int ans = n + 1;
        int cnt[3] = {};
        for (int i = 0, j = 0; i < n; ++i) {
            while ((!cnt[0] || !cnt[1] || !cnt[2]) && j <= n) {
                if (j < n)
                    ++cnt[s[j] - '1'];
                ++j;
            }
            if (j > n)
                break;
            ans = std::min(ans, j - i);
            --cnt[s[i] - '1'];
        }
        if (ans > n) {
            std::cout << 0 << "\n";
        } else {
            std::cout << ans << "\n";
        }
    }
    return 0;
}