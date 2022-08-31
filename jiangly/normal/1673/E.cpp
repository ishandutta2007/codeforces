#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::string ans(1 << 20, '0');
    
    for (int i = 0; i < n; i++) {
        int p = b[i];
        for (int j = i; j < n; j++) {
            if (j > i) {
                if (b[j] >= 20) {
                    break;
                }
                if (((1LL * p) << b[j]) >= (1 << 20)) {
                    break;
                }
                p <<= b[j];
            }
            
            int free = n - 1 - (j - i) - (i > 0) - (j < n - 1);
            int least = std::max(0, k - (i > 0) - (j < n - 1));
            
            if (least > free) {
                continue;
            }
            
            if (free == 0) {
                ans[(1 << 20) - p - 1] ^= 1;
                continue;
            }
            
            int t = __builtin_ctz(free);
            if (least & ((1 << t) - 1)) {
                least &= ~((1 << t) - 1);
                least += 1 << t;
            }
            
            if ((least & free) == least && (least >> t & 1)) {
                ans[(1 << 20) - p - 1] ^= 1;
            }
            
        }
    }
    
    int i = 0;
    while (i < (1 << 20) - 1 && ans[i] == '0') {
        i++;
    }
    
    std::cout << ans.substr(i) << "\n";
    
    return 0;
}