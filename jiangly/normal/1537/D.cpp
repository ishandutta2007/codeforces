#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n % 2 == 1 || ((n & (n - 1)) == 0 && __builtin_ctz(n) % 2 == 1)) {
            std::cout << "Bob\n";
        } else {
            std::cout << "Alice\n";
        }
    }
    return 0;
}