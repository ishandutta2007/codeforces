#include <bits/stdc++.h>

using i64 = long long;

int pw[10];

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    int res = 2E9;
    
    for (int mask = 2; mask < (1 << 10); mask++) {
        if (__builtin_popcount(mask) != k) {
            continue;
        }
        
        int big = std::__lg(mask);
        int small = __builtin_ctz(mask);
        
        i64 x = 0;
        
        for (int i = 9; i >= 0; i--) {
            int d = n / pw[i] % 10;
            if ((mask >> d & 1) || (x == 0 && d == 0)) {
                if ((pw[i] - 1) / 9 * big >= n % pw[i]) {
                    x += 1LL * d * pw[i];
                    continue;
                }
            }
            d++;
            while (~mask >> d & 1) {
                d++;
            }
            x += 1LL * d * pw[i];
            x += (pw[i] - 1) / 9 * small;
            break;
        }
        
        res = std::min(1LL * res, x);
    }
    
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    pw[0] = 1;
    for (int i = 1; i <= 9; i++) {
        pw[i] = pw[i - 1] * 10;
    }
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}