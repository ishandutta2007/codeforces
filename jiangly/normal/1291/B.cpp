#include <iostream>
#include <vector>
int t, n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int l = 0, r = n;
    while (l < n && a[l] >= l)
        ++l;
    while (r > 0 && a[r - 1] >= n - r)
        --r;
    if (l > r) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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