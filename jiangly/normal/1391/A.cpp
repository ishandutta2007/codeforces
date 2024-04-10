#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cout << i << " \n"[i == n];
    }
    return 0;
}