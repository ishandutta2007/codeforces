#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    if (n > 1) {
        std::cout << 1 << " " << n << "\n";
        for (int i = 0; i < n; ++i)
            std::cout << (i < n - 1 ? 1ll * a[i] * -n : 0ll) << " \n"[i == n - 1];
        std::cout << 1 << " " << n - 1 << "\n";
        for (int i = 0; i < n - 1; ++i)
            std::cout << 1ll * a[i] * (n - 1) << " \n"[i == n - 2];
    } else {
        std::cout << 1 << " " << 1 << "\n";
        std::cout << 0 << "\n";
        std::cout << 1 << " " << 1 << "\n";
        std::cout << 0 << "\n";
    }
    std::cout << n << " " << n << "\n";
    std::cout << -a[n - 1] << "\n";
    return 0;
}