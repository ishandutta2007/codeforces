#include <bits/stdc++.h>

using int64 = long long;

namespace oct {

void sync();

inline void ios() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

}  // namespace oct

int T, n, m;
int64 x, y, a, b;

inline int64 ps(int64 x, int64 y, int64 P) {
    int64 z = 0;
    while (y) {
        z = y & 1 ? z + x : z;
        x <<= 1, y >>= 1, x = x >= P ? x - P : x, z = z >= P ? z - P : z;
    }
    return z;
}
inline int64 pm(int64 x, int64 y, int64 P) {
    int64 z = 1;
    x %= P;
    while (y) z = y & 1 ? ps(z, x, P) : z, x = ps(x, x, P), y >>= 1;
    return z;
}

int main() {
    oct::ios();
    std::cin >> T;
    while (T--) {
        std::cin >> a;
        int64 t = a, m1 = 1;
        n = 0;
        while (t) t /= 10, n++;
        for (m = 0;; m++, a *= 10, m1 *= 10) {
            b = (-a) & ((1 << (n + m)) - 1);
            if ((a + b) % 5 == 0) b += 1 << (n + m);
            if (b >= m1) continue;
            x = a + b, y = x >> (n + m);
            int i, j;
            int64 now = 0, phi, pw;
            for (i = 0; i < 4; i++) {
                if (pm(2, i, 5) == y % 5) now = i;
            }
            phi = 4, pw = 5;
            for (i = 2; i <= n + m; i++) {
                pw *= 5;
                for (j = 0; j < 5; j++) {
                    if (pm(2, now + j * phi, pw) == y % pw) {
                        now += j * phi;
                        break;
                    }
                }
                phi *= 5;
            }
            std::cout << now + n + m << '\n';
            break;
        }
    }
    return 0;
}