#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        std::cout << 1 << " " << x - 1 << "\n";
    }
    return 0;
}