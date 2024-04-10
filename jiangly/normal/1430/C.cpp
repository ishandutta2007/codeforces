#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::priority_queue<int> h;
        std::vector<std::pair<int, int>> ans;
        for (int i = 1; i <= n; ++i) h.push(i);
        for (int i = 0; i < n - 1; ++i) {
            int a = h.top();
            h.pop();
            int b = h.top();
            h.pop();
            ans.emplace_back(a, b);
            h.push((a + b + 1) / 2);
        }
        std::cout << h.top() << "\n";
        for (auto [a, b] : ans) std::cout << a << " " << b << "\n";
    }
    
    return 0;
}