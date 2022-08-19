#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n), cnt(n);
    std::vector<int> p;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        if (cnt[a[i]] <= k) {
            p.push_back(i);
        }
    }
    
    while (int(p.size()) % k != 0) {
        p.pop_back();
    }
    std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
    
    std::vector<int> ans(n);
    for (int i = 0; i < int(p.size()); i++) {
        ans[p[i]] = i % k + 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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