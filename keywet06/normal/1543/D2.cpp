#include <bits/stdc++.h>

int T;

int knxor(int x, int y, int k) {
    int z = 0, p = 1;
    while (x > 0 || y > 0) {
        int a = x % k, b = y % k;
        x = x / k, y = y / k;
        int c = (a - b + k) % k;
        z = z + p * c;
        p = p * k;
    }
    return z;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                std::cout << 0 << std::endl;
            } else if (i % 2 == 0) {
                std::cout << knxor(i, i - 1, k) << std::endl;
            } else {
                std::cout << knxor(i - 1, i, k) << std::endl;
            }
            int v;
            std::cin >> v;
            if (v == 1) break;
        }
    }
    return 0;
}