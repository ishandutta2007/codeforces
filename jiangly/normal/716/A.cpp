#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, c;
    std::cin >> n >> c;
    
    std::vector<int> t(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        if (i > 0 && t[i] - t[i - 1] <= c) {
            ans++;
        } else {
            ans = 1;
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}