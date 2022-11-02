#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e6, MAX2 = 4e6;
int tree[MAX2];
int add[MAX2];
int arr[MAXN];

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
    int n, w;
    cin >> n >> w;
    for (int j = 0; j < n; ++j) {
        int len;
        cin >> len;
        multiset<int> st;
        int l2 = w - len + 1;
        for (int i = 0; i < len; ++i) {
            cin >> arr[i];
            if (st.size() < l2) {
                st.insert(arr[i]);
                auto it = st.end();
                it--;
                int mx = *it;
                if (i < w - len) {
                    mx = max(mx, (int64_t)0);
                }
                update(1, i, i + 1, mx, 0, w);
            } else {
                st.erase(st.lower_bound(arr[i - l2]));
                st.insert(arr[i]);
                auto it = st.end();
                it--;
                int mx = *it;
                if (i < w - len) {
                    mx = max(mx, (int64_t)0);
                }
                update(1, i, i + 1, mx, 0, w);
            }
        }
        if (st.size() == len) {
            auto it = st.end();
            it--;
            int mx = *it;
            mx = max(mx, (int64_t)0);
            update(1, len, w - len + 1, mx, 0, w);
            for (int i = 0; i < len - 1; ++i) {
                st.erase(st.lower_bound(arr[i]));
                auto it = st.end();
                it--;
                int mx = *it;
                mx = max(mx, (int64_t)0);
                update(1, w - len + 1 + i, w - len + 2 + i, mx, 0, w);
            }
        } else {
            for (int i = 0; i < l2 - 1; ++i) {
                st.erase(st.lower_bound(arr[i + len - l2]));
                auto it = st.end();
                it--;
                int mx = *it;
                mx = max(mx, (int64_t)0);
                update(1, len + i, len + i + 1, mx, 0, w);
            }
        }
    }
    for (int i = 0; i < w; ++i) {
        int x = get(1, i, 0, w);
        cout << x << " ";
    }
    return 0;
}