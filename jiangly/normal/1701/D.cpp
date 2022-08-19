#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::vector<int> l(n), r(n);
    std::vector<std::vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        l[i] = (i + 1) / (b[i] + 1) + 1;
        r[i] = b[i] == 0 ? n : (i + 1) / b[i];
        p[l[i] - 1].push_back(i);
    }
    
    std::vector<int> a(n);
    std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<>> h;
    for (int i = 1; i <= n; i++) {
        for (auto j : p[i - 1]) {
            h.push({r[j], j});
        }
        int j = h.top()[1];
        h.pop();
        a[j] = i;
    }
    
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