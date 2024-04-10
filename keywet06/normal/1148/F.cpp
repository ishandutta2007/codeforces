#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> val(n);
    std::vector<long long> mask(n);
    for (int i = 0; i < n; ++i) std::cin >> val[i] >> mask[i];
    long long sum = std::accumulate(val.begin(), val.end(), 0LL);
    long long s = 0;
    for (int k = 0; k < 62; ++k) {
        long long x = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask[i] >> k) == 1) x += val[i];
        }
        if (1.0 * sum * x > 0) {
            s |= 1LL << k;
            for (int i = 0; i < n; ++i) {
                if (mask[i] >> k & 1) val[i] = -val[i];
            }
        }
    }
    std::cout << s << std::endl;
    return 0;
}