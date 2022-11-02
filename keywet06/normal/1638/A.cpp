// Luogu Remote

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1), r(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> a[i], r[a[i]] = i;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != i) {
                for (int j = r[i]; j >= i; --j) std::cout << a[j] << ' ';
                for (int j = r[i] + 1; j <= n; ++j) std::cout << a[j] << ' ';
                break;
            } else {
                std::cout << a[i] << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}