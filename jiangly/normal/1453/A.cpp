#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::set<int> s;
        std::cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n + m; ++i) {
            int x;
            std::cin >> x;
            if (s.count(x)) {
                ++ans;
            } else {
                s.insert(x);
            }
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}