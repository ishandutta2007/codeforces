#include <bits/stdc++.h>

const int N = 105;

int n, k, t, x, p, c, d;
int pre[N], ans[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    t = (n - 1) / (k - 1) + 1;
    for (int i = 1; i <= n * k; ++i) {
        std::cin >> x;
        if (ans[x]) continue;
        if (pre[x] <= p) {
            pre[x] = i;
        } else {
            ans[x] = i, ++c, ++d;
            if (c == t || d == n) p = i, c = 0;
        }
    }
    for (int i = 1; i <= n; ++i) std::cout << pre[i] << ' ' << ans[i] << '\n';
    return 0;
}