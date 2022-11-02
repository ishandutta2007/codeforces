#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::array a{std::vector<int>(n), std::vector<int>(n)}, b(a);
    int Ca = 0, Cb = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) std::cin >> a[i][j], Ca += a[i][j];
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) std::cin >> b[i][j], Cb += b[i][j];
    }
    if (Ca != Cb) return std::cout << "-1\n", 0;
    int64 Ans = 0;
    int cnt = 0;
    std::array<int, 2> ca{}, cb{};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (a[j][i]) ++cnt, ++ca[j];
            if (b[j][i]) --cnt, ++cb[j];
            int t = std::min(ca[j], cb[j]);
            ca[j] -= t, cb[j] -= t;
        }
        for (int j = 0; j < 2; ++j) {
            int t = std::min(ca[j], cb[!j]);
            ca[j] -= t, cb[!j] -= t, Ans += t;
        }
        Ans += std::abs(cnt);
    }
    std::cout << Ans << "\n";
    return 0;
}