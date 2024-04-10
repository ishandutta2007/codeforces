#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

struct Query {
    int l, r, i;
};

const int mxn = 3e5 + 5;
int n, q, K;
int a[mxn];
int mn[mxn], que[mxn], ql, qr;
std::vector <Query> qry[mxn];
i64 ans[mxn];

struct SegmentTree {
    static const int mxn = 1 << 19;
    int tag[mxn << 1], min[mxn << 1], len[mxn << 1];
    i64 sum[mxn << 1];

    SegmentTree() {
        memset(tag, -1, sizeof(tag));
        memset(min, 0, sizeof(min));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < mxn; ++ i) len[i + mxn] = 1;
        for (int i = mxn - 1; i; -- i) len[i] = len[i << 1] + len[i << 1 | 1];
    }

    void push(int x, int v) { tag[x] = min[x] = v, sum[x] = 1LL * v * len[x]; }

    void pushdown(int x) { if (~tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = -1; }

    void pushup(int x) { min[x] = std::min(min[x << 1], min[x << 1 | 1]); sum[x] = sum[x << 1] + sum[x << 1 | 1]; }

    void update(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
        if (l <= a && b <= r) return push(i, v);
        if (r <= a || b <= l) return ;
        pushdown(i);
        int m = (a + b) >> 1;
        update(l, r, v, i << 1, a, m);
        update(l, r, v, i << 1 | 1, m, b);
        pushup(i);
    }

    i64 query(int l, int r, int i = 1, int a = 0, int b = mxn) {
        if (l <= a && b <= r) return sum[i];
        if (r <= a || b <= l) return 0;
        pushdown(i);
        int m = (a + b) >> 1;
        return query(l, r, i << 1, a, m) + query(l, r, i << 1 | 1, m, b);
    }

    int base_lower_bound(int v, int i = 1, int a = 0, int b = mxn) {
        while (i < mxn) {
            pushdown(i);
            int m = (a + b) >> 1;
            if (min[i << 1] <= v) i = i << 1, b = m;
            else i = i << 1 | 1, a = m;
        }
        return a;
    }

    int lower_bound(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
        if (min[i] > v) return -1;
        if (l <= a && b <= r) return base_lower_bound(v, i, a, b);
        if (r <= a || b <= l) return -1;
        pushdown(i);
        int m = (a + b) >> 1;
        int ans = -1;
        if ((ans = lower_bound(l, r, v, i << 1, a, m)) != -1) return ans;
        if ((ans = lower_bound(l, r, v, i << 1 | 1, m, b)) != -1) return ans;
        return -1;
    }
} seg;

i64 query(int l, int r, int v) {
    int p = seg.lower_bound(l, r, v);
    if (p == -1) p = r;
    return seg.query(p, r) + 1LL * (p - l) * v;
}

int main() {
    scanf("%d %d %d", &n, &q, &K);
    rep(i, n) scanf("%d", &a[i]);
    for (int i = n - 1; ~i; -- i) {
        while (ql < qr && a[que[qr - 1]] > a[i]) -- qr;
        while (ql < qr && que[ql] >= i + K) ++ ql;
        que[qr ++] = i;
        mn[i] = a[que[ql]];
    }
    rep(i, q) {
        int l, r;
        scanf("%d %d", &l, &r);
        -- l, -- r;
        qry[l % K].push_back({l, r, i});
    }
    rep(rem, K) if (!qry[rem].empty()) {
        /*
        for (Query Q : qry[rem]) {
            int l = Q.l, r = Q.r, i = Q.i;
            int val = a[l];
            ans[i] = val;
            for (int s = l + 1; s + K - 1 <= r; s += K) {
                val = std::min(val, mn[s]);
                ans[i] += val;
            }
        }
        */
        std::vector <int> b;
        for (int i = rem + 1; i + K - 1 < n; i += K) b.push_back(i);
        std::sort(qry[rem].begin(), qry[rem].end(), [&] (Query x, Query y) {
            return x.l < y.l;
        });
        int ptr = (int) qry[rem].size() - 1;
        while (ptr >= 0 && qry[rem][ptr].l + 1 + K - 1 >= n) {
            ans[qry[rem][ptr].i] = a[qry[rem][ptr].l];
            -- ptr;
        }
        seg.push(1, 0);
        std::vector <int> stk;
        for (int i = (int) b.size() - 1; ~i; -- i) {
            while (!stk.empty() && mn[b[stk.back()]] > mn[b[i]]) stk.pop_back();
            if (stk.empty()) seg.update(i, b.size(), mn[b[i]]);
            else seg.update(i, stk.back(), mn[b[i]]);
            stk.push_back(i);
            while (ptr >= 0 && qry[rem][ptr].l + 1 == b[i]) {
                int p = std::upper_bound(b.begin(), b.end(), qry[rem][ptr].r - K + 1) - b.begin();
                ans[qry[rem][ptr].i] = a[qry[rem][ptr].l] + query(i, p, a[qry[rem][ptr].l]);
                -- ptr;
            }
        }
    }
    rep(i, q) printf("%lld\n", ans[i]);
    return 0;
}