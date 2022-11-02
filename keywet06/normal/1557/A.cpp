#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353; // 1000000007;
const int N = 1000005;

int T;

int64 n, x, y, z, ans, max;
int64 a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(9);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        ans = 0, max = -1e15;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            ans += a[i], max = std::max(max, a[i]);
        }
        std::cout << double(ans - max) / (n - 1) + max << '\n';
    }
    return 0;
}