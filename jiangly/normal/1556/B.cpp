#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] %= 2;
        if (a[i] == 1) {
            p.push_back(i);
        }
    }
    
    i64 res = 1E18;
    
    for (int c = 0; c < 2; c++) {
        if (int(p.size()) != (n + 1 - c) / 2) {
            continue;
        }
        i64 v = 0;
        for (int i = 0; i < int(p.size()); i++) {
            v += std::abs(p[i] - (2 * i + c));
        }
        res = std::min(res, v);
    }
    
    if (res == 1E18) {
        res = -1;
    }
    std::cout << res << "\n";
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