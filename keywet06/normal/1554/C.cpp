#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int T, n, x, y, z, ans, f;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> x >> y;
        z = 0, f = 1;
        while (1 << z <= x) ++z;
        ans = y >> z << z;
        while (z--) {
            if ((y >> z) & 1 && !((y + 1 >> z) & 1)) {
                ans += 1 << z + 1, f = 0;
                break;
            }
            if ((x >> z) & 1 && !((y >> z) & 1)) {
                f = 0;
                break;
            } else if (!((x >> z) & 1) && (y >> z) & 1) {
                ans |= 1 << z;
            }
        }
        ans += f;
        std::cout << ans << '\n';
    }
    return 0;
}