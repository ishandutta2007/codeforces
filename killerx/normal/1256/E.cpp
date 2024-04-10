#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n;
int a[mxn];
int id[mxn];

using val_t = std::pair <int, int>;
const val_t inf = {0x3f3f3f3f, -1};
val_t dp[mxn];

struct SegmentTree {
    static const int mxn = 1 << 18;
    val_t min[mxn << 1];

    void init() {
        rep(i, mxn << 1) min[i] = inf;
    }

    void update(int x, val_t v) {
        for (x += mxn; x; x >>= 1) min[x] = std::min(min[x], v);
    }

    val_t query(int l, int r) {
        val_t ans = inf;
        for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = std::min(ans, min[l ++]);
            if (r & 1) ans = std::min(ans, min[-- r]);
        }
        return ans;
    }
} seg;

int gid[mxn], gsz;

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    std::iota(id, id + n, 0);
    std::sort(id, id + n, [&] (int x, int y) {
        return a[x] < a[y];
    });
    seg.init();
    dp[0] = {0, -1};
    rep(i, n) {
        seg.update(i, {dp[i].first - a[id[i]], i});
        if (i > 1) dp[i + 1] = seg.query(0, i - 1), dp[i + 1].first += a[id[i]];
        else dp[i + 1] = inf;
    }
    gsz = 0;
    for (int i = n; i; i = dp[i].second) {
        ++ gsz;
        for (int j = dp[i].second; j < i; ++ j) gid[id[j]] = gsz;
    }
    printf("%d %d\n", dp[n].first, gsz);
    rep(i, n) printf("%d ", gid[i]);
    printf("\n");
    return 0;
}