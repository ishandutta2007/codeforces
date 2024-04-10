#include <iostream>
#include <vector>
int t, n, m;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            sum += a;
        }
        std::cout << std::min(sum, m) << "\n";
    }
    return 0;
}