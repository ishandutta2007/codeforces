#include <iostream>
int t, n;
void solve() {
    std::cin >> n;
    bool odd = false, even = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x % 2 == 0) {
            even = true;
        } else {
            odd = true;
        }
        sum += x;
    }
    if (sum % 2 == 1 || even && odd) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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