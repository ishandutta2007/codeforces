#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, n;
        std::cin >> a >> b >> n;
        if (a > b)
            std::swap(a, b);
        int ans = 0;
        while (b <= n) {
            a += b;
            std::swap(a, b);
            ++ans;
        }
        std::cout << ans << "\n";
    }
    return 0;
}