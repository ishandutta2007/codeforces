#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int x, Num = 0;
        std::set<int> Set;
        bool Next = false;
        for (int i = 0; i < n; ++i) {
            std::cin >> x, Num += x == 1, Next |= Set.count(x - 1) | Set.count(x + 1), Set.insert(x);
        }
        std::cout << (Num == n || !(Num && Next) ? "Yes" : "No") << '\n';
    }
    return 0;
}