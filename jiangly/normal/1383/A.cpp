#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string a, b;
        std::cin >> a >> b;
        int cnt[20][20] = {};
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                ok = false;
            } else if (a[i] < b[i]) {
                ++cnt[a[i] - 'a'][b[i] - 'a'];
            }
        }
        if (!ok) {
            std::cout << -1 << "\n";
            continue;
        }
        int ans = 0;
        for (int j = 1; j < 20; ++j) {
            for (int i = 0; i < j; ++i) {
                if (cnt[i][j] > 0) {
                    ++ans;
                    for (int k = 0; k < 20; ++k) {
                        cnt[j][k] += cnt[i][k];
                        cnt[i][k] = 0;
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}