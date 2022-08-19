#include <iostream>
#include <vector>
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < i; ++j) {
            if (a[i] == a[j]) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    std::cout << "NO\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}