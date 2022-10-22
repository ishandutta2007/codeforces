#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long i64;

const int mxn = 2e5 + 5;

int n, K;
bool can[mxn];

struct SegmentTree {
    static const int mxn = 1 << 18;
    i64 min[mxn << 1];

    void clear() { memset(min, 0x3f, sizeof(min)); }

    void update(int x, i64 v) { for (x += mxn; x; min[x] = std::min(min[x], v), x >>= 1); }

    i64 query(int l, int r) {
        i64 ans = 1LL << 60;
        for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = std::min(ans, min[l ++]);
            if (r & 1) ans = std::min(ans, min[-- r]);
        }
        return ans;
    }
} seg;

int main() {
    scanf("%d %d", &n, &K);
    static char temp[mxn];
    scanf("%s", temp);
    seg.clear();
    rep(i, n) {
        can[i] = temp[i] - '0';
        if (can[i]) {
            i64 x;
            if (i - K <= 0) x = i + 1;
            else x = seg.query(i - K, n) + i + 1;
            seg.update(std::min(n, i + K + 1), x);
        }
        i64 x;
        if (i <= 0) x = i + 1;
        else x = seg.query(i, n) + i + 1;
        seg.update(i + 1, x);
    }
    printf("%lld\n", seg.query(n, n + 1));
	return 0;
}