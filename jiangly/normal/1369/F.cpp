#include <bits/stdc++.h>
constexpr int N = 1e5;
int n;
int f[N], g[N], a[N + 1], b[N + 1];
int get(long long s, long long e) {
    if (2 * s > e) {
        return 1;
    } else {
        e /= 2;
        if (e & 1) {
            return (e - s) & 1;
        } else if (2 * s > e) {
            return (e - s) & 1;
        } else {
            return get(s, e / 2);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        long long s, e;
        std::cin >> s >> e;
        f[i] = get(s, 2 * e);
        g[i] = get(s, e);
    }
    b[0] = 1;
    for (int i = 0; i < n; ++i) {
        a[i + 1] = f[i] ? b[i] : a[i];
        b[i + 1] = g[i] ? b[i] : a[i];
    }
    std::cout << a[n] << " " << b[n] << "\n";
    return 0;
}