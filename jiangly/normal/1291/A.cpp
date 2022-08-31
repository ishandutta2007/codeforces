#include <iostream>
#include <vector>
int t, n;
std::string s;
std::vector<int> odd;
void solve() {
    std::cin >> n >> s;
    odd.clear();
    for (char c : s)
        if (c % 2 == 1)
            odd.push_back(c - '0');
    if (int(odd.size()) < 2) {
        std::cout << -1 << "\n";
    } else {
        std::cout << odd[0] << odd[1] << "\n";
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