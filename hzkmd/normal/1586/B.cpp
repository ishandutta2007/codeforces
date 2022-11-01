#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<bool> vis(n);
        for (int i = 0; i < m; ++i) {
            int x;
            std::cin >> x;
            std::cin >> x;
            --x;
            vis[x] = true;
            std::cin >> x;
        }
        int rt = std::find(vis.begin(), vis.end(), false) - vis.begin();
        for (int i = 0; i < n; ++i) {
            if (i != rt) {
                std::cout << rt + 1 << " " << i + 1 << "\n";
            }
        }
    }
}