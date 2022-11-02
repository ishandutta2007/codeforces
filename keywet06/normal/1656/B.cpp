#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        int x;
        bool Ans = false;
        std::set<int> Set;
        while (n--) std::cin >> x, Ans |= Set.count(x + k) || Set.count(x - k), Set.insert(x);
        std::cout << (Ans ? "Yes" : "No") << '\n';
    }
    return 0;
}