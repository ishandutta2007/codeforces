#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        
        int ans;
        
        if (n % 2 == 1) {
            ans = 2;
            for (int i = 0; i < n; i += 2)
                if (s[i] % 2 == 1)
                    ans = 1;
        } else {
            ans = 1;
            for (int i = 1; i < n; i += 2)
                if (s[i] % 2 == 0)
                    ans = 2;
        }
        
        std::cout << ans << "\n";
    }
    
    return 0;
}