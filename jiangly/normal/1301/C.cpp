#include <iostream>
int t, n, m;
void solve() {
    std::cin >> n >> m;
    int x = (n - m) / (m + 1), c = (n - m) % (m + 1);
    std::cout << 1LL * n * (n + 1) / 2 - 1LL * c * (x + 1) * (x + 2) / 2 - 1LL * (m + 1 - c) * x * (x + 1) / 2 << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}