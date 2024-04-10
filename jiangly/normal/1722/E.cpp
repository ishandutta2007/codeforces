#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    int m = 0;
    std::vector<int> h(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i] >> w[i];
        m = std::max({m, h[i], w[i]});
    }
    std::vector sum(m + 1, std::vector<i64>(m + 1));
    for (int i = 0; i < n; i++) {
        sum[h[i]][w[i]] += h[i] * w[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int hs, ws, hb, wb;
        std::cin >> hs >> ws >> hb >> wb;
        
        hb = std::min(hb, m + 1);
        wb = std::min(wb, m + 1);
        hs = std::min(hs, hb - 1);
        ws = std::min(ws, wb - 1);
        
        auto ans = sum[hb - 1][wb - 1] - sum[hb - 1][ws] - sum[hs][wb - 1] + sum[hs][ws];
        std::cout << ans << "\n";
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