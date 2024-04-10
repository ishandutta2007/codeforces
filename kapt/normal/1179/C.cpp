#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define add second
#define min_v first

const int inf = -1e9, maxn = 5e6, max2 = 1e6;
pair <int, int> tree[maxn];
int a[maxn], b[maxn];

void pull(int v) {
    tree[v].min_v = min(tree[v * 2].min_v, tree[v * 2 + 1].min_v);
}

void push(int l, int r, int v) {
    if (r - l != 1){
        tree[2 * v].add += tree[v].add;
        tree[2 * v + 1].add += tree[v].add;
    }
    tree[v].min_v += tree[v].add;
    tree[v].add = 0;
}

void group(int v, int l, int r, int vl, int vr, int val) {
    push(vl, vr, v);
    if (r <= l) {
        return;
    }
    if (l == vl && r == vr) {
        tree[v].add += val;
        push(vl, vr, v);
        return;
    }
    int vm = (vl + vr) / 2;
    group(2 * v, l, min(r, vm), vl, vm, val);
    group(2 * v + 1, max(l, vm), r, vm, vr, val);
    pull(v);
}

int get(int v, int vl, int vr) {
    // cout << "v: " << v << "\n";
    push(vl, vr, v);
    if (vr == vl + 1) {
        return vl;
    }
    int vm = (vl + vr) / 2;
    int v1 = v * 2;
    int v2 = v * 2 + 1;
    push(vl, vm, v1); push(vm, vr, v2);
    /*cout << v1 << " " << v2 << "\n";
    cout << vl << " " << vr << "\n";
    cout << tree[v].add << "\n";
    cout << tree[v1].add << " " << tree[v2].add << "\n";
    cout << tree[v].min_v << "\n";
    cout << tree[v1].min_v << " " << tree[v2].min_v << "\n";*/
    if (tree[v2].min_v + tree[v2].add < 0) {
        return get(v2, vm, vr);
    } else if (tree[v1].min_v + tree[v1].add < 0) {
        return get(v1, vl, vm);
    } else {
        return -1;
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i + 1] = x;
        group(1, 1, x + 1, 1, max2 + 1, -1);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b[i + 1] = x;
        group(1, 1, x + 1, 1, max2 + 1, 1);
    }
    int q;
    cin >> q;
    /*for (int i = 0; i < 20; ++i) {
        cout << tree[i].min_v << " ";
    }
    cout << "\n";
    cout << get(1, 1, max2 + 1) << "\n";*/
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            group(1, 1, a[i] + 1, 1, max2 + 1, 1);
            a[i] = x;
            group(1, 1, a[i] + 1, 1, max2 + 1, -1);
        } else {
            int i, x;
            cin >> i >> x;
            group(1, 1, b[i] + 1, 1, max2 + 1, -1);
            b[i] = x;
            group(1, 1, b[i] + 1, 1, max2 + 1, 1);
        }
        /*for (int i = 0; i < 20; ++i) {
            cout << tree[i].min_v << " ";
        }
        cout << "\n";*/
        cout << get(1, 1, max2 + 1) << "\n";
    }
    return 0;
}