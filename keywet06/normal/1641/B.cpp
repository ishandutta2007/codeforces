#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<int> b(a);
        std::sort(b.begin(), b.end());
        int Flag = n & 1;
        for (int i = 0; i + 1 < n; ++++i) Flag |= b[i] != b[i + 1];
        if (Flag) {
            std::cout << -1 << '\n';
            continue;
        }
        auto Reverse = [&](int l, int r) {
            while (l < r) std::swap(a[l++], a[r--]);
        };
        int L = 0;
        std::vector<std::pair<int, int> > Oper;
        std::vector<int> Len;
        for (int i = 0; i < n; ++++i) {
            int j = i + 1;
            while (a[j] != a[i]) ++j;
            for (int k = i + 1; k < j; ++k) Oper.emplace_back(L - i + j + k - i, a[k]);
            Len.push_back(j - i << 1), Reverse(i + 1, j), L += j - i << 1;
        }
        std::cout << Oper.size() << '\n';
        for (auto [l, x] : Oper) std::cout << l << ' ' << x << '\n';
        std::cout << Len.size() << '\n';
        for (auto x : Len) std::cout << x << ' ';
        std::cout << '\n';
    }
    return 0;
}