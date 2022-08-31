#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i)
            std::cin >> p[i];
        std::reverse(p.begin(), p.end());
        for (auto x : p)
            std::cout << x << " \n"[x == p.back()];
    }
    return 0;
}