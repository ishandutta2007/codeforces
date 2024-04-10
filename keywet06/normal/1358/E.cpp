#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int64 n, x, y, key, g = 1e16;
int64 v[N], s[N];
int64 ss[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    x = (n + 1) / 2, y = n - x;
    for (int i = 1; i <= x; ++i) std::cin >> v[i], s[i] = s[i - 1] + v[i];
    std::cin >> key;
    if (key < 0) {
        for (int i = 1; i <= x; ++i) {
            g = std::min(g, (s[x] - s[i - 1] - 1) / (-key) + x - (i - 1));
            if (y + x - (i - 1) <= g) {
                return std::cout << y + x - (i - 1) << std::endl, 0;
            }
        }
        return std::cout << -1 << std::endl, 0;
    } else {
        return std::cout << (s[x] + key * y > 0 ? n : -1) << std::endl, 0;
    }
    return 0;
}