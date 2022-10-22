#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> t, d, b;

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = b[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

void push(int v, int l, int r) {
    if (l + 1 == r) {
        d[v] = 0;
        return;
    }
    t[v * 2 + 1] += d[v];
    t[v * 2 + 2] += d[v];
    d[v * 2 + 1] += d[v];
    d[v * 2 + 2] += d[v];
    d[v] = 0;
}


void add(int v, int l, int r, int l1, int r1, int k) {
    if (l1 >= r || l >= r1) {
        return;
    };
    push(v, l, r);
    if (l == l1 && r == r1) {
        d[v] += k;
        t[v] += k;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    add(2 * v + 1, l, m, l1, min(m, r1), k);
    add(2 * v + 2, m, r, max(l1, m), r1, k);
}

int f(int v, int l, int r, int k) {
    push(v, l, r);
    if (l + 1 == r) {
        return l + 1;
    }
    int m = (l + r) / 2;
    push(v * 2 + 1, l, m);
    push(v * 2 + 2, m, r);
   // cout << l << " " << r << " " << k << " " << t[v * 2 + 2] << endl;
    if (t[v * 2 + 2] <= k) {
        return f(v * 2 + 2, m, r, k);
    }
    else {
        return f(2 * v + 1, l, m, k);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    b.resize(n);
    t.resize(8 * n);
    d.resize(8 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            b[i] = 0;
        }
        else {
            b[i] = b[i - 1] + i;
        }
    }
    build(0, 0, n);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = f(0, 0, n, a[i]);
        add(0, 0, n, ans[i], n, -ans[i]);
    }
    for (auto c : ans) {
        cout << c << " ";
    }
}