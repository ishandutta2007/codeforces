#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 22;
int n, q, a[N], ans[N], cnt[N], t[4 * N];
vector<array<int, 3>> qu[N];
vector<int> g[N];
set<int> dp[N];

void update(int v, int l, int r, int i, int x) {
    if (l + 1 == r) {
        t[v] += x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        update(v * 2 + 1, l, m, i, x);
    } else {
        update(v * 2 + 2, m, r, i, x);
    }
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int get(int v, int l, int r, int x) {
    if (t[v] < x) {
        return -1;
    }
    if (l + 1 == r) {
        return l;
    }
    int m = (l + r) / 2;
    int res = get(v * 2 + 1, l, m, x);
    if (res != -1) {
        return res;
    }
    return get(v * 2 + 2, m, r, x - t[v * 2 + 1]);
}

int getsum(int v, int l, int r, int l1, int r1) {
    if (l1 >= r || l >= r1) {
        return 0;
    }
    if (l1 <= l && r <= r1) {
        return t[v];
    }
    int m = (l + r) / 2;
    return getsum(v * 2 + 1, l, m, l1, r1) + getsum(v * 2 + 2, m, r, l1, r1);
}

void del(int x) {
    if (cnt[x]) {
        dp[cnt[x]].erase(x);
        update(0, 0, n + 1, cnt[x], -1);
    }
}

void add(int x) {
    if (cnt[x]) {
        dp[cnt[x]].insert(x);
        update(0, 0, n + 1, cnt[x], 1);
    }
}

void dfs(int v) {
    del(a[v]);
    cnt[a[v]]++;
    add(a[v]);
    for (auto u : g[v]) {
        dfs(u);
    }
    for (auto arr : qu[v]) {
        int i = arr[0], l = arr[1], k = arr[2];
        k += getsum(0, 0, n + 1, 0, l);
        int res = get(0, 0, n + 1, k);
        if (res != -1) {
            ans[i] = *dp[res].begin();
        } else {
            ans[i] = -1;
        }
    }
    del(a[v]);
    cnt[a[v]]--;
    add(a[v]);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        qu[i].clear();
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    fill(t, t + 4 * (n + 1), 0);
    for (int i = 0; i < q; i++) {
        int v, l, k;
        cin >> v >> l >> k;
        v--;
        qu[v].push_back({i, l, k});
    }
    dfs(0);
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