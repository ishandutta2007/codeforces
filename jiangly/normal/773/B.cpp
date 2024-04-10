#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector a(n, std::vector<int>(5));
    std::vector<int> pass(5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> a[i][j];
            if (a[i][j] >= 0) {
                pass[j]++;
            }
        }
    }
    
    
    int ans = -1;
    for (int mask = 0; mask < 7776; mask++) {
        std::vector<int> type(5);
        for (int i = 0, x = mask; i < 5; i++) {
            type[i] = x % 6;
            x /= 6;
        }
        
        int diff = 0;
        for (int i = 0; i < 5; i++) {
            if (a[0][i] >= 0) {
                diff += (type[i] + 1) * (250 - a[0][i]);
            }
            if (a[1][i] >= 0) {
                diff -= (type[i] + 1) * (250 - a[1][i]);
            }
        }
        
        if (diff <= 0) {
            continue;
        }
        
        int lo = 0, hi = 1e9;
        for (int i = 0; i < 5; i++) {
            lo = std::max(lo, (pass[i] << type[i]) - n);
            if (type[i] < 5) {
                if (a[0][i] < 0) {
                    hi = std::min(hi, (pass[i] << (type[i] + 1)) - 1 - n);
                } else {
                    lo = std::max(lo, (n - (pass[i] << (type[i] + 1)) + (1 << (type[i] + 1)) - 1) / ((1 << (type[i] + 1)) - 1));
                }
            }
        }
        
        if (lo > hi) {
            continue;
        }
        
        if (ans < 0 || ans > lo) {
            ans = lo;
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}