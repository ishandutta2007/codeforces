#include <iostream>
int t, n;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        int a = 2, b, c;
        while (a * a <= n && n % a != 0)
            ++a;
        if (a * a > n) {
            std::cout << "NO\n";
            continue;
        }
        n /= a;
        b = a + 1;
        while (b * b <= n && n % b != 0)
            ++b;
        if (b * b >= n) {
            std::cout << "NO\n";
            continue;
        }
        c = n / b;
        std::cout << "YES\n";
        std::cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}