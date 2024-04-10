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
        bool neg = false;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (a[i] < 0) {
                neg = true;
            }
        }
        if (neg) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            std::cout << "101\n";
            for (int i = 0; i <= 100; i++) {
                std::cout << i << " \n"[i == 100];
            }
        }
    }
    return 0;
}