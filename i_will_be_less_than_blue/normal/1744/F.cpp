#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, inv[N], n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            inv[x] = i;
        }
        int mn = n, mx = 0;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                mn = std::min(mn, inv[i / 2]);
                mx = std::max(mx, inv[i / 2]);
            }
            ans += std::max(0, std::min(n - i, mn) - std::max(0, mx - i + 1) + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}