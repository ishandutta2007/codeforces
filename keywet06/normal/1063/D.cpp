#include <bits/stdc++.h>

using int64 = long long;
using ldou = long double;

int main() {
    int64 n, l, r, K;
    std::cin >> n >> l >> r >> K;
    int64 A = (r - l + n) % n + 1;
    if (K < A) {
        std::cout << -1 << std::endl;
        return 0;
    }
    if (n <= sqrt(K)) {
        for (int64 s = n; s >= 0; s--) {
            int64 t = (K - A) % (n + s);
            if (A + s - n - 1 <= t && t <= s && t <= A) {
                std::cout << s << std::endl;
                return 0;
            }
        }
        std::cout << -1 << std::endl;
        return 0;
    } else {
        int64 ans = -1;
        if (K <= A + A) ans = n + K + 1 - A - A;
        if (K == A + A) --ans;
        for (int64 d = 1; d * n <= K - A; d++) {
            int64 s = std::min((K - A - A + n + 1 - n * d) / (d + 1), (K - A - n * d) / d);
            int64 t = (K - A) % (n + s);
            if (A + s - n - 1 <= t && t <= s && t <= A) ans = std::max(ans, s);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}