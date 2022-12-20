#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 1;
int m[N], d[N];
int a[N], b[N];
int v;

void push(int v) {
    m[2*v + 1] += d[v];
    m[2*v + 2] += d[v];
    d[2*v + 1] += d[v];
    d[2*v + 2] += d[v];
    d[v] = 0;
}

void recalc(int v) {
    m[v] = min(m[2*v + 1], m[2*v + 2]) + d[v];
}

void add(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r) {
        m[v] += x;
        d[v] += x;
    } else if (l >= vr || vl >= r)
            return;
        else {
            push(v);
            add(2*v + 1, vl, (vl + vr) / 2, l, r, x);
            add(2*v + 2, (vl + vr) / 2, vr, l, r, x);
            recalc(v);
        }
}

int fint(int v, int vl, int vr) {
    if (m[v] >= 0)
        return -1;
    if (vr - vl == 1)
        return vl;
    push(v);
    if (m[2*v + 2] < 0)
        return fint(2*v + 2, (vl + vr) / 2, vr);
    else
        return fint(2*v + 1, vl, (vl + vr) / 2);
}

int main() {
    int i, j, k, n, t, x, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v = 1;
    while (v < 1e6) v *= 2;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        add(0, 1, v + 1, 1, a[i] + 1, -1);
    }
    for (i = 0; i < k; ++i) {
        cin >> b[i];
        add(0, 1, v + 1, 1, b[i] + 1, 1);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> t >> j >> x;
        --j;
        if (t == 1) {
            add(0, 1, v + 1, 1, a[j] + 1, 1);
            a[j] = x;
            add(0, 1, v + 1, 1, a[j] + 1, -1);
        } else {
            add(0, 1, v + 1, 1, b[j] + 1, -1);
            b[j] = x;
            add(0, 1, v + 1, 1, b[j] + 1, 1);
        }
        cout << fint(0, 1, v + 1) << "\n";
    }
}