#include <bits/stdc++.h>

bool check(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int sum = std::accumulate(a.begin(), a.end(), 0);
        if (!check(sum)) {
            std::cout << n << "\n";
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << n - 1 << "\n";
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (flag && a[i] & 1) {
                    flag = false;
                } else {
                    std::cout << i + 1 << " ";
                }
            }
            std::cout << "\n";
        }
    }
}