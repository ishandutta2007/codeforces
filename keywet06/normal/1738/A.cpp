#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a, b, co(n), cx(n);
        long long Ans = 0;
        for (int i = 0; i < n; ++i) std::cin >> co[i];
        for (int i = 0; i < n; ++i) std::cin >> cx[i];
        for (int i = 0; i < n; ++i) (co[i] ? a : b).push_back(cx[i]), Ans += cx[i];
        std::sort(a.begin(), a.end(), std::greater<int>());
        std::sort(b.begin(), b.end(), std::greater<int>());
        int df = std::min(a.size(), b.size());
        Ans += a.size() == b.size() ? -std::min(a.back(), b.back()) : 0;
        for (int i = 0; i < df; ++i) Ans += a[i], Ans += b[i];
        std::cout << Ans << '\n';
    }
    return 0;
}