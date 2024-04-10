#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
constexpr int P = 1'000'000'007;
int n, m;
std::vector<unsigned> v;
std::map<int, int> id;
std::vector<std::vector<int>> f, dp;
std::vector<std::vector<std::pair<int, int>>> e;
std::vector<int> parent, dis, a, b, l, top, p, type, len;
std::vector<bool> vis;
void inc(int &a, int b) {
    a += b - P;
    a += a >> 31 & P;
}
void dfs(int u) {
    for (auto [v, i] : e[u]) {
        if (parent[v] == -1) {
            dis[v] = dis[u] ^ l[i];
            vis[i] = true;
            top[v] = top[u];
            parent[v] = u;
            dfs(v);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    v = {0};
    id[0] = 0;
    for (int i = 0; i < int(v.size()); ++i) {
        unsigned u = v[i];
        for (int j = 1; j < 32; ++j) {
            if (u >> j & 1)
                continue;
            unsigned s = u;
            for (int k = 0; k < 32; ++k)
                if (u >> k & 1)
                    s |= 1 << (k ^ j);
            s |= 1 << j;
            if (id.count(s))
                continue;
            id[s] = v.size();
            v.push_back(s);
        }
    }
    int cnt = v.size();
    f.assign(cnt, std::vector<int>(cnt));
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            if (v[i] & v[j]) {
                f[i][j] = -1;
                continue;
            }
            unsigned s = v[i] | v[j];
            for (int x = 1; x < 32; ++x)
                if (v[j] >> x & 1)
                    for (int y = 0; y < 32; ++y)
                        if (v[i] >> y & 1)
                            s |= 1 << (y ^ x);
            f[i][j] = id[s];
        }
    }
    std::cin >> n >> m;
    parent.assign(n, -1);
    a.resize(m);
    b.resize(m);
    l.resize(m);
    e.resize(n);
    top.resize(n);
    type.resize(n);
    p.assign(n, -1);
    vis.resize(m);
    len.resize(n);
    dis.resize(n);
    parent[0] = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i] >> l[i];
        --a[i];
        --b[i];
        if (a[i] == 0) {
            parent[b[i]] = 0;
            dis[b[i]] = l[i];
            vis[i] = true;
        } else if (b[i] == 0) {
            parent[a[i]] = 0;
            dis[a[i]] = l[i];
            vis[i] = true;
        }
        e[a[i]].emplace_back(b[i], i);
        e[b[i]].emplace_back(a[i], i);
    }
    for (int i = 1; i < n; ++i) {
        if (parent[i] == 0) {
            top[i] = i;
            dfs(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (!vis[i]) {
            int u = a[i];
            int v = b[i];
            if (top[u] != top[v]) {
                p[u] = v;
                p[v] = u;
                len[u] = len[v] = dis[u] ^ dis[v] ^ l[i];
                continue;
            }
            int t = top[u];
            if (type[t] == -1)
                continue;
            if ((dis[u] ^ dis[v] ^ l[i]) == 0) {
                type[t] = -1;
                continue;
            }
            type[t] = f[type[t]][dis[u] ^ dis[v] ^ l[i]];
        }
    }
    dp.assign(2, std::vector<int>(cnt));
    int cur = 0;
    dp[cur][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (top[i] == i && p[i] < i) {
            cur ^= 1;
            dp[cur] = dp[cur ^ 1];
            if (p[i] == -1) {
                if (type[i] != -1)
                    for (int j = 0; j < cnt; ++j)
                        if (f[j][type[i]] != -1)
                            inc(dp[cur][f[j][type[i]]], dp[cur ^ 1][j]);
            } else {
                int k = p[i];
                if (type[i] == -1 || type[k] == -1)
                    continue;
                int ty = f[type[i]][type[k]];
                if (ty != -1) {
                    for (int j = 0; j < cnt; ++j) {
                        if (f[j][ty] != -1) {
                            inc(dp[cur][f[j][ty]], dp[cur ^ 1][j]);
                            inc(dp[cur][f[j][ty]], dp[cur ^ 1][j]);
                        }
                    }
                }
                if (len[i] != 0 && ty != -1) {
                    ty = f[ty][len[i]];
                    if (ty != -1)
                        for (int j = 0; j < cnt; ++j)
                            if (f[j][ty] != -1)
                                inc(dp[cur][f[j][ty]], dp[cur ^ 1][j]);
                }
            }
        }
    }
    std::cout << std::accumulate(dp[cur].begin(), dp[cur].end(), 0LL) % P << "\n";
    return 0;
}