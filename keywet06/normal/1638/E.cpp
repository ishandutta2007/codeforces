// Luogu Remote

#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    int m = 1 << 33 - __builtin_clz(n - 1);
    std::vector<int> Col(m);
    std::vector<int64> Sum(m), Pre(n + 1);
    Col[1] = 1;
    using DelF = std::function<void(int, int, int)>;
    DelF Del = [&](int u, int l, int r) -> void {
        if (Col[u]) return Sum[u] += Pre[Col[u]], Col[u] = 0, void(0);
        int Mid = l + r >> 1;
        Del(u << 1, l, Mid), Del(u << 1 | 1, Mid + 1, r);
    };
    using ColorF = std::function<void(int, int, int, int, int, int)>;
    ColorF Color = [&](int u, int l, int r, int x, int y, int c) -> void {
        if (l >= x && r <= y) return Del(u, l, r), Sum[u] -= Pre[c], Col[u] = c, void(0);
        if (Col[u]) Col[u << 1] = Col[u << 1 | 1] = Col[u], Col[u] = 0;
        int Mid = l + r >> 1;
        if (x <= Mid) Color(u << 1, l, Mid, x, y, c);
        if (y > Mid) Color(u << 1 | 1, Mid + 1, r, x, y, c);
    };
    using QueryF = std::function<int64(int, int, int, int)>;
    QueryF Query = [&](int u, int l, int r, int x) -> int64 {
        int64 v = Pre[Col[u]] + Sum[u];
        if (l == r) return v;
        int Mid = l + r >> 1;
        return (x <= Mid ? Query(u << 1, l, Mid, x) : Query(u << 1 | 1, Mid + 1, r, x)) + v;
    };
    std::string s;
    int l, r, x, c;
    while (q--) {
        std::cin >> s;
        if (s[0] == 'C') {
            std::cin >> l >> r >> c;
            Color(1, 1, n, l, r, c);
        } else if (s[0] == 'A') {
            std::cin >> x >> c;
            Pre[x] += c;
        } else {
            std::cin >> x;
            std::cout << Query(1, 1, n, x) << '\n';
        }
    }
    return 0;
}