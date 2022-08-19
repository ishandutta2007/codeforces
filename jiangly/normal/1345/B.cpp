#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int ans = 0;
        while (n > 1) {
            int h = 1;
            while ((3 * h + 4) * (h + 1) / 2 <= n)
                ++h;
            n -= (3 * h + 1) * h / 2;
            ++ans;
        }
        std::cout << ans << "\n";
    }
    return 0;
}