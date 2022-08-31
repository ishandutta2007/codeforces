#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int inf = 1e9;
struct SegmentTree {
    int n;
    std::vector<int> mn, tag;
    SegmentTree(int n) : n(n), mn(4 * n, inf), tag(4 * n) {}
    void pull(int p) {
        mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void add(int p, int v) {
        mn[p] += v;
        tag[p] += v;
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            add(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    std::vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int r = 0; r < k; r++) {
        SegmentTree t(n);
        std::vector<int> last(n, -1);
        int lastdp = 0;
        for (int i = 1; i <= n; i++) {
            t.rangeAdd(1, 0, n, i - 1, i, lastdp - inf);
            if (last[a[i - 1]] != -1) {
                t.rangeAdd(1, 0, n, 0, last[a[i - 1]] + 1, i - 1 - last[a[i - 1]]);
            }
            last[a[i - 1]] = i - 1;
            lastdp = dp[i];
            dp[i] = t.mn[1];
        }
    }
    std::cout << dp[n] << "\n";
    return 0;
}