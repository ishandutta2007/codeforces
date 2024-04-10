#include <iostream>
#include <vector>
int t, a, b, x, y;
void solve() {
    std::cin >> a >> b >> x >> y;
    std::cout << std::max(a * std::max(y, b - y - 1), b * std::max(x, a - x - 1)) << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}