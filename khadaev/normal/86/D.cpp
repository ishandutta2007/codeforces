#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int A = 1e6 + 10;
const int N = 2e5 + 10;
int n, q;

const int K = 600;
struct Query {
    int l, r, d, ix;

    Query () {};

    bool operator< (const Query &a) const {
        if (d != a.d) return d < a.d;
        return (d & 1) ? (r < a.r) : (r > a.r);
    }
};
int cnt[A];
ll ans[N];
ll cur;
ll a[N];
Query qs[N];

inline void add(int i) {
    cur += (2 * ++cnt[a[i]] - 1) * a[i];
}

inline void rem(int i) {
    cur -= (2 * --cnt[a[i]] + 1) * a[i];
}

inline void mo() {
    sort(qs, qs + q);
    cur = 0;
    int lc = 0, rc = 0;
    for (int i = 0; i < q; ++i) {
        while (lc < qs[i].l)
            rem(lc++);
        while (lc > qs[i].l)
            add(--lc);
        while (rc < qs[i].r)
            add(rc++);
        while (rc > qs[i].r)
            rem(--rc);
        ans[qs[i].ix] = cur;
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &qs[i].l, &qs[i].r);
        --qs[i].l;
        qs[i].d = qs[i].l / K;
        qs[i].ix = i;
    }
    mo();
    for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
}