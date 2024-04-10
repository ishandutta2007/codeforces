#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;
vector<pair<int, int>> E[N];
int n, t[4 * N], p[N], ans[N], vl[N], vr[N], tmp;
vector<int> st[N];

int get(int v) {
    return (v == p[v] ? v : p[v] = get(p[v]));
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        sort(E[l].rbegin(), E[l].rend());
        if ((int) E[l].size()) {
            t[v] = E[l].back().first;
        } else {
            t[v] = N;
        }
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

void get(int v, int l, int r, int l1, int r1) {
    if (l >= r1 || l1 >= r || t[v] >= r1) {
        return;
    }
    if (l + 1 == r) {
        while ((int) E[l].size() && E[l].back().first < r1) {
            ans[E[l].back().second] = tmp;
            E[l].pop_back();
        }
        if ((int) E[l].size()) {
            t[v] = E[l].back().first;
        } else {
            t[v] = N;
        }
        return;
    }
    int m = (l + r) / 2;
    get(v * 2 + 1, l, m, l1, r1);
    get(v * 2 + 2, m, r, l1, r1);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

void solve() {
    int m, q;
    cin >> n >> m >> q;
    iota(p, p + n, 0);
    for (int i = 0; i < n; i++) {
        E[i].clear();
        vl[i] = vr[i] = i;
        st[i] = {i};
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
        e[i].first--, e[i].second--;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            ans[i] = 0;
        } else {
            E[l].push_back({r, i});
        }
    }
    build(0, 0, n);
    tmp = 0;
    for (auto [x, y] : e) {
        x = get(x), y = get(y);
        tmp++;
        if (x == y) {
            continue;
        }
        if ((int) st[x].size() > (int) st[y].size()) {
            swap(x, y);
        }
        for (auto v : st[x]) {
            p[v] = v;
        }
        for (auto v : st[x]) {
            vl[v] = vr[v] = v;
            if (v - 1 >= 0 && get(v - 1) == y) {
                int l = vl[v - 1];
                vl[v] = l;
                vr[l] = v;
            }
            if (v + 1 < n && get(v + 1) == y) {
                int r = vr[v + 1];
                vl[r] = v;
                vr[v] = r;
            }
            if (vl[v] != v && vr[v] != v) {
                vr[vl[v]] = vr[v];
                vl[vr[v]] = vl[v];
            }
            p[v] = y;
            st[y].push_back(v);
            //cout << v << " " << y << " " << vl[v] << " " << vr[v] << endl;
            get(0, 0, n, vl[v], vr[v] + 1);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}