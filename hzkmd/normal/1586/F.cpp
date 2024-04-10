#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> a(n, std::vector<int>(n, -1));
    int idx = 0, len = 1;
    do {
        len *= k;
        for (int l = 0; l < n; l += len) {
            int r = std::min(n, l + len);
            for (int x = l; x < r; ++x) {
                for (int y = x + 1; y < r; ++y) {
                    if (a[x][y] == -1) {
                        a[x][y] = idx;
                    }
                }
            }
        }
        ++idx;
    } while (len < n);

    std::cout << idx << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::cout << a[i][j] + 1 << " ";
        }
    }
    std::cout << "\n";
}