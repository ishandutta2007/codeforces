#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::vector<int> a(m);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (s[i + 1][j] == 'X' && s[i][j + 1] == 'X') {
                a[j + 1]++;
            }
        }
    }
    for (int j = 1; j < m; j++) {
        a[j] += a[j - 1];
    }
    
    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        r--;
        std::cout << (a[l] == a[r] ? "YES" : "NO") << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}