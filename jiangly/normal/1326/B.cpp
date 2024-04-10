#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];
    long long x = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << x + b[i] << " \n"[i == n - 1];
        x = std::max(x, x + b[i]);
    }
    return 0;
}