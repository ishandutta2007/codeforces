#include <iostream>
#include <algorithm>
int t, n, x;
std::string s;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> x >> s;
        int sum = n - 2 * int(std::count(s.begin(), s.end(), '1'));
        int ans = 0;
        for (int i = 0, balance = 0; i < n; ++i) {
            if (sum == 0) {
                if (x == balance)
                    ans = -1;
            } else if (1LL * (x - balance) * sum >= 0 && (x - balance) % sum == 0) {
                ++ans;
            }
            if (s[i] == '0') {
                ++balance;
            } else {
                --balance;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}