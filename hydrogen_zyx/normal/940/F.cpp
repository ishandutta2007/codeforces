#include<bits/stdc++.h>

using namespace std;
int n, Q;
vector<int> v, b;
const int N = 2e5 + 10;
int bl[N];
struct node {
    int l, r, id, t;
} q[N];
struct change {
    int x, val;
} c[N];
int tot[N], cntt[N];

inline void add(int x) {
    --tot[cntt[x]];
    ++tot[++cntt[x]];
}

inline void del(int x) {
    --tot[cntt[x]];
    ++tot[--cntt[x]];
}

inline void modify(int now, int i) {
    if (q[i].l <= c[now].x && c[now].x <= q[i].r) {
        del(v[c[now].x]);
        add(c[now].val);
    }
    swap(v[c[now].x], c[now].val);
}

int ans[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> Q;
    int unt = pow(n, 2.0 / 3.0);
    for (register int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (register int i = 0; i < n; i++) {
        b.push_back(v[i]);
        bl[i] = (i - 1) / unt + 1;
    }
    int cnt, cnt2;
    cnt = cnt2 = 0;
    for (register int i = 0; i < Q; i++) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            ++cnt;
            q[cnt] = {--x, --y, cnt, cnt2};
        }
        if (opt == 2) {
            ++cnt2;
            c[cnt2] = {--x, y};
            b.push_back(y);
        }
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int &x: v) x = lower_bound(b.begin(), b.end(), x) - b.begin();
    for (register int i = 1; i <= cnt2; i++) { c[i].val = lower_bound(b.begin(), b.end(), c[i].val) - b.begin(); }
    sort(q + 1, q + cnt + 1, [](node x, node y) {
        if (bl[x.l] ^ bl[y.l]) return x.l < y.l;
        if (bl[x.r] ^ bl[y.r]) return x.r < y.r;
        return x.t < y.t;
    });
    int l = 1, r = 0, now = 0;
    for (register int i = 1; i <= cnt; i++) {
        while (l > q[i].l) add(v[--l]);
        while (r < q[i].r) add(v[++r]);
        while (l < q[i].l) del(v[l++]);
        while (r > q[i].r) del(v[r--]);
        while (now < q[i].t) modify(++now, i);
        while (now > q[i].t) modify(now--, i);
        for (ans[q[i].id] = 1; tot[ans[q[i].id]] > 0; ++ans[q[i].id]);
    }
    for (register int i = 1; i <= cnt; i++) cout << ans[i] << '\n';
    return 0;
}