#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a, b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int ans = 0;
    for (int k = 0; k < 25; ++k) {
        for (int i = 0; i < n; ++i)
            b[i] = a[i] & ((1 << (k + 1)) - 1);
        std::sort(b.begin(), b.end());
        int d = 1 << k;
        long long cnt = 0;
        for (int i = n - 1, x = 0, y = 0, z = 0; i >= 0; --i) {
            while (x < n && b[x] + b[i] < d)
                ++x;
            while (y < n && b[y] + b[i] < 2 * d)
                ++y;
            while (z < n && b[z] + b[i] < 3 * d)
                ++z;
            cnt += std::max(0, std::min(i, y) - x);
            cnt += std::max(0, i - z);
        }
        if (cnt % 2 == 1)
            ans |= 1 << k;
    }
    std::cout << ans << "\n";
    return 0;
}