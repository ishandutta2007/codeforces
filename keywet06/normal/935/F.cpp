#include <bits/stdc++.h>

const int N = 300005;

long long a[N], t[N * 8];

void modify(int l, int r, int x, long long c, int id) {
    if (l == r) return void(t[id] = c);
    int m = (l + r) / 2;
    x <= m ? modify(l, m, x, c, id * 2) : modify(m + 1, r, x, c, id * 2 + 1);
    t[id] = std::min(t[id * 2], t[id * 2 + 1]);
}

long long query(int l, int r, int u, int v, int id) {
    if (u <= l && r <= v) return t[id];
    int m = (l + r) / 2;
    long long ans = 10000000000000LL;
    if (u <= m) ans = std::min(ans, query(l, m, u, std::min(m, v), id * 2));
    if (v > m) ans = std::min(ans, query(m + 1, r, std::max(u, m + 1), v, id * 2 + 1));
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    long long s = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
    for (int i = 1; i < n; ++i) s += abs(a[i]);
    for (int i = 0; i < n; ++i) modify(0, n, i, std::max(a[i + 1], 0LL) + std::max(-a[i], 0LL), 1);
    int T;
    std::cin >> T;
    while (T--) {
        long long f, l, r, x;
        std::cin >> f >> l >> r >> x, --l, --r;
        if (f == 1) {
            if (l == r) {
                if (l == n - 1) {
                    std::cout << s - abs(a[l]) + abs(a[l] + x) << '\n';
                    continue;
                }
                long long w = s;
                w = w - abs(a[l]) - abs(a[l + 1]);
                w = w + abs(a[l] + x) + abs(a[l + 1] - x);
                std::cout << w << '\n';
                continue;
            }
            long long tmp = query(0, n, l, r, 1);
            tmp = std::min(tmp, x);
            std::cout << s + (x - tmp) * 2 << '\n';
        }
        if (f == 2) {
            s = s - abs(a[l]) - abs(a[r + 1]);
            a[l] += x;
            a[r + 1] -= x;
            s = s + abs(a[l]) + abs(a[r + 1]);
            modify(0, n, l, std::max(a[l + 1], 0LL) + std::max(-a[l], 0LL), 1);
            modify(0, n, r, std::max(a[r + 1], 0LL) + std::max(-a[r], 0LL), 1);
            if (l != 0) modify(0, n, l - 1, std::max(a[l], 0LL) + std::max(-a[l - 1], 0LL), 1);
            if (r != n - 1) modify(0, n, r + 1, std::max(a[r + 2], 0LL) + std::max(-a[r + 1], 0LL), 1);
        }
    }
    return 0;
}