#include <bits/stdc++.h>

typedef long long int64;

const int N = 100005;

int n, a, b;
int g[N], k[N], d[N], pr[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> a >> b;
    for (int i = 1; i < n; ++i) std::cin >> g[i];
    for (int i = 1; i <= n; ++i) std::cin >> k[i];
    if (a > b) {
        for (int i = 1, j = n - 1; i < j; ++i, --j) std::swap(g[i], g[j]);
        for (int i = 1, j = n; i < j; ++i, --j) std::swap(k[i], k[j]);
        a = n - a + 1, b = n - b + 1;
    }
    d[a] = a;
    for (int i = 1; i <= n; ++i) {
        if (i > a) d[i] = std::min(d[i - 1], pr[g[i - 1]]);
        pr[k[i]] = i;
    }
    for (int i = 1; i <= 100000; ++i) pr[i] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (i < a) d[i] = std::max(d[i + 1], pr[g[i]]);
        pr[k[i]] = i;
    }
    int l = 0, r = b;
    int64 ans = 0;
    bool right = true;
    while (l != a && r != a) {
        if (right) {
            if (d[r] <= l) return std::cout << -1 << '\n', 0;
            l = d[r];
        } else {
            if (d[l] >= r) return std::cout << -1 << '\n', 0;
            r = d[l];
        }
        ans += r - l, right = !right;
    }
    std::cout << ans << '\n';
    return 0;
}