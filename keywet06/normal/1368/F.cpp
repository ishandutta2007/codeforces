#include <bits/stdc++.h>

const int N = int(1e3) + 5;

int a[N], g[N];

int main() {
    int n;
    std::cin >> n;
    if (n >= 4) {
        int t = 0;
        int ans = 0;
        for (int i = 2; i <= n / 2; ++i) {
            int res = n - i - (n - 1) / i;
            if (res > ans) {
                ans = res;
                t = i;
            }
        }
        int step = (n - 1) / t + 1;
        for (int i = 0, j = 0; i < t; ++i) {
            g[j] = 1;
            j += (n - j) / (t - i);
        }
        while (std::accumulate(a, a + n, 0) < ans) {
            std::cout << step;
            for (int i = 0, j = step; i < n; ++i) {
                if (j && !a[i] && !g[i]) {
                    std::cout << " " << i + 1;
                    a[i] = 1;
                    --j;
                }
            }
            std::cout << std::endl;
            int z;
            std::cin >> z;
            --z;
            for (int i = 0; i < step; ++i) a[(z + i) % n] = 0;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}