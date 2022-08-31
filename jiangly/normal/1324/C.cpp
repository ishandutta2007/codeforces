#include <iostream>
#include <vector>
void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int j = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            ans = std::max(ans, i - j);
            j = i;
        }
    }
    ans = std::max(ans, n - j);
    std::cout << ans << "\n";
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