#include <bits/stdc++.h>
void ensure(bool exp) {
    if (!exp) {
        std::cout << "-1\n";
        exit(0);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n);
    for (auto &i : a) {
        i.resize(m);
        for (int &j : i)
            std::cin >> j;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j) {
            if (a[i][j] > 0) {
                ensure(i == n - 1 || a[i][j] < a[i + 1][j]);
                ensure(j == m - 1 || a[i][j] < a[i][j + 1]);
            } else {
                a[i][j] = std::min(a[i][j + 1], a[i + 1][j]) - 1;
                ensure(a[i][j] > 0);
            }
            ans += a[i][j];
        }
    std::cout << ans << "\n";
    return 0;
}