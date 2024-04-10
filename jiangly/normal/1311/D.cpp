// lg
#include <iostream>
#include <vector>
int t, a, b, c;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        int ans = std::numeric_limits<int>::max(), A, B, C;
        for (int i = 1; i < 2 * a; ++i) {
            for (int j = i; j < 2 * b; j += i) {
                int l = c / j * j, r = l + j, v = std::abs(i - a) + std::abs(j - b);
                if (l >= j && v + std::abs(l - c) < ans) {
                    ans = v + std::abs(l - c);
                    A = i;
                    B = j;
                    C = l;
                }
                if (v + std::abs(r - c) < ans) {
                    ans = v + std::abs(r - c);
                    A = i;
                    B = j;
                    C = r;
                }
            }
        }
        std::cout << ans << "\n";
        std::cout << A << " " << B << " " << C << "\n";
    }
    return 0;
}