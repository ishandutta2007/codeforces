#include <bits/stdc++.h>

const int P = 1000000007;

int n, m;

std::vector<bool> vis;

std::vector<int> Par, Dis, a, b, l, top, p, type, len;

std::vector<unsigned> v;

std::vector<std::vector<int> > f, dp;

std::vector<std::vector<std::pair<int, int> > > e;

std::map<int, int> id;

void Inc(int &a, int b) { a += b - P, a += a >> 31 & P; }

void Dfs(int u) {
    for (auto [v, i] : e[u]) {
        if (Par[v] == -1) Dis[v] = Dis[u] ^ l[i], vis[i] = true, top[v] = top[u], Par[v] = u, Dfs(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    v = {0};
    id[0] = 0;
    for (int i = 0; i < int(v.size()); ++i) {
        unsigned u = v[i];
        for (int j = 1; j < 32; ++j) {
            if (u >> j & 1) continue;
            unsigned s = u;
            for (int k = 0; k < 32; ++k) {
                if (u >> k & 1) s |= 1 << (k ^ j);
            }
            s |= 1 << j;
            if (id.count(s)) continue;
            id[s] = v.size(), v.push_back(s);
        }
    }
    int cnt = v.size();
    f.assign(cnt, std::vector<int>(cnt));
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            if (v[i] & v[j] && (f[i][j] = -1)) continue;
            unsigned s = v[i] | v[j];
            for (int x = 1; x < 32; ++x) {
                if (v[j] >> x & 1) {
                    for (int y = 0; y < 32; ++y) {
                        if (v[i] >> y & 1) s |= 1 << (y ^ x);
                    }
                }
            }
            f[i][j] = id[s];
        }
    }
    std::cin >> n >> m;
    Par.assign(n, -1), a.resize(m), b.resize(m), l.resize(m), e.resize(n), top.resize(n);
    type.resize(n), p.assign(n, -1), vis.resize(m), len.resize(n), Dis.resize(n), Par[0] = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i] >> l[i], --a[i], --b[i];
        if (a[i] == 0) {
            Par[b[i]] = 0, Dis[b[i]] = l[i], vis[i] = true;
        } else if (b[i] == 0) {
            Par[a[i]] = 0, Dis[a[i]] = l[i], vis[i] = true;
        }
        e[a[i]].emplace_back(b[i], i);
        e[b[i]].emplace_back(a[i], i);
    }
    for (int i = 1; i < n; ++i) {
        if (Par[i] == 0) top[i] = i, Dfs(i);
    }
    for (int i = 0; i < m; ++i) {
        if (!vis[i]) {
            int u = a[i], v = b[i];
            if (top[u] != top[v]) {
                p[u] = v, p[v] = u, len[u] = len[v] = Dis[u] ^ Dis[v] ^ l[i];
                continue;
            }
            int t = top[u];
            if (type[t] == -1) continue;
            if ((Dis[u] ^ Dis[v] ^ l[i]) == 0 && (type[t] = -1)) continue;
            type[t] = f[type[t]][Dis[u] ^ Dis[v] ^ l[i]];
        }
    }
    dp.assign(2, std::vector<int>(cnt));
    int cur = 0;
    dp[cur][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (top[i] == i && p[i] < i) {
            cur ^= 1, dp[cur] = dp[cur ^ 1];
            if (p[i] == -1) {
                if (type[i] != -1) {
                    for (int j = 0; j < cnt; ++j) {
                        if (f[j][type[i]] != -1) Inc(dp[cur][f[j][type[i]]], dp[cur ^ 1][j]);
                    }
                }
            } else {
                int k = p[i];
                if (type[i] == -1 || type[k] == -1) continue;
                int ty = f[type[i]][type[k]];
                if (ty != -1) {
                    for (int j = 0; j < cnt; ++j) {
                        if (f[j][ty] != -1) {
                            Inc(dp[cur][f[j][ty]], dp[cur ^ 1][j]);
                            Inc(dp[cur][f[j][ty]], dp[cur ^ 1][j]);
                        }
                    }
                }
                if (len[i] != 0 && ty != -1) {
                    ty = f[ty][len[i]];
                    if (ty != -1) {
                        for (int j = 0; j < cnt; ++j) {
                            if (f[j][ty] != -1) Inc(dp[cur][f[j][ty]], dp[cur ^ 1][j]);
                        }
                    }
                }
            }
        }
    }
    std::cout << std::accumulate(dp[cur].begin(), dp[cur].end(), 0LL) % P << "\n";
    return 0;
}