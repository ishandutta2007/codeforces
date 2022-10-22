#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct evt {
    int x, t, l, r, y;
};

bool cmp(evt x, evt y) {
    if (x.x == y.x) return x.t < y.t;
    return x.x < y.x;
}

const int MN = 1000005;

int n, m, u, v, w, st[3 * MN], ans = 1;
vector<evt> vec;

void upd(int l, int r, int x, int val, int idx) {
    if (l == r) {
        st[idx] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) upd(l, mid, x, val, idx * 2);
    else upd(mid + 1, r, x, val, idx * 2 + 1);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

int qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return 0;
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return qry(l, mid, x, y, idx * 2) + qry(mid + 1, r, x, y, idx * 2 + 1);
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w >> u >> v;
        if (u == 0 && v == 1e6) ans++;
        vec.push_back({u, 0, 0, 0, w});
        vec.push_back({v, 2, 0, 0, w});
    }
    for (int i = 1; i <= m; i++) {
        cin >> w >> u >> v;
        if (u == 0 && v == 1e6) ans++;
        vec.push_back({w, 1, u, v, 0});
    }
    sort(vec.begin(), vec.end(), cmp);
    for (evt p : vec) {
        if (p.t == 0) upd(0, 1e6, p.y, 1, 1);
        if (p.t == 2) upd(0, 1e6, p.y, -1, 1);
        if (p.t == 1) ans += qry(0, 1e6, p.l, p.r, 1);
    }
    printf("%lld\n", ans);

    return 0;
}