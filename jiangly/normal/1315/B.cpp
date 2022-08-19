#include <iostream>
#include <vector>
int t, a, b, p;
std::string s;
std::vector<long long> cost;
void solve() {
    std::cin >> a >> b >> p >> s;
    cost.resize(s.length());
    cost.back() = 0;
    s.back() = 'C';
    for (int i = int(s.length()) - 2; i >= 0; --i)
        cost[i] = cost[i + 1] + (s[i] == s[i + 1] ? 0 : s[i] == 'A' ? a : b);
    for (int i = 0; ; ++i) {
        if (cost[i] <= p) {
            std::cout << i + 1 << "\n";
            break;
        }
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