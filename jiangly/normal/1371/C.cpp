#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int64_t a, b, n, m;
        std::cin >> a >> b >> n >> m;
        if (a + b >= n + m && std::min(a, b) >= m) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}