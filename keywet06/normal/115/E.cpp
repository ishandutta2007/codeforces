#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 2e5 + 5;

int n, m, L, R;

int64 add;
int64 d[N * 4], tag[N * 4], a[N];

vector<pair<int, int64>> v[N];

inline int64 max(int64& a, int64& b) { return a > b ? a : b; }

inline void pd(int& o) {
    if (tag[o]) {
        int l = o << 1, r = l | 1;
        d[l] += tag[o];
        d[r] += tag[o];
        tag[l] += tag[o];
        tag[r] += tag[o];
        tag[o] = 0;
    }
}

void add_1(int l, int r, int o) {
    if (l == r) {
        d[o] += add;
    } else {
        pd(o);
        int mid = l + r >> 1;
        if (L <= mid) {
            add_1(l, mid, o << 1);
        } else {
            add_1(mid + 1, r, o << 1 | 1);
        }
        d[o] = max(d[o << 1], d[o << 1 | 1]);
    }
}

void add_lot(int l, int r, int o) {
    if (L <= l && r <= R) {
        d[o] += add, tag[o] += add;
    } else {
        int mid = l + r >> 1;
        pd(o);
        if (L <= mid) add_lot(l, mid, o << 1);
        if (mid < R) add_lot(mid + 1, r, o << 1 | 1);
        d[o] = max(d[o << 1], d[o << 1 | 1]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, l, r; i <= m; ++i) {
        cin >> l >> r >> add;
        v[r].push_back(make_pair(l, add));
    }
    for (int i = 1; i <= n; ++i) {
        L = n - i, add = d[1];
        add_1(0, n, 1);
        ++L, R = n, add = -a[i];
        add_lot(0, n, 1);
        for (auto it : v[i]) {
            L = n - it.first + 1, R = n, add = it.second;
            add_lot(0, n, 1);
        }
    }
    cout << d[1] << endl;
    return 0;
}