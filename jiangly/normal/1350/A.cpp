#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        int p = 2;
        while (n % p)
            ++p;
        std::cout << n + p + 2 * (k - 1) << "\n";
    }
    return 0;
}