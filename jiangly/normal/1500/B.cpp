#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int inverse(int a, int m) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r;
        std::swap(g, r);
        x -= q * y;
        std::swap(x, y);
    }
    return x < 0 ? x + m : x;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    i64 k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m), c(2 * std::max(n, m), -1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        c[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        b[i]--;
        b[i] = c[b[i]];
    }
    std::vector<i64> v(m);
    i64 g = std::gcd(n, m);
    i64 lcm = i64(n) * m / g;
    i64 in = inverse(n / g, m / g);
    for (int i = 0; i < m; i++) {
        if (b[i] == -1 || b[i] % g != i % g) {
            v[i] = -1;
        } else {
            i64 x = ((i - b[i]) / g * in % (m / g) + (m / g)) % (m / g);
            v[i] = x * n + b[i];
        }
    }
    i64 l = 1, r = 1e18;
    while (l < r) {
        i64 mid = (l + r) / 2;
        i64 cnt = mid;
        i64 d = mid / lcm;
        i64 e = mid % lcm;
        for (int i = 0; i < m; i++) {
            if (v[i] != -1) {
                cnt -= d;
                cnt -= (e > v[i]);
            }
        }
        if (cnt >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << "\n";
    return 0;
}