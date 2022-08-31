#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        
        bool ok = true;
        for (int j = 0; j <= k; j++) {
            if (s.find('0' + j) == std::string::npos) {
                ok = false;
            }
        }
        
        ans += ok;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}