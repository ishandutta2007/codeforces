#include <iostream>
#include <vector>
#include <algorithm>
int t, n, x;
std::vector<int> a;
void solve() {
    std::cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    if (std::count(a.begin(), a.end(), x) > 0) {
        std::cout << 1 << "\n";
    } else {
        int m = *std::max_element(a.begin(), a.end());
        std::cout << std::max(2, (x + m - 1) / m) << "\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}