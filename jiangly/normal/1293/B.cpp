#include <iostream>
#include <iomanip>
int n;
double ans;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        ans += 1.0 / i;
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
    return 0;
}