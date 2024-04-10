#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t[5];
    int ans = 0, sum = 0;
    for (int i = 0; i < 5; ++i) {
        std::cin >> t[i];
        sum += t[i];
    }
    std::sort(t, t + 5);
    for (int i = 0; i < 4; ++i) {
        if (t[i] == t[i + 1]) {
            ans = std::max(ans, 2 * t[i]);
            if (i < 3 && t[i] == t[i + 2]) {
                ans = std::max(ans, 3 * t[i]);
            }
        }
    }
    std::cout << sum - ans << "\n";
    
    return 0;
}