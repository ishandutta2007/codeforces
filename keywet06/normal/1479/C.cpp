#include <bits/stdc++.h>

struct edge {
    int u, v, c;
};

int l, r;

std::vector<edge> ed;

void add(int u, int v, int c) { ed.push_back((edge){u, v, c}); }

int solve(int l, int r) {
    if (l > 1) {
        int n = solve(1, r - l + 1);
        add(n, n + 1, l - 1);
        return n + 1;
    }
    if ((r & -r) == r) {
        int k = 0, R_ = r;
        while (R_) R_ /= 2, ++k;
        k--;
        add(1, 2, 1);
        for (int i = 3; i <= k + 2; ++i) {
            add(1, i, 1);
            for (int j = 2; j < i; ++j) add(j, i, (1 << (j - 2)));
        }
        return k + 2;
    }
    int n = 0;
    while (1 << (n + 1) <= r - 1) ++n;
    solve(1, 1 << n);
    add(1, n + 3, 1);
    for (int i = 0; i <= n; ++i) {
        if ((r - 1) >> i & 1) {
            add(i + 2, n + 3, 1 + ((r - 1) >> (i + 1) << (i + 1)));
        }
    }
    return n + 3;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> l >> r;
    std::cout << "YES" << '\n';
    int n = solve(l, r);
    std::cout << n << ' ' << ed.size() << '\n';
    for (auto e : ed) std::cout << e.u << ' ' << e.v << ' ' << e.c << '\n';
    return 0;
}