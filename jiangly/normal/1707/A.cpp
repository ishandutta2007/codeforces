#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::string s(n, '0');
    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= a[i]) {
            s[i] = '1';
        } else if (x < q) {
            x++;
            s[i] = '1';
        }
    }
    
    std::cout << s << "\n";
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