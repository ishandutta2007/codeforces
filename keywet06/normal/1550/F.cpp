#include <bits/stdc++.h>

const int INF = 1e9;

struct edge {
    int u, w;
};

std::vector<std::vector<edge>> g;

struct node {
    int v, u, w;
};

bool operator<(const node &a, const node &b) {
    if (a.w != b.w) return a.w < b.w;
    if (std::min(a.v, a.u) != std::min(b.v, b.u))
        return std::min(a.v, a.u) < std::min(b.v, b.u);
    return std::max(a.v, a.u) < std::max(b.v, b.u);
}

std::vector<std::vector<int>> o;
std::vector<int> p;

bool unite(int a, int b) {
    a = p[a], b = p[b];
    if (a == b) return false;
    if (o[a].size() < o[b].size()) std::swap(a, b);
    for (int v : o[b]) {
        p[v] = a;
        o[a].push_back(v);
    }
    o[b].clear();
    return true;
}

std::vector<int> mn;

void dfs(int v, int p, int d) {
    mn[v] = d;
    for (auto e : g[v])
        if (e.u != p) dfs(e.u, v, std::max(d, e.w));
}

int main() {
    int n, q, s, d;
    scanf("%d%d%d%d", &n, &q, &s, &d);
    --s;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::vector<int> idx(a[n - 1] + 1);
    for (int i = 0; i < n; ++i) idx[a[i]] = i;
    o.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i) o[i] = std::vector<int>(1, i), p[i] = i;
    g.resize(n);
    std::set<int> pos(a.begin(), a.end());
    int cnt = n;
    while (cnt > 1) {
        std::vector<node> es;
        for (const std::vector<int> &comp : o)
            if (!comp.empty()) {
                for (int i : comp) pos.erase(a[i]);
                node mn = {-1, -1, INF};
                for (int i : comp) {
                    for (int dx : {-d, d}) {
                        auto it = pos.lower_bound(a[i] + dx);
                        if (it != pos.end())
                            mn = std::min(
                                mn, {i, idx[*it], abs(abs(a[i] - *it) - d)});
                        if (it != pos.begin()) {
                            --it;
                            mn = std::min(
                                mn, {i, idx[*it], abs(abs(a[i] - *it) - d)});
                        }
                    }
                }
                for (int i : comp) pos.insert(a[i]);
                assert(mn.v != -1);
                es.push_back(mn);
            }
        for (auto e : es) {
            if (unite(e.v, e.u)) {
                --cnt;
                g[e.v].push_back({e.u, e.w});
                g[e.u].push_back({e.v, e.w});
            }
        }
    }
    mn.resize(n);
    dfs(s, -1, 0);
    while (q--) {
        int i, k;
        scanf("%d%d", &i, &k);
        --i;
        puts(mn[i] <= k ? "Yes" : "No");
    }
    return 0;
}