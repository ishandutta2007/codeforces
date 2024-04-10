#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::set<int64_t> s{0};
    int64_t sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        int64_t ns = sum + x;
        if (s.count(ns)) {
            ++ans;
            s = {sum};
        }
        s.insert(sum = ns);
    }
    std::cout << ans << "\n";
    
    return 0;
}