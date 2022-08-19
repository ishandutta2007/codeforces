#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    if (k & 1) {
        for (int i = 0; i < n; i++) {
            s[i] ^= 1;
        }
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && k > 0) {
            s[i] = '1';
            k--;
            a[i] = 1;
        }
    }
    a[n - 1] += k;
    if (k & 1) {
        s[n - 1] ^= 1;
    }
    
    std::cout << s << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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