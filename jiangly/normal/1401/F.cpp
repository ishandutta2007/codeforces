#include <bits/stdc++.h>
int64_t s[1 << 19];
void modify(int p, int l, int r, int x, int v) {
    if (r - l == 1) {
        s[p] = v;
    } else {
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        s[p] = s[2 * p] + s[2 * p + 1];
    }
}
int64_t rangeSum(int p, int l, int r, int x, int y, int t) {
    if (l >= y || r <= x)
        return 0;
    if (l >= x && r <= y)
        return s[p ^ (t >> __builtin_ctz(r - l))];
    int m = (l + r) / 2;
    return rangeSum(2 * p, l, m, x, y, t) + rangeSum(2 * p + 1, m, r, x, y, t);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q, t = 0;
    std::cin >> n >> q;
    for (int i = 0; i < (1 << n); ++i) {
        int v;
        std::cin >> v;
        modify(1, 0, 1 << n, i, v);
    }
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, v;
            std::cin >> x >> v;
            --x;
            x ^= t;
            modify(1, 0, 1 << n, x, v);
        } else if (op == 2) {
            int k;
            std::cin >> k;
            t ^= (1 << k) - 1;
        } else if (op == 3) {
            int k;
            std::cin >> k;
            t ^= 1 << k;
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            std::cout << rangeSum(1, 0, 1 << n, l, r, t) << "\n";
        }
    }
    return 0;
}