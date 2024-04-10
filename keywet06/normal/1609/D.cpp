#include <bits/stdc++.h>

const int N = 2005;

int n, q, c, x, y, d, ans;
int f[N], size[N], num[N];

inline int find(int u) { return f[u] == u ? u : (f[u] = find(f[u])); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q, c = 1, num[1] = N;
    for (int i = 1; i <= n; ++i) f[i] = i, size[i] = 1;
    while (q--) {
        std::cin >> x >> y, x = find(x), y = find(y);
        if (x == y) {
            ++c;
        } else {
            --num[size[x]], --num[size[y]];
            f[y] = x, ++num[size[x] += size[y]];
        }
        ans = -1, d = c;
        for (int i = n; i; --i) {
            for (int j = 0; j < num[i]; ++j) {
                if (d) --d, ans += i;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}