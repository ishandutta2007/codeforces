#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

int sz, X1 = 2e9, X2 = 2e9, Y1 = 2e9, Y2 = 2e9, n, x[500000], y[500000], c[500000];
long long ans = 0, d[4000000];
pair<long long, int> t[4000000];
vector<long long> z = {0, (int) 2e9};
vector<int> s[1000000];

void push(int v, int l, int r) {
    t[v].fi += d[v];
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    d[v] = 0;
}

void build(int v, int l, int r) {
    d[v] = 0;
    if (l + 1 == r) {
        t[v] = {-z[l], z[l]};
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

void update(int v, int l, int r, int l1, int r1, long long x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

pair<long long, int> get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return {-1e18, -1};
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
        z.push_back(x[i]);
        z.push_back(y[i]);
    }
    sort(z.begin(), z.end());
    z.resize(unique(z.begin(), z.end()) - z.begin());
    sz = z.size();
    build(0, 0, sz);
    unordered_map<long long, int> ind;
    for (int i = 0; i < z.size(); i++) ind[z[i]] = i;
    for (int i = 0; i < n; i++) x[i] = ind[x[i]];
    for (int i = 0; i < n; i++) y[i] = ind[y[i]];
    for (int i = 0; i < n; i++) {
        s[min(x[i], y[i])].push_back(i);
    }
    for (int l = sz - 1; l >= 0; l--) {
        for (auto i : s[l]) {
            update(0, 0, sz, max(x[i], y[i]), sz, c[i]);
        }
        pair<long long, int> res = get(0, 0, sz, l, sz);
        if (res.fi + z[l] > ans) {
            ans = res.fi + z[l];
            X1 = Y1 = z[l];
            X2 = Y2 = res.se;
        }
    }
    cout << ans << endl << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
}