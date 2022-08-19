#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        for (int i = n - 1; ; --i) {
            if (k > n - i - 1) {
                k -= n - i - 1;
            } else {
                std::cout << std::string(i, 'a') + 'b' + std::string(n - k - i - 1, 'a') + 'b' + std::string(k - 1, 'a') << "\n";
                break;
            }
        }
    }
    return 0;
}