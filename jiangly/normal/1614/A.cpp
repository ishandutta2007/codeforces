#include <bits/stdc++.h>

void solve() {
    int n, l, r, k;
    std::cin >> n >> l >> r >> k;
    
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (l <= x && x <= r) {
            a.push_back(x);
        }
    }
    std::sort(a.begin(), a.end());
    
    int res = 0;
    for (auto x : a) {
        if (k >= x) {
            res++;
            k -= x;
        }
    }
    
    std::cout << res << '\n';
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