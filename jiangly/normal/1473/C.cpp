#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        int x = n - k;
        for (int i = 1; i <= k; i++) {
            if (i < k - x) {
                std::cout << i;
            } else {
                std::cout << k - x + k - i;
            }
            std::cout << " \n"[i == k];
        }
    }
    return 0;
}