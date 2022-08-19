#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n <= 30) {
            std::cout << "NO\n";
        } else if (n == 36 || n == 40 || n == 44) {
            std::cout << "YES\n";
            std::cout << 6 << " " << 10 << " " << 15 << " " << n - 31 << "\n";
        } else {
            std::cout << "YES\n";
            std::cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << "\n";
        }
    }
    return 0;
}