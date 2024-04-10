#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        int tot = 0;
        for (int i = 0; i < n; ++i)
            tot += s[i] - '0';
        int ans = 0;
        for (int b = 0; b < k; ++b) {
            int su = 0, mi = 0;
            for (int i = b; i < n; i += k) {
                su += (s[i] == '1' ? 1 : -1);
                mi = std::min(mi, su);
                ans = std::max(ans, su - mi);
            }
        }
        std::cout << tot - ans << "\n";
    }
    return 0;
}