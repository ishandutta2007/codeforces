#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, m;
int a[mxn];

int s_less[mxn], s_greater[mxn];

struct BIT {
    static const int mxn = 1e6 + 10, shift = 5e5 + 5;
    int s[mxn];
    void init() { memset(s, 0, sizeof(s)); }
    inline void update(int x, int v) { for (x += shift; x < mxn; x += x & -x) s[x] += v; }
    inline int query(int x) { int ans = 0; for (x += shift; x; x -= x & -x) ans += s[x]; return ans; }
} bit;

int main() {
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) {
        s_less[i + 1] = s_less[i] + (a[i] < m);
        s_greater[i + 1] = s_greater[i] + (a[i] > m);
    }
    rep(i, n + 1) {
        s_less[i] = s_less[i] * 2 - i;
        s_greater[i] = s_greater[i] * 2 - i;
    }
    long long ans = 1LL * n * (n + 1) / 2;
    // 2 * #less - n >= 0
    bit.init();
    rep(i, n + 1) {
        ans -= bit.query(s_less[i]);
        bit.update(s_less[i], +1);
    }
    // 2 * #greater - n > 0
    bit.init();
    rep(i, n + 1) {
        ans -= bit.query(s_greater[i] - 1);
        bit.update(s_greater[i], +1);
    }
    printf("%lld\n", ans);
	return 0;
}