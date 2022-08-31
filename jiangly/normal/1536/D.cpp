#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }
        std::set<int> s{b[0]};
        bool bad = false;
        for (int i = 1; i < n; i++) {
            auto it = s.insert(b[i]).first;
            if (b[i] != b[i - 1] && *(b[i] > b[i - 1] ? std::prev(it) : std::next(it)) != b[i - 1]) {
                bad = true;
            }
        }
        std::cout << (bad ? "NO" : "YES") << "\n";
    }
    return 0;
}