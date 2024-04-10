#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, c;
        std::cin >> n >> c;
        std::vector<int> a(n), b(c + 1);
        for (int i = 0, x; i < n; ++i) std::cin >> x, ++b[x];
        int t = 0;
        for (int i = 1; i <= c; ++i) {
            if (b[i] = std::min(b[i], 1)) a[t++] = i;
            b[i] += b[i - 1];
        }
        auto B = [&](int64 i) -> int { return b[std::min(i, int64(c))]; };
        a.resize(n = t);
        bool Ans = true;
        for (int i = 0; i < n; ++i) {
            int Num = 0;
            for (int j = 0; j < n && int64(a[i]) * a[j] <= c; ++j) {
                Num += B(a[i] * int64(a[j] + 1) - 1) - B(a[i] * int64(a[j]) - 1);
            }
            Ans = Num == n - i;
            if (!Ans) break;
        }
        std::cout << (Ans ? "Yes" : "No") << std::endl;
    }
    return 0;
}