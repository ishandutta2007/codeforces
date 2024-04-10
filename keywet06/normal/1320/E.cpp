#include <bits/stdc++.h>

using pair = std::pair<int, int>;

template <typename _Tp>
using r_priority_queue =
    std::priority_queue<_Tp, std::vector<_Tp>, std::greater<_Tp> >;

const int C = 20;
const int N = 200005;
const int M = N << 1;
const int INF = 1e9;

int n, q, k, m, x, y, u, v, dcnt, cnt, c;
int dfn[N], deep[N], head[N], vis[N], vir[N], dis[N], pk[N], pm[N], sd[N],
    kis[N], nxt[N], lst[N];
int next[M], to[M], val[M], p[M];
int fa[N][C];

std::stack<int> st;

std::vector<int> tos[N];

r_priority_queue<pair> f[N];

inline void dfs(int u, int f) {
    dfn[u] = ++dcnt, fa[u][0] = f, deep[u] = deep[f] + 1;
    for (int i = 1; i < C; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : tos[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
}

inline int lca(int u, int v) {
    if (deep[u] < deep[v]) std::swap(u, v);
    for (int x = deep[u] - deep[v], i = 0; x; ++i) {
        while (!(x & 1 << i)) ++i;
        u = fa[u][i], x -= 1 << i;
    }
    for (int i = C - 1; ~i; --i) {
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    }
    return u == v ? u : fa[u][0];
}

inline void trick(int u) {
    if (vis[u] < c) vis[u] = c, head[u] = vir[u] = 0, dis[u] = INF;
}

inline void insert(int u, int v, int w) {
    next[++cnt] = head[u], head[u] = cnt;
    to[cnt] = v, val[cnt] = w;
}

inline void addedge(int u, int v) {
    trick(u), trick(v);
    int w = std::abs(deep[u] - deep[v]);
    insert(u, v, w), insert(v, u, w);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y;
        tos[x].push_back(y);
        tos[y].push_back(x);
    }
    dfs(1, 1);
    std::cin >> q;
    for (c = 1; c <= q; ++c) {
        std::cin >> k >> m, cnt = 0;
        for (int i = 1; i <= k; ++i) {
            std::cin >> pk[i];
            std::cin >> sd[i];
            kis[pk[i]] = c, p[i] = pk[i];
        }
        for (int i = 1; i <= m; ++i) std::cin >> pm[i], p[i + k] = pm[i];
        std::sort(p + 1, p + k + m + 1,
                  [](int x, int y) { return dfn[x] < dfn[y]; });
        st.push(1);
        for (int i = 1; i <= k + m; ++i) {
            x = lca(st.top(), p[i]), y = 0;
            while (deep[st.top()] > deep[x]) {
                y = st.top(), st.pop();
                if (deep[st.top()] >= deep[x]) addedge(y, st.top()), y = 0;
            }
            if (y) st.push(x), addedge(x, y);
            if (st.top() != p[i]) st.push(p[i]);
        }
        x = st.top(), st.pop();
        while (!st.empty()) addedge(x, st.top()), x = st.top(), st.pop();
        nxt[0] = 1, lst[k + 1] = k;
        for (int i = 1; i <= k; ++i) {
            lst[i] = i - 1, nxt[i] = i + 1, dis[pk[i]] = 0, vir[pk[i]] = i;
        }
        for (int i = 1; i <= k; ++i) {
            for (int e = head[pk[i]]; e; e = next[e]) {
                if (!vir[to[e]]) f[i].emplace(val[e], to[e]);
            }
        }
        int turn = 1, min;
        while (nxt[0] <= k) {
            min = 1e9;
            for (int r = nxt[0]; r <= k; r = nxt[r]) {
                int max = turn * sd[r];
                while (!f[r].empty() && f[r].top().first <= max) {
                    int u = f[r].top().second;
                    if (vir[u] && (f[r].pop(), 1)) continue;
                    dis[u] = f[r].top().first, vir[u] = r, f[r].pop();
                    for (int e = head[u]; e; e = next[e]) {
                        if (!vir[to[e]]) f[r].emplace(dis[u] + val[e], to[e]);
                    }
                }
                if (f[r].empty()) {
                    nxt[lst[r]] = nxt[r], lst[nxt[r]] = lst[r];
                } else {
                    min = std::min(min, (f[r].top().first + sd[r] - 1) / sd[r]);
                }
            }
            turn = min;
        }
        for (int i = 1; i <= m; ++i) std::cout << vir[pm[i]] << " \n"[i == m];
    }
    return 0;
}