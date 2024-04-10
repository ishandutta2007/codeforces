#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::string s;
    std::cin >> s;
    
    int sum[n + 1];
    sum[0] = 1;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        if ((r - l) % 2 == 1) {
            std::cout << "1\n";
        } else if (sum[l] == sum[r]) {
            std::cout << "0\n";
        } else {
            std::cout << "2\n";
        }
    }
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