#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int e2 = 0, e3 = 0;
        for (; n % 2 == 0; n /= 2)
            ++e2;
        for (; n % 3 == 0; n /= 3)
            ++e3;
        if (n > 1 || e2 > e3) {
            std::cout << -1 << "\n";
        } else {
            std::cout << 2 * e3 - e2 << "\n";
        }
    }
    return 0;
}