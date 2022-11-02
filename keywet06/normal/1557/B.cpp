#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;
const int N = 1000005;

int T;
int p[N], q[N];

int64 n, x, y, z, ans, max, k;
int64 a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(9);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        ans = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], p[i] = i;
        std::sort(p + 1, p + n + 1, [](int x, int y) { return a[x] < a[y]; });
        for (int i = 1; i <= n; ++i) q[p[i]] = i;
        for (int i = 1; i < n; ++i) ans += q[i] + 1 == q[i + 1];
        std::cout << (n - ans <= k ? "YES" : "NO") << '\n';
    }
    return 0;
}