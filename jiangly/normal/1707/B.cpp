#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    
    while (n - (cnt.count(0) ? cnt[0] : 0) > 1) {
        std::map<int, int> nc;
        int last = -1;
        n--;
        for (auto [x, c] : cnt) {
            if (c > 1) {
                nc[0] += c - 1;
            }
            if (last != -1) {
                nc[x - last]++;
            }
            last = x;
        }
        cnt = nc;
    }
    
    cnt.erase(0);
    std::cout << (cnt.empty() ? 0 : cnt.begin()->first) << "\n";
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