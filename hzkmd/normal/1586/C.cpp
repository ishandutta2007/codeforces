#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> sum(m);
    for (int i = 1; i < n ; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') {
                ++sum[j];
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        sum[i] += sum[i - 1];
    }

    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l, --r;
        if (sum[r] == sum[l]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}