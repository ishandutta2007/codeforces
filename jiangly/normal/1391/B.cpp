#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            if (i < n - 1) {
                ans += (s.back() != 'D');
            } else {
                ans += std::count(s.begin(), s.end(), 'D');
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}