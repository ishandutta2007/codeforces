#include <bits/stdc++.h>

const int M = 131072;

int n, ans = 20, a[20][M * 2 + 5];

std::vector<int> v, z;

inline int& f(int x, int y) { return a[x][y + M]; }

void dfs(int x) {
    if (f(x, -(M >> x) - 1) || f(x, (M >> x) + 1)) return;
    if (x > 17) {
        if (z.size() < ans) ans = z.size(), v = z;
        return;
    }
    int i;
    for (i = -(M >> x); i <= (M >> x); ++i)
        if ((i & 1) && f(x, i)) break;
    if (i > (M >> x)) {
        for (int i = -(M >> x + 1) - 1; i <= (M >> x + 1) + 1; ++i) f(x + 1, i) = 0;
        for (int i = -(M >> x + 1); i <= (M >> x + 1); ++i) f(x + 1, i) = f(x, i << 1);
        dfs(x + 1);
        return;
    }
    z.push_back(1 << x);
    for (int i = -(M >> x + 1) - 1; i <= (M >> x + 1) + 1; ++i) f(x + 1, i) = 0;
    for (int i = -(M >> x); i <= (M >> x); ++i)
        if (f(x, i)) f(x + 1, (i & 1 ? i - 1 : i) >> 1) = 1;
    dfs(x + 1);
    z.pop_back();
    z.push_back(-(1 << x));
    for (int i = -(M >> x + 1) - 1; i <= (M >> x + 1) + 1; ++i) f(x + 1, i) = 0;
    for (int i = -(M >> x); i <= (M >> x); ++i)
        if (f(x, i)) f(x + 1, (i & 1 ? i + 1 : i) >> 1) = 1;
    dfs(x + 1);
    z.pop_back();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    int x;
    while (n--) std::cin >> x, f(0, x) = 1;
    dfs(0);
    std::cout << ans << '\n';
    for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " \n"[i == v.size() - 1];
    return 0;
}