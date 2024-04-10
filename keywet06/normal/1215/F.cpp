#include <bits/stdc++.h>

const int N = 400000;
const int V = N << 1;
const int M = V << 1;

int tot, cnt;
int L[N], R[N], s[N];
int Low[M], Dfn[M], Bel[M];

std::vector<int> stk;
std::vector<int> g[M];

void tarjan(int u) {
    stk.push_back(u);
    Dfn[u] = tot++;
    Low[u] = Dfn[u];
    for (int v : g[u]) {
        if (Dfn[v] == -1) {
            tarjan(v);
            Low[u] = std::min(Low[u], Low[v]);
        } else if (Bel[v] == -1) {
            Low[u] = std::min(Low[u], Dfn[v]);
        }
    }
    if (Low[u] == Dfn[u]) {
        Bel[u] = cnt;
        while (stk.back() != u) Bel[stk.back()] = cnt, stk.pop_back();
        stk.pop_back(), ++cnt;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    memset(Dfn, -1, sizeof(Dfn));
    memset(Low, -1, sizeof(Low));
    memset(Bel, -1, sizeof(Bel));
    int n, p, r, m;
    std::cin >> n >> p >> r >> m;
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        g[u].push_back(v + V);
        g[v].push_back(u + V);
    }
    for (int i = 0; i < p; ++i) std::cin >> L[i] >> R[i], s[i] = i;
    std::sort(s, s + p, [&](int a, int b) { return L[a] < L[b]; });
    for (int i = 0; i < p; ++i) {
        g[i + N].push_back(s[i]);
        g[s[i] + V].push_back(i + N + V);
        if (i < p - 1) {
            g[i + N].push_back(i + 1 + N);
            g[i + 1 + N + V].push_back(i + N + V);
        }
    }
    for (int i = 0; i < p; ++i) s[i] = L[s[i]];
    for (int i = 0; i < p; ++i) {
        int x = std::upper_bound(s, s + p, R[i]) - s;
        if (x != p) {
            g[i + V].push_back(x + N);
            g[x + N + V].push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        g[u + V].push_back(v);
        g[v + V].push_back(u);
    }
    for (int i = 0; i < M; ++i) {
        if (Dfn[i] == -1) tarjan(i);
    }
    for (int i = 0; i < p; ++i) {
        if (Bel[i] == Bel[i + V]) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    int f = 0, k = 0;
    for (int i = 0; i < p; ++i) {
        if (Bel[i] > Bel[i + V]) f = std::max(f, L[i]), ++k;
    }
    std::cout << k << ' ' << f << std::endl;
    for (int i = 0; i < p; ++i) {
        if (Bel[i] > Bel[i + V]) std::cout << i + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}