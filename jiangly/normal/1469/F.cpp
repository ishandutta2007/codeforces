#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int inf = 1e9, N = 5e5;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }
    std::sort(l.begin(), l.end(), std::greater<>());
    int a[N]{};
    a[0] = 1;
    a[1] = -1;
    int ans = inf;
    int total = 0;
    for (int i = 0, j = 0; i < N - 1; ++i) {
        total += a[i];
        a[i + 1] += a[i];
        if (total + a[i + 1] >= k) {
            ans = std::min(ans, i + 1);
        }
        while (a[i] > 0 && j < n) {
            int u = (l[j] - 1) / 2;
            int v = l[j] - 1 - u;
            a[i + 2]++;
            a[i + 2 + u]--;
            a[i + 2]++;
            a[i + 2 + v]--;
            a[i]--;
            total--;
            j++;
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    std::cout << ans << "\n";
    return 0;
}