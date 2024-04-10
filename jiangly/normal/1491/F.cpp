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
        int x = -1;
        std::vector<int> ans;
        for (int i = 1; i < n; i++) {
            std::cout << "? " << i << " 1\n";
            for (int j = 0; j < i; j++) {
                std::cout << j + 1 << " \n"[j == i - 1];
            }
            std::cout << i + 1 << std::endl;
            int res;
            std::cin >> res;
            if (res != 0) {
                x = i;
                break;
            }
        }
        assert(x != -1);
        int l = 1, r = x;
        while (l < r) {
            int m = (l + r) / 2;
            std::cout << "? " << m << " 1\n";
            for (int i = 0; i < m; i++) {
                std::cout << i + 1 << " \n"[i == m - 1];
            }
            std::cout << x + 1 << std::endl;
            int res;
            std::cin >> res;
            if (res != 0) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        for (int i = 0; i < x; i++) {
            if (i != l - 1) {
                ans.push_back(i);
            }
        }
        for (int i = x + 1; i < n; i++) {
            std::cout << "? 1 1\n";
            std::cout << i + 1 << "\n";
            std::cout << x + 1 << std::endl;
            int res;
            std::cin >> res;
            if (res == 0) {
                ans.push_back(i);
            }
        }
        std::cout << "! " << ans.size();
        for (auto x : ans) {
            std::cout << " " << x + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}