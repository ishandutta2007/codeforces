#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int k = (2 * n + 1) / 3;
    std::cout << k << "\n";
    if (k == 1) {
        std::cout << "1 1\n";
    } else if (k % 2 == 1) {
        int t = k / 2;
        int even = t / 2, odd = t - t / 2;
        std::cout << even + 1 << " " << even + 1 << "\n";
        for (int i = 1; i <= even; i++) {
            std::cout << i << " " << 2 * even + 2 - i << "\n";
            std::cout << 2 * even + 2 - i << " " << i << "\n";
        }
        for (int i = 1; i <= odd; i++) {
            std::cout << 2 * even + 1 + i << " " << 2 * even + 1 + 2 * odd + 1 - i << "\n";
            std::cout << 2 * even + 1 + 2 * odd + 1 - i << " " << 2 * even + 1 + i << "\n";
        }
    } else {
        int t = k / 2 - 1;
        int even = t / 2, odd = t - t / 2;
        std::cout << even + 1 << " " << even + 1 << "\n";
        for (int i = 1; i <= even; i++) {
            std::cout << i << " " << 2 * even + 2 - i << "\n";
            std::cout << 2 * even + 2 - i << " " << i << "\n";
        }
        for (int i = 1; i <= odd; i++) {
            std::cout << 2 * even + 1 + i << " " << 2 * even + 1 + 2 * odd + 1 - i << "\n";
            std::cout << 2 * even + 1 + 2 * odd + 1 - i << " " << 2 * even + 1 + i << "\n";
        }
        std::cout << k << " " << k << "\n";
    }
    
    return 0;
}