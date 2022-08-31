#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            a = std::abs(a);
            std::cout << (i % 2 == 0 ? a : -a) << " \n"[i == n - 1];
        }
    }
    return 0;
}