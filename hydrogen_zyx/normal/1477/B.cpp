#include <bits/stdc++.h>

using namespace std;
int N;

char a[1 << 20], b[1 << 20];
int tree[1 << 21];
int lazy[1 << 21];

void init() {
    for (int i = 0; i < (N << 1); i++) {
        tree[i] = 0;
        lazy[i] = -1;
    }
}

void pushdown(int k, int l, int r) {
    if (k >= N || lazy[k] == -1) return;
    int mid = (l + r) >> 1;
    tree[k << 1] = lazy[k] * (mid - l + 1);
    tree[k << 1 | 1] = lazy[k] * (r - mid);
    lazy[k << 1] = lazy[k];
    lazy[k << 1 | 1] = lazy[k];
    lazy[k] = -1;
}

void pushup(int k, int l, int r) {
    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

int query_range(int k, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return tree[k];
    }
    pushdown(k, l, r);
    int mid = (l + r) >> 1;
    int lq = query_range(k << 1, l, mid, ql, qr);
    int rq = query_range(k << 1 | 1, mid + 1, r, ql, qr);
    return lq + rq;
}

void change_range(int k, int l, int r, int ql, int qr, int x) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        tree[k] = (r - l + 1) * x;
        lazy[k] = x;
        return;
    }
    pushdown(k, l, r);
    int mid = (l + r) >> 1;
    change_range(k << 1, l, mid, ql, qr, x);
    change_range(k << 1 | 1, mid + 1, r, ql, qr, x);
    pushup(k, l, r);
}

pair<int, int> c[1 << 20];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cin >> a + 1 >> b + 1;
        for (int i = 1; i <= m; i++) {
            cin >> c[i].first >> c[i].second;
        }
        N = 1;
        while (N < n) N *= 2;
        init();
        for (int i = 1; i <= n; i++) {
            if (b[i] == '0') change_range(1, 1, N, i, i, 0);
            else change_range(1, 1, N, i, i, 1);
        }
        bool ok = 1;
        for (int i = m; i >= 1; i--) {
            int len = c[i].second - c[i].first + 1;
            int cnt = query_range(1, 1, N, c[i].first, c[i].second);
            if (cnt * 2 == len) {
                ok = 0;
                break;
            }
            int bian;
            if (cnt * 2 > len) bian = 1;
            else bian = 0;
            change_range(1, 1, N, c[i].first, c[i].second, bian);
        }
        for (int i = 1; i <= n; i++) {
            if (query_range(1, 1, N, i, i) != a[i] - '0') ok = 0;

        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}