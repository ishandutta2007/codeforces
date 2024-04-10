#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a;
    std::cin >> n >> a;
    --a;
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    int ans = t[a];
    for (int i = 1; i <= a || i + a < n; ++i) {
        if (i > a) {
            ans += t[i + a];
        } else if (i + a >= n) {
            ans += t[a - i];
        } else if (t[a + i] == 1 && t[a - i] == 1) {
            ans += 2;
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}