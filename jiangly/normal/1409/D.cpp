#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a[19] = {};
        int64_t n;
        int s;
        std::cin >> n >> s;
        int64_t x = n;
        int sum = 0;
        for (int i = 0; i < 19; ++i) {
            a[i] = x % 10;
            x /= 10;
            sum += a[i];
        }
        int p = 0;
        while (sum > s) {
            if (a[p] == 0) {
                ++p;
                continue;
            }
            sum -= a[p];
            a[p] = 0;
            for (int i = p + 1; ; ++i) {
                if (a[i] == 9) {
                    a[i] = 0;
                    sum -= 9;
                } else {
                    ++a[i];
                    ++sum;
                    break;
                }
            }
            ++p;
        }
        x = 0;
        for (int i = 18; i >= 0; --i)
            x = 10 * x + a[i];
        std::cout << x - n << "\n";
    }
    return 0;
}