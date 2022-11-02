#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int T, n, e;
int a[N], p[N], nxt[N], lst[N];

int64 ans;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    for (int i = (p[1] = 1, 2); i < N; ++i) {
        if (p[i]) continue;
        for (int j = i << 1; j < N; j += i) p[j] = 1;
    }
    std::cin >> T;
    while (T--) {
        std::cin >> n >> e;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = n - e + 1; i <= n; ++i) nxt[i] = 0;
        for (int i = 1; i <= e; ++i) lst[i] = 0;
        for (int i = e + 1; i <= n; ++i) {
            lst[i] = a[i - e] == 1 ? lst[i - e] + 1 : 0;
        }
        for (int i = n - e; i; --i) {
            nxt[i] = a[i + e] == 1 ? nxt[i + e] + 1 : 0;
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (p[a[i]]) continue;
            ans += int64(lst[i] + 1) * (nxt[i] + 1) - 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}