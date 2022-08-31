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
        if (a[0] + a[1] > a.back()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << 1 << " " << 2 << " " << n << "\n";
        }
    }
    return 0;
}