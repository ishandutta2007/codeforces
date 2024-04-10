#include <bits/stdc++.h>

const int N = 105;

int T, n;
int a[N], b[N];

std::vector<int> c, d;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        c.clear(), d.clear();
        for (int i = 1; i <= n; ++i) {
            if (a[i] < b[i]) {
                for (int j = a[i]; j < b[i]; ++j) c.push_back(i);
            } else {
                for (int j = b[i]; j < a[i]; ++j) d.push_back(i);
            }
        }
        if (c.size() != d.size()) {
            std::cout << -1 << '\n';
        } else {
            std::cout << (n = c.size()) << '\n';
            for (int i = 0; i < n; ++i) {
                std::cout << d[i] << ' ' << c[i] << '\n';
            }
        }
    }
    return 0;
}