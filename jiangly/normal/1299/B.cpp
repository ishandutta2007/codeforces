#include <iostream>
#include <vector>
int n;
std::vector<int> x, y;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    if (n % 2 == 1) {
        std::cout << "NO\n";
        return 0;
    }
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];
    int x0 = x[0] + x[n / 2];
    int y0 = y[0] + y[n / 2];
    for (int i = 0; i < n / 2; ++i) {
        if (x[i] + x[i + n / 2] != x0 || y[i] + y[i + n / 2] != y0) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
    return 0;
}