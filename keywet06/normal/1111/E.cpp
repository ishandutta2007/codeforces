#include <bits/stdc++.h>

const int N = 100'000, M = 300, P = 1'000'000'007;

int n, q, dfsClock;

std::vector<int> e[N];

int fen[N], dfn[N], top[N], size[N], dep[N], parent[N], dfa[N], qv[N], f[N], dp[N + 1][M + 1];

void add(int pos, int val) {
    for (int i = pos + 1; i <= N; i += i & -i) fen[i - 1] += val;
}

int query(int pos) {
    int result = 0;
    for (int i = pos + 1; i > 0; i -= i & -i) result += fen[i - 1];
    return result;
}

void rangeAdd(int l, int r, int val) {
    add(l, val),
    add(r, -val);
}

void dfsSize(int u) {
    if (parent[u] != -1) e[u].erase(std::find(e[u].begin(), e[u].end(), parent[u]));
    size[u] = 1;
    for (int &v : e[u]) {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfsSize(v);
        size[u] += size[v];
        if (size[v] > size[e[u].front()]) std::swap(v, e[u].front());
    }
}

void dfsHLD(int u) {
    dfn[u] = dfsClock++;
    dfa[dfn[u]] = u;
    for (int v : e[u]) {
        if (v == e[u].front()) {
            top[v] = top[u];
        } else {
            top[v] = v;
        }
        dfsHLD(v);
    }
}

int reach(int u, int v) {
    int last = -1;
    while (top[u] != top[v]) {
        last = top[u];
        u = parent[top[u]];
    }
    if (u == v) {
        return last;
    } else {
        return dfa[dfn[v] + 1];
    }
}

void subtreeAdd(int root, int u, int val) {
    if (u == root) {
        rangeAdd(0, n, val);
    } else if (dfn[u] <= dfn[root] && dfn[root] < dfn[u] + size[u]) {
        int v = reach(root, u);
        rangeAdd(0, dfn[v], val);
        rangeAdd(dfn[v] + size[v], n, val);
    } else {
        rangeAdd(dfn[u], dfn[u] + size[u], val);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfsSize(0);
    dfsHLD(0);
    while (q--) {
        int k, m, root;
        std::cin >> k >> m >> root, --root;
        for (int i = 0; i < k; ++i) {
            std::cin >> qv[i];
            --qv[i];
            subtreeAdd(root, qv[i], 1);
        }
        for (int i = 0; i < k; ++i) f[i] = query(dfn[qv[i]]) - 1;
        for (int i = 0; i < k; ++i) subtreeAdd(root, qv[i], -1);
        std::sort(f, f + k);
        dp[0][0] = 1;
        for (int i = 0; i < k; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i + 1][j] = (1LL * dp[i][j] * std::max(0, j - f[i]) + dp[i][j - 1]) % P;
            }
        }
        std::cout << std::accumulate(dp[k], dp[k] + m + 1, 0LL) % P << "\n";
    }
    return 0;
}