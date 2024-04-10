#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int x, a[4];
        std::cin >> x >> a[1] >> a[2] >> a[3];
        std::cout << (a[x] && a[a[x]] ? "YES" : "NO") << '\n';
    }
    return 0;
}