#include <bits/stdc++.h>

typedef long long int64;

const int N = 300005;

bool vis[N], ib[N];

int n, q;
int prv[N], b[N], pub[N], siz[N];

int64 maxi[N], d[N];

std::vector<std::pair<int64, int> > adj[N];

void dfs(int id) {
    vis[id] = true;
    for (auto cur : adj[id]) {
        if (!vis[cur.second]) {
            d[cur.second] = d[id] + cur.first;
            prv[cur.second] = id;
            dfs(cur.second);
        }
    }
}

void dfs2(int id) {
    ++siz[pub[id]];
    maxi[pub[id]] = std::max(maxi[pub[id]], d[id]);
    for (auto cur : adj[id]) {
        if (!pub[cur.second]) {
            if (ib[cur.second]) {
                pub[cur.second] = cur.second;
            } else {
                pub[cur.second] = pub[id];
            }
            dfs2(cur.second);
        }
    }
}

int64 ans;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int u, v;
        int64 w;
        std::cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dfs(1);
    int cur = n;
    int cnt = 0;
    while (cur != 0) {
        ib[cur] = true;
        ++cnt;
        cur = prv[cur];
    }
    cur = n;
    for (int i = cnt; i >= 1; --i) {
        b[i] = cur;
        cur = prv[cur];
    }
    pub[1] = 1;
    dfs2(1);
    for (int i = 1; i <= cnt; ++i) {
        if (siz[b[i]] >= 3) ans = d[n];
        if (i != 1 && (siz[b[i]] >= 2 || siz[b[i - 1]] >= 2)) {
            ans = std::max(ans, maxi[b[i - 1]] + maxi[b[i]] - d[b[i]] + d[n] - d[b[i]]);
        }
        if (i > 2) ans = std::max(ans, d[b[i - 2]] + d[n] - d[b[i]]);
    }
    for (int i = 1; i <= q; ++i) {
        int64 w;
        std::cin >> w;
        std::cout << std::min(d[n], ans + w) << std::endl;
    }
    return 0;
}