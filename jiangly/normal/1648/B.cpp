#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, c;
    std::cin >> n >> c;
    
    std::vector<int> cnt(c + 1), sum(c + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= c; i++) {
        sum[i] = sum[i - 1] + cnt[i];
    }
    
    for (int y = 1; y <= c; y++) {
        if (!cnt[y]) {
            continue;
        }
        
        for (int i = 1; i * y <= c; i++) {
            int r = std::min(c, i * y + y - 1);
            if (sum[r] - sum[i * y - 1] > 0) {
                if (cnt[i] == 0) {
                    std::cout << "No\n";
                    return;
                }
            }
        }
    }
    
    std::cout << "Yes\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}