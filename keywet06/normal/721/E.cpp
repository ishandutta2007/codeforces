#include <bits/stdc++.h>

using int64 = long long;

using Pa = std::pair<int64, int>;

const int N = 100005;

Pa f0[N], f[N];

Pa bsd(Pa a, Pa b) { return a.first > b.first || a.first == b.first && a.second < b.second ? a : b; }

int64 l[N], r[N];

int query(int64 x, int n) { return std::lower_bound(r + 1, r + n + 1, x) - r; }

int main() {
    int i, j, n;
    int64 L, p, t;
    std::cin >> L >> n >> p >> t;
    for (i = 1; i <= n; ++i) std::cin >> l[i] >> r[i];
    l[n + 1] = L + 1, r[n + 1] = L + 2;
    for (i = 1; i <= n; ++i) {
        f0[i] = bsd(f0[i], f0[i - 1]);
        f[i] = bsd(f[i], std::make_pair(f0[i].first + (r[i] - l[i]) / p, l[i] + ((r[i] - l[i]) / p) * p));
        int64 t0 = f[i].second + t;
        j = query(t0, n + 1);
        if (j > n) continue;
        if (l[j] >= t0) {
            f0[j] = bsd(f0[j], std::make_pair(f[i].first, t0));
            continue;
        }
        f[j] = bsd(f[j], std::make_pair(f[i].first + (r[j] - t0) / p, t0 + ((r[j] - t0) / p) * p));
        f0[j + 1] = bsd(f0[j + 1], std::make_pair(f[i].first, t0));
    }
    int64 ans = 0;
    for (i = 1; i <= n; ++i) ans = std::max(ans, f[i].first);
    std::cout << ans << '\n';
    return 0;
}