#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int d = 1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                d = n / i;
                break;
            }
        }
        std::cout << d << " " << n - d << "\n";
    }
    return 0;
}