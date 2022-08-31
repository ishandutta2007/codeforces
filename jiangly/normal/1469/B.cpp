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
        int mx0 = 0, mx1 = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            s += x;
            mx0 = std::max(mx0, s);
        }
        s = 0;
        int m;
        std::cin >> m;
        for (int i = 0; i < m; ++i) {
            int x;
            std::cin >> x;
            s += x;
            mx1 = std::max(mx1, s);
        }
        std::cout << mx0 + mx1 << "\n";
    }
    return 0;
}