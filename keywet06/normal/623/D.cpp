#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cout.precision(15);
    std::cout << std::fixed;
    int n;
    while (std::cin >> n) {
        double start = clock() / (double)CLOCKS_PER_SEC;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<double> b(n);
        for (int i = 0; i < n; ++i) b[i] = (100 - a[i]) / 100.0;
        std::vector<double> p(n, 1.0);
        int turns = 0;
        double sum = 0;
        while (1) {
            double win = 1.0;
            for (int i = 0; i < n; ++i) win *= 1 - p[i];
            sum += 1 - win;
            if (turns % 100 == 0) {
                if (clock() / (double)CLOCKS_PER_SEC - start > 1.5) {
                    std::cout << sum << std::endl;
                    break;
                }
            }
            int id = 0;
            for (int i = 1; i < n; ++i) {
                if ((1 - p[i] * b[i]) * (1 - p[id]) > (1 - p[id] * b[id]) * (1 - p[i])) id = i;
            }
            p[id] *= b[id];
            if (p[id] < 1e-30) p[id] = 0;
            ++turns;
        }
    }
    return 0;
}