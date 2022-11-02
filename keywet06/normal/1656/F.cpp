#include <bits/stdc++.h>

template<typename Type1, typename Type2>
inline Type1 &Mad(Type1 &x, Type2 y) {
    return x > y ? x : (x = y);
}

using int64 = long long;

const int N = 100005;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int64> a(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a.begin() + 1, a.end());
        int64 s = 0, Max = -1e18, r = 0;
        for (int i = 2; i <= n; ++i) s += a[1] + a[i], r += a[1] * a[i];
        if (s > 0) {
            std::cout << "INF" << '\n';
            continue;
        }
        Mad(Max, -a[1] * s + r);
        Mad(Max, -a[2] * s + r);
        s = 0, r = 0;
        for (int i = 1; i < n; ++i) s += a[n] + a[i], r += a[n] * a[i];
        if (s < 0) {
            std::cout << "INF" << '\n';
            continue;
        }
        Mad(Max, -a[n] * s + r);
        Mad(Max, -a[n - 1] * s + r);
        for (int i = n - 1; i > 1; --i) {
            s -= a[n] + a[i], s += a[1] + a[i];
            r -= a[n] * a[i], r += a[1] * a[i];
            Mad(Max, -a[i] * s + r);
            Mad(Max, -a[i - 1] * s + r);
        }
        std::cout << Max << '\n';
    }
    return 0;
}