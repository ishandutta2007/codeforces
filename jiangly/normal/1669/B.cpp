#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        cnt[x]++;
    }
    
    for (int x = 0; x < n; x++) {
        if (cnt[x] >= 3) {
            std::cout << x + 1 << "\n";
            return;
        }
    }
    
    std::cout << "-1\n";
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