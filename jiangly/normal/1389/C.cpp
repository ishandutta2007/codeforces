#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();
        int ans = n;
        int cnt[10] = {};
        for (auto c : s)
            ++cnt[c - '0'];
        for (int i = 0; i < 10; ++i)
            ans = std::min(ans, n - cnt[i]);
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                int res = 0;
                for (auto c : s)
                    if (c - '0' == (res & 1 ? y : x))
                        ++res;
                res &= ~1;
                res = n - res;
                ans = std::min(ans, res);
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}