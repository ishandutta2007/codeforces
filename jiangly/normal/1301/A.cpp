#include <iostream>
int t;
std::string a, b, c;
void solve() {
    std::cin >> a >> b >> c;
    for (int i = 0; i < int(a.length()); ++i) {
        if (a[i] != c[i] && b[i] != c[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}