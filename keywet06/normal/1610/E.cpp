#include <bits/stdc++.h>

void Solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int res = 0;
    for (int i = 0, k = 0; i < n; ++i) {
        k = std::max(k, i);
        while (k < n && a[i] == a[k]) ++k;
        int j = k, cnt = k - i;
        while (j < n) ++cnt, j = std::lower_bound(a.begin() + j + 1, a.end(), 2 * a[j] - a[i]) - a.begin();
        res = std::max(res, cnt);
    }
    std::cout << n - res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}