// lg
#include <iostream>
#include <vector>
#include <algorithm>
int t, n, m;
std::vector<int> a;
std::vector<bool> ok;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        a.resize(n);
        ok.assign(n + 1, false);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        for (int i = 0; i < m; ++i) {
            int p;
            std::cin >> p;
            ok[p] = true;
        }
        for (int i = 1, j = 0; i <= n; ++i) {
            if (!ok[i]) {
                std::sort(a.begin() + j, a.begin() + i);
                j = i;
            }
        }
        if (std::is_sorted(a.begin(), a.end())) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}