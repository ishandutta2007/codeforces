#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> pre;
    for (int i = 0; i < n; i++) {
        int len = std::max(int(pre.size()), (b[i] - 1) / 9 + 1) + 1;
        std::vector<int> dp(len + 1);
        dp[0] = b[i] + 1;
        pre.resize(len);
        for (int j = 0; j < len; j++) {
            dp[j + 1] = pre[j] + dp[j];
            if (pre[j] < 9) {
                dp[j + 1] = std::min(dp[j + 1], pre[j] + 1);
            }
        }
        std::vector<int> a(len);
        bool gr = false;
        for (int j = len - 1; j >= 0; j--) {
            if (gr) {
                a[j] = std::max(0, b[i] - 9 * j);
            } else if (pre[j] + dp[j] <= b[i] && pre[j] + 9 * j >= b[i]) {
                a[j] = pre[j];
            } else {
                a[j] = std::max(pre[j] + 1, b[i] - 9 * j);
                gr = true;
            }
            b[i] -= a[j];
        }
        assert(b[i] == 0);
        if (a.back() == 0) {
            len--;
            a.pop_back();
        }
        for (int i = len - 1; i >= 0; i--) {
            std::cout << a[i];
        }
        std::cout << "\n";
        pre = a;
    }
    return 0;
}