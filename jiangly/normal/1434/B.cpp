#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a;
    int cnt = 0;
    std::vector<int> ans(n);
    for (int i = 0; i < 2 * n; ++i) {
        char op;
        std::cin >> op;
        if (op == '+') a.emplace_back(cnt++, 0);
        else {
            int v;
            std::cin >> v;
            if (a.empty() || a.back().second > v) {
                std::cout << "NO\n";
                return 0;
            }
            ans[a.back().first] = v;
            a.pop_back();
            if (!a.empty() && v > a.back().second) a.back().second = v;
        }
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}