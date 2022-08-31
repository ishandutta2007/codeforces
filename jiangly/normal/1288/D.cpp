#include <iostream>
constexpr int N = 300'000, M = 8;
int n, m, x, y, tot;
int a[N][M], id[1 << M];
bool solve(int v) {
    std::fill(id, id + tot, -1);
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < m; ++j)
            if (a[i][j] >= v)
                s |= 1 << j;
        id[s] = i;
    }
    for (int i = tot - 1; i >= 0; --i)
        for (int j = 0; j < m; ++j)
            if (id[i | 1 << j] != -1)
                id[i] = id[i | 1 << j];
    for (int i = 0; i < tot; ++i) {
        if (id[i] != -1 && id[(tot - 1) ^ i] != -1) {
            x = id[i];
            y = id[(tot- 1) ^ i];
            return true;
        }
    }
    return false;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    tot = 1 << m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> a[i][j];
    int l = 0, r = 1'000'000'000;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (solve(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    solve(l);
    std::cout << x + 1 << " " << y + 1 << "\n";
    return 0;
}