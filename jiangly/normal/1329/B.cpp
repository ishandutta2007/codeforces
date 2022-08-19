#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int d, m;
        std::cin >> d >> m;
        std::vector<int> a{1};
        for (int i = 1; ; ++i) {
            if ((1 << i) > d) {
                a.push_back(d - (1 << (i - 1)) + 1);
                break;
            } else {
                a.push_back(1 << (i - 1));
            }
        }
        int n = a.size() - 1;
        int ans = 1 % m;
        for (int i = 1; i <= n; ++i) {
            int dp = 1ll * ans * a[i] % m;
            ans = (ans + dp) % m;
        }
        ans = (ans - 1 + m) % m;
        std::cout << ans << "\n";
    }
    return 0;
}