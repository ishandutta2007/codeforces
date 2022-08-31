#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
int t, n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n);
    std::map<int, int> c;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        int x = __builtin_ctz(a[i]);
        int &y = c[a[i] >> x];
        y = std::max(y, x);
    }
    int ans = 0;
    for (auto &&[x, y] : c)
        ans += y;
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}