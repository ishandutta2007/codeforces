#include <bits/stdc++.h>

void solve() {
    int n;
    int64_t w;
    std::cin >> n >> w;
    std::vector<int> x;
    bool ok = false;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a > w || ok) continue;
        if (2 * a >= w) {
            x = {i};
            ok = true;
            continue;
        }
        sum += a;
        x.push_back(i);
        if (2 * sum >= w) ok = true;
    }
    if (ok) {
        std::cout << x.size() << "\n";
        for (int j = 0; j < int(x.size()); ++j) std::cout << x[j] + 1 << " \n"[j == int(x.size()) - 1];
    } else {
        std::cout << -1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) solve();
    
    return 0;
}