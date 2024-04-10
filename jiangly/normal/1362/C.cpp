#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        long long ans = 0;
        while (n) {
            ans += n;
            n /= 2;
        }
        std::cout << ans << "\n";
    }
    return 0;
}