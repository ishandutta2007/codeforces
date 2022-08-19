#include <iostream>
int t, s;
void solve() {
    std::cin >> s;
    std::cout << s + (s - 1) / 9 << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}