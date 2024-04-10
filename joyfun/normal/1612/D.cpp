#include <bits/stdc++.h>

int t;
long long a, b, x;

int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> x;
        if (a < b) std::swap(a, b);
        std::string ans = "NO";
        while (b) {
            if (a - x >= 0 && ((a - x) % b == 0 || (a > b && (a - x) % (a - b) == 0))) {
                ans = "YES";
            }
            a = a % b;
            std::swap(a, b);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}