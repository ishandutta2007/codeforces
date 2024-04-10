#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

constexpr int maxn = 1 << 18;
static_assert(maxn >= 200000);

long long seg[maxn * 2 - 1];

void build() {
    for (int k = maxn - 2; k >= 0; k--) {
        seg[k] = min(seg[2 * k + 1], seg[2 * k + 2]);
        seg[2 * k + 1] -= seg[k];
        seg[2 * k + 2] -= seg[k];
    }
}

void inc(int l, int r, int v) {
    l += maxn;
    r += maxn;

    bool a = false, b = false;
    while (true) {
        if (l < r) {
            if (l & 1)
                a = true, seg[l - 1] += v;
            if (r & 1)
                b = true, seg[r - 2] += v;
        }
        l = (l + 1) >> 1, r >>= 1;
        if (!r)
            break;
        if (a) {
            int k = l - 2;
            long long x = min(seg[2 * k + 1], seg[2 * k + 2]);
            seg[k] += x;
            seg[2 * k + 1] -= x;
            seg[2 * k + 2] -= x;
        }
        if (b) {
            int k = r - 1;
            long long x = min(seg[2 * k + 1], seg[2 * k + 2]);
            seg[k] += x;
            seg[2 * k + 1] -= x;
            seg[2 * k + 2] -= x;
        }
    }
}

long long rmq(int l, int r) {
    l += maxn;
    r += maxn;

    long long x = LLONG_MAX, y = LLONG_MAX;
    while (true) {
        if (l < r) {
            if (l & 1)
                x = min(x, seg[l - 1]);
            if (r & 1)
                y = min(y, seg[r - 2]);
        }
        l = (l + 1) >> 1, r >>= 1;
        if (!r)
            break;
        if (x != LLONG_MAX)
            x += seg[l - 2];
        if (y != LLONG_MAX)
            y += seg[r - 1];
    }

    return min(x, y);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &seg[maxn - 1 + i]);

    build();

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        r++;
        if (getchar() == ' ') {
            int v;
            scanf("%d", &v);
            if (l < r) {
                inc(l, r, v);
            } else {
                inc(0, r, v);
                inc(l, n, v);
            }
        } else {
            long long ans;
            if (l < r) {
                ans = rmq(l, r);
            } else {
                ans = min(rmq(0, r), rmq(l, n));
            }
            printf("%lld\n", ans);
        }
    }
}