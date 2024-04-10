#include <iostream>
#include <vector>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for (int i = n - 1, j = 1; i >= 1; --i) {
        x[i] = (81ll * (n - i - 1) % P + 180) * j % P;
        j = 10ll * j % P;
    }
    for (int i = 1; i < n; ++i)
        std::cout << x[i] << " ";
    std::cout << 10 << "\n";
    return 0;
}