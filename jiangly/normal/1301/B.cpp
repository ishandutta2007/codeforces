#include <iostream>
#include <vector>
#include <cstdlib>
int t, n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int mx = std::numeric_limits<int>::min();
    int mn = std::numeric_limits<int>::max();
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == -1 && a[i + 1] != -1) {
            mx = std::max(mx, a[i + 1]);
            mn = std::min(mn, a[i + 1]);
        } else if (a[i] != -1 && a[i + 1] == -1) {
            mx = std::max(mx, a[i]);
            mn = std::min(mn, a[i]);
        } else {
            ans = std::max(ans, std::abs(a[i] - a[i + 1]));
        }
    }
    if (mx < mn) {
        std::cout << 0 << " " << 0 << "\n";
    } else {
        std::cout << std::max(ans, (mx - mn + 1) / 2) << " " << (mn + mx) / 2 << "\n";
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