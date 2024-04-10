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
        std::set<int> s;
        std::vector<int> x(n);
        for (int i = 0; i < n; i++) {
            std::cin >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                s.insert(x[i] - x[j]);
            }
        }
        std::cout << s.size() << "\n";
    }
    return 0;
}