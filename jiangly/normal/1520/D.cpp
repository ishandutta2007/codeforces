#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> count(2 * n - 1);
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            x--;
            ans += count[x - i + n - 1]++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}