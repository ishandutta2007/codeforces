#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> vis(n);
        for (int i = 0; i < 2 * n; ++i) {
            int x;
            std::cin >> x;
            if (!vis[x - 1])
                std::cout << x << " ";
            vis[x - 1] = 1;
        }
        std::cout << "\n";
    }
    return 0;
}