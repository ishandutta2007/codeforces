#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::string s;
    std::cin >> s;
    
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    }
    
    std::vector<int> p[4 * n + 1];
    for (int i = 0; i < n; i++) {
        p[sum[i] + sum[i + 1] + 2 * n].push_back(i);
    }
    
    auto get = [&](int l, int r) {
        int x = sum[l] + sum[r] + 2 * n;
        auto it = std::lower_bound(p[x].begin(), p[x].end(), l);
        assert(it != p[x].end() && *it < r);
        return *it;
    };
    
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        if ((r - l) % 2 == 1) {
            std::cout << "1\n";
            std::cout << get(l, r) + 1 << "\n";
        } else if (sum[l] == sum[r]) {
            std::cout << "0\n";
        } else {
            std::cout << "2\n";
            std::cout << l + 1 << " " << get(l + 1, r) + 1 << "\n";
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