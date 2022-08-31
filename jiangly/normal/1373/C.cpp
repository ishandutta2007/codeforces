#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        long long ans = 0;
        int sum = 0, mn = 0;
        for (auto c : s) {
            ans += mn;
            sum += c == '+' ? 1 : -1;
            mn = std::min(mn, sum);
        }
        ans += 1ll * int(s.length()) * (1 - mn);
        std::cout << ans << "\n";
    }
    return 0;
}