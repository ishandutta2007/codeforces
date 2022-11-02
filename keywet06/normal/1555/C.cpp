#include <bits/stdc++.h>

using int64 = long long;

const int N = 100005;

int T, n;

int64 ans;
int64 a[N], b[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, a[n + 1] = b[n + 1] = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        for (int i = n; i; --i) a[i] += a[i + 1];
        for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
        ans = 1e15;
        for (int i = 1; i <= n; ++i) {
            ans = std::min(ans, std::max(a[i + 1], b[i - 1]));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}