#include <iostream>
#include <vector>
#include <algorithm>
int n, q;
std::vector<int> a, pos, ans, rt, vis, cnt, sum;
std::vector<std::vector<int>> e;
std::vector<std::vector<std::pair<long long, int>>> queries;
void dfs1(int u) {
    vis[u] = 1;
    for (int v : e[u]) {
        if (vis[v] == 0) {
            dfs1(v);
        } else if (vis[v] == 1) {
            pos[v] = 1;
            for (int i = u; i != v; i = a[i]) {
                rt[i] = v;
                ++pos[v];
            }
            rt[v] = v;
            for (int i = u, j = pos[v]; i != v; i = a[i])
                pos[i] = --j;
        }
    }
    vis[u] = 2;
}
void dfs2(int u, int d) {
    if (pos[u] == -1)
        for (auto &&[m, i] : queries[u])
            if (d + m < int(cnt.size()))
                ans[i] -= cnt[d + m];
    if (d >= int(cnt.size()))
        cnt.resize(d + 1);
    ++cnt[d];
    for (int v : e[u])
        if (pos[v] == -1)
            dfs2(v, d + 1);
    if (pos[u] == -1)
        for (auto &&[m, i] : queries[u])
            if (d + m < int(cnt.size()))
                ans[i] += cnt[d + m];
}
void dfs3(int u, int d) {
    if (d >= int(cnt.size()))
        cnt.resize(d + 1);
    ++cnt[d];
    for (int v : e[u])
        if (rt[v] != v)
            dfs3(v, d + 1);
}
void dfs4(int u, int d) {
    if (pos[u] != -1)
        for (auto &&[m, i] : queries[u])
            if (d + m < int(cnt.size()))
                ans[i] -= cnt[d + m];
    if (d >= int(cnt.size()))
        cnt.resize(d + 1);
    ++cnt[d];
    for (int v : e[u])
        if (rt[v] != v)
            dfs4(v, d + 1);
    if (pos[u] != -1)
        for (auto &&[m, i] : queries[u])
            if (d + m < int(cnt.size()))
                ans[i] += cnt[d + m];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    pos.assign(n, -1);
    e.resize(n);
    queries.resize(n);
    vis.resize(n);
    rt.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        e[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        if (vis[i] == 0)
            dfs1(i);
    std::cin >> q;
    ans.resize(q);
    for (int i = 0; i < q; ++i) {
        long long m;
        int u;
        std::cin >> m >> u;
        --u;
        queries[u].emplace_back(m, i);
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i] != -1) {
            cnt.clear();
            dfs2(i, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (rt[i] == i) {
            cnt.clear();
            dfs3(i, 0);
            sum = cnt;
            for (int j = pos[i]; j < int(sum.size()); ++j)
                sum[j] += sum[j - pos[i]];
            int j = i;
            do {
                for (auto &&[m, k] : queries[j]) {
                    long long t = m + (i == j ? 0 : pos[j]);
                    if (t >= int(cnt.size())) {
                        t %= pos[i];
                        t += (cnt.size() - t - 1) / pos[i] * pos[i];
                    } else {
                        ans[k] -= cnt[t];
                    }
                    ans[k] += sum[t];
                }
                j = a[j];
            } while (j != i);
            cnt.clear();
            dfs4(i, 0);
        }
    }
    for (int i = 0; i < q; ++i)
        std::cout << ans[i] << "\n";
    return 0;
}