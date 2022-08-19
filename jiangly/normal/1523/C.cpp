#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<std::vector<int>> ans(n);
        ans[0] = {1};
        std::vector<int> stk{0};
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                ans[i] = ans[stk.back()];
                ans[i].push_back(1);
                stk.push_back(i);
            } else {
                while (ans[stk.back()].back() != a[i] - 1) {
                    stk.pop_back();
                }
                ans[i] = ans[stk.back()];
                ans[i].back()++;
                stk.back() = i;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < int(ans[i].size()); j++) {
                std::cout << ans[i][j] << ".\n"[j == int(ans[i].size()) - 1];
            }
        }
    }
    return 0;
}