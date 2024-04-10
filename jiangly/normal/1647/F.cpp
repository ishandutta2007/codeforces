#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto solve = [&](auto a) {
        int x = std::max_element(a.begin(), a.end()) - a.begin();
        
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i <= x; i++) {
            if (a[i] > mx1) {
                mx1 = a[i];
            } else if (a[i] > mx2) {
                mx2 = a[i];
            } else {
                return 0;
            }
        }
        
        int lmx = mx2;
        
        std::vector<int> rmx(n, 1E9 + 1);
        mx1 = mx2 = 0;
        for (int i = n - 1; i > x; i--) {
            if (a[i] > mx1) {
                mx1 = a[i];
                rmx[i] = mx2;
            } else if (a[i] > mx2) {
                mx2 = a[i];
                rmx[i] = mx1;
            } else {
                break;
            }
        }
        
        int ans = 0;
        std::array<int, 2> dp{lmx, 0};
        for (int i = x + 1; i < n; i++) {
            std::array<int, 2> ndp{int(1E9 + 1), 0};
            
            if (a[i] < a[i - 1]) {
                ndp[0] = std::min(ndp[0], dp[0]);
            }
            if (a[i] > a[i - 1]) {
                ndp[1] = std::max(ndp[1], dp[1]);
            }
            if (a[i] < dp[1]) {
                ndp[0] = std::min(ndp[0], a[i - 1]);
            }
            if (a[i] > dp[0]) {
                ndp[1] = std::max(ndp[1], a[i - 1]);
            }
            
            dp = ndp;
            
            if (dp[1] > rmx[i]) {
                ans++;
            }
        }
        
        return ans;
    };
    
    int ans = solve(a);
    
    std::reverse(a.begin(), a.end());
    
    ans += solve(a);
    
    std::cout << ans << "\n";
    
    return 0;
}