#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> w(n);
        for (int i = 0; i < n; i++) {
            std::cin >> w[i];
        }
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        i64 sum = std::accumulate(w.begin(), w.end(), 0ll);
        std::vector<i64> a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < int(e[i].size()) - 1; j++) {
                a.push_back(w[i]);
            }
        }
        std::sort(a.begin(), a.end(), std::greater<>());
        std::cout << sum;
        for (int i = 0; i < n - 2; ++i) {
            sum += a[i];
            std::cout << " " << sum;
        }
        std::cout << "\n";
    }
    return 0;
}