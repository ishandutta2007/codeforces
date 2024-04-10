#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

int T, n, ans;

int64 a[N], b[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        ans = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[b[i] = i];
        std::sort(b + 1, b + n + 1, [](int x, int y) { return a[x] < a[y]; });
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (b[i] + b[j] == a[b[i]] * a[b[j]]) ++ans;
                if (b[i] + n < a[b[i]] * a[b[j]]) break;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}