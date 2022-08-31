#include <iostream>
#include <vector>
int t, n, d;
std::vector<int> a;
void solve() {
    std::cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            if (d >= i) {
                d -= i;
                ++a[0];
            }
        }
    }
    std::cout << a[0] << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}