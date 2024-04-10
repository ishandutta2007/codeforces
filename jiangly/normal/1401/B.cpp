#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x1, y1, z1;
        std::cin >> x1 >> y1 >> z1;
        int x2, y2, z2;
        std::cin >> x2 >> y2 >> z2;
        int ans = 0;
        int x = std::min(z1, y2);
        ans += 2 * x;
        z1 -= x;
        y2 -= x;
        ans -= 2 * std::max(0, y1 + z2 - (x1 + y1 + z1));
        std::cout << ans << "\n";
    }
    return 0;
}