#include <bits/stdc++.h>

using int64 = long long;

const int N = 5005;

int T, n, tag[N], s[N];

int64 f[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> tag[i];
        for (int i = 1; i <= n; ++i) std::cin >> s[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                if (tag[i] == tag[j]) continue;
                int64 tmpi = f[i], tmpj = f[j], del = std::abs(s[i] - s[j]);
                f[i] = std::max(f[i], tmpj + del);
                f[j] = std::max(f[j], tmpi + del);
            }
        }
        std::cout << *std::max_element(f + 1, f + 1 + n) << '\n';
        for (int i = 1; i <= n; ++i) f[i] = 0;
    }
    return 0;
}