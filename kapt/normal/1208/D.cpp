#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5, MAX2 = 8e5;
int tree[MAX2];
int add[MAX2];
int pref[MAXN];
int arr[MAXN];
int ans[MAXN];

inline void push(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tree[v] += add[v];
        add[v] = 0;
        return;
    }
    int v1 = v * 2;
    int v2 = v * 2 + 1;
    add[v1] += add[v];
    add[v2] += add[v];
    tree[v] += add[v];
    add[v] = 0;
}

inline void pull(int v) {
    int v1 = 2 * v;
    int v2 = 2 * v + 1;
    tree[v] = max(tree[v1], tree[v2]);
}

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tree[v] = pref[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(v * 2, vl, vm);
    build(v * 2 + 1, vm, vr);
    pull(v);
}

int get(int v, int l, int vl, int vr) {
    while (vr - vl != 1) {
        push(v, vl, vr);
        int vm = (vl + vr) / 2;
        if (l < vm) {
            v *= 2;
            vr = vm;
        } else {
            v *= 2;
            v++;
            vl = vm;
        }
    }
    push(v, vl, vr);
    return tree[v];
}

void update(int v, int l, int r, int val, int vl, int vr) {
    push(v, vl, vr);
    if (l >= vr || r <= vl) {
        return;
    }
    if (l <= vl && r >= vr) {
        add[v] += val;
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2, l, r, val, vl, vm);
    update(v * 2 + 1, l, r, val, vm, vr);
    push(v * 2, vl, vm);
    push(v * 2 + 1, vm, vr);
    pull(v);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pref[0] = 0;
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + i;
    }
    build(1, 0, n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        int x = arr[i];
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int fm = get(1, m, 0, n);
            if (fm > x) {
                r = m;
            } else {
                l = m;
            }
        }
        ans[i] = l + 1;
        update(1, l + 1, n, -l - 1, 0, n);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}