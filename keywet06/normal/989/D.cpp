#include <bits/stdc++.h>

std::vector<int> a, b;

int main() {
    int n, l, w;
    std::cin >> n >> l >> w;
    for (int i = 0; i < n; i++) {
        int x, z;
        std::cin >> x >> z;
        (z > 0 ? a : b).push_back(x);
    }
    long long ans = 0;
    std::sort(b.begin(), b.end());
    for (int x : a) {
        if (x < 0) {
            int t = (-x * 2) / (w + 1);
            ans += b.size() - (std::upper_bound(b.begin(), b.end(), x + t - l) - b.begin());
        } else {
            if (w > 1) {
                int t = (x * 2) / (w - 1);
                ans += b.size() - (std::upper_bound(b.begin(), b.end(), x + t - l) - b.begin());
            }
        }
    }
    std::cout << ans;
    return 0;
}