#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e6;
int tree[MAXN];
int add[MAXN];

void pull(int v) {
    tree[v] = min(tree[v * 2] + add[v * 2], tree[v * 2 + 1] + add[v * 2 + 1]);
}

void push(int v) {
    tree[v] += add[v];
    tree[v * 2] += add[v];
    tree[v * 2 + 1] += add[v];
    add[v] = 0;
}

void update(int v, int vl, int vr, int l, int r, int val) {
    if (l >= vr || r <= vl) {
        return;
    }
    if (l <= vl && r >= vr) {
        add[v] += val;
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2, vl, vm, l, r, val);
    update(v * 2 + 1, vm, vr, l, r, val);
    pull(v);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l >= vr || r <= vl) {
        return 1e9;
    }
    if (l <= vl && r >= vr) {
        return tree[v] + add[v];
    }
    push(v);
    int vm = (vl + vr) / 2;
    int res1 = get(v * 2, vl, vm, l, r);
    int res2 = get(v * 2 + 1, vm, vr, l, r);
    return min(res1, res2);
}

array<int, 3> seg[MAXN];

main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        l--; r--;
        seg[i] = {w, l, r};
    }
    sort(seg, seg + n);
    int ans = 1e9;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        while (r < n && get(1, 0, m, 0, m - 1) <= 0) {
            update(1, 0, m, seg[r][1], seg[r][2], 1);
            r++;
        }
        /// cout << r << endl;
        if (get(1, 0, m, 0, m - 1) > 0) {
            ans = min(ans, seg[r - 1][0] - seg[i][0]);
        }
        update(1, 0, m, seg[i][1], seg[i][2], -1);
    }
    cout << ans;
    return 0;
}