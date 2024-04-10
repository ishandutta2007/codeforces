#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1 << 20;
const i64 inf = 1e13 + 7;

i64 calc(int *a, int l, int r) {
    static int temp[mxn];
    if (l + 1 >= r) return 0;
    int m = (l + r) >> 1;
    i64 ans = 0;
    ans += calc(a, l, m);
    ans += calc(a, m, r);
    for (int i = l, j = m, k = l; i < m || j < r; ) {
        if (j == r || (i < m && a[i] <= a[j])) {
            temp[k ++] = a[i ++];
        } else {
            temp[k ++] = a[j ++];
            ans += m - i;
        }
    }
    for (int i = l; i < r; ++ i) a[i] = temp[i];
    return ans;
}

i64 calc(int *l, int *r) {
    static int temp[mxn];
    memcpy(temp, l, sizeof(int) * (r - l));
    return calc(temp, 0, r - l);
}

int n, m;
int a[mxn], b[mxn];

struct Tag {
    i64 x, y;

    Tag(): x(0), y(inf) {}
    Tag(i64 _x, i64 _y): x(_x), y(_y) {}
};

Tag operator + (const Tag &a, const Tag &b) {
    return {a.x + b.x, std::min(a.y + b.x, b.y)};
}

i64 OP(i64 base, Tag t) {
    return std::min(t.y, base + t.x);
}

Tag tag[mxn << 1];

void push(int x, Tag v) {
    tag[x] = tag[x] + v;
}

void pushdown(int x) {
    push(x << 1, tag[x]);
    push(x << 1 | 1, tag[x]);
    tag[x] = {0, inf};
}

void update(int l, int r, Tag t, int i = 1, int a = 0, int b = mxn) {
    if (l <= a && b <= r) return push(i, t);
    if (r <= a || b <= l) return ;
    int m = (a + b) >> 1;
    pushdown(i);
    update(l, r, t, i << 1, a, m);
    update(l, r, t, i << 1 | 1, m, b);
}

Tag query(int x) {
    x += mxn;
    for (int i = 20; i; -- i) pushdown(x >> i);
    return tag[x];
}

void Main() {
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) scanf("%d", &b[i]);
    std::sort(b, b + m);
    i64 BASE = calc(a, a + n);
    // eprintf("%lld\n", BASE);
    push(1, {inf, 0});
    i64 base = 0;
    rep(i, n) {
        push(1, {0, 0});
        int S = std::lower_bound(b, b + m, a[i]) - b;
        int T = std::upper_bound(b, b + m, a[i]) - b;
        base += S;
        update(0, S, {-1, inf});
        update(T, m, {+1, inf});
        /*
        eprintf("%lld", base);
        rep(j, m + 1) eprintf(" +%lld", OP(0, query(j)));
        eprintf("\n");
        */
    }
    i64 ans = inf;
    rep(i, m + 1) {
        ans = std::min(ans, base);
        base += OP(0, query(i));
    }
    printf("%lld\n", ans + BASE);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}