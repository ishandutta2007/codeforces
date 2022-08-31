#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        int sum = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            mx = std::max(mx, a[i]);
        }
        if (sum % 2 == 0 && 2 * mx <= sum) {
            std::cout << "HL\n";
        } else {
            std::cout << "T\n";
        }
    }
    return 0;
}