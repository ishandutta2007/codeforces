#include <iostream>
#include <vector>
#include <algorithm>
int t, n;
std::vector<int> num;
void solve() {
    std::cin >> n;
    std::cout << std::upper_bound(num.begin(), num.end(), n) - num.begin() << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            std::string s(i, '0' + j);
            num.push_back(std::atoi(s.c_str()));
        }
    }
    while (t--)
        solve();
    return 0;
}