#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1000000007;
void ensure(bool exp) {
    if (!exp) {
        cout << 0 << endl;
        exit(0);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> to(2 * n - 2), pre(2 * n - 2, -1), nxt(2 * n - 2, -1), head(n, -1), tail(n, -1), in(n, -1), dep(n);
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        to[2 * i] = v;
        to[2 * i + 1] = u;
        e[u].push_back(2 * i);
        e[v].push_back(2 * i + 1);
    }
    function<void(int)> dfs = [&](int u) {
        for (int i : e[u]) {
            if (i == (in[u] ^ 1))
                continue;
            int v = to[i];
            dep[v] = dep[u] + 1;
            in[v] = i;
            dfs(v);
        }
    };
    dfs(0);
    auto getPath = [&](int u, int v) {
        vector<int> l, r;
        while (u != v) {
            if (dep[u] > dep[v]) {
                l.push_back(in[u] ^ 1);
                u = to[in[u] ^ 1];
            } else {
                r.push_back(in[v]);
                v = to[in[v] ^ 1];
            }
        }
        reverse(r.begin(), r.end());
        l.insert(l.end(), r.begin(), r.end());
        return l;
    };
    auto solve = [&](int u, int v) {
        auto p = move(getPath(u, v));
        ensure(head[u] == -1);
        ensure(tail[v] == -1);
        ensure(pre[p[0]] == -1);
        ensure(nxt[p.back() ^ 1] == -1);
        head[u] = p[0];
        tail[v] = p.back() ^ 1;
        pre[p[0]] = -2;
        nxt[p.back() ^ 1] = -2;
        for (int i = 0; i + 1 < p.size(); ++i) {
            int x = to[p[i]];
            ensure(nxt[p[i] ^ 1] == -1);
            ensure(pre[p[i + 1]] == -1);
            nxt[p[i] ^ 1] = p[i + 1];
            pre[p[i + 1]] = nxt[p[i] ^ 1];
        }
    };
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        if (a == -1)
            continue;
        ensure(i != a);
        solve(i, a);
    }
    vector<int> used(2 * n - 2), cnt(n);
    for (int i = 0; i < 2 * n - 2; ++i) {
        if (used[i] || pre[i] >= 0)
            continue;
        int c = 0, ed;
        for (int j = i; j >= 0; ed = j, j = nxt[j])
            ++c;
        for (int j = i; j >= 0; j = nxt[j])
            used[j] = c;
        if (pre[i] != -2 && nxt[ed] != -2)
            ++cnt[to[i ^ 1]];
        if (pre[i] == -2 && nxt[ed] == -2)
            ensure(c == e[to[i ^ 1]].size());
    }
    for (int i = 0; i < 2 * n - 2; ++i)
        ensure(used[i] > 0);
    int ans = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= cnt[i]; ++j)
            ans = 1LL * ans * j % P;
    cout << ans << endl;
    return 0;
}