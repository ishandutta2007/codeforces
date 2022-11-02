#include <bits/stdc++.h>

struct node {
    int l, r, x;
};

using int64 = long long;

const int N = 500005;
const int P = 998244353;

int n, m, k, l, u, x;
int f[N], d[N];

int64 sum, ans;

node a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) std::cin >> a[i].l >> a[i].r >> a[i].x;
    std::sort(a + 1, a + m + 1, [](node x, node y) { return x.r < y.r; });
    ans = f[0] = 1;
    for (int c = 0; c < k; ++c) {
        sum = u = 1, x = l = 0;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= m; ++i) {
            if (a[i].x & (1 << c)) ++d[a[i].l], --d[a[i].r + 1];
        }
        for (int i = 1; i <= n; ++i) {
            sum += f[i] = (x += d[i]) ? 0 : sum % P;
            while (u <= m && a[u].r <= i) {
                if (a[u].x & (1 << c) && ++u) continue;
                while (l < a[u].l) sum -= f[l++];
                ++u;
            }
        }
        ans = ans * (sum % P) % P;
    }
    std::cout << ans << std::endl;
    return 0;
}