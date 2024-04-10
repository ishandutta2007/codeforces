#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin (Deb << "[Debug] at Line " << __LINE__)
#define Debug (Delin << " : ")
#define Deline (Delin << std::endl)

const int N = 200005;

int n, m, x, y;
int low[N], up[N], deep[N], fa[N];

std::vector<int> to[N];

inline void push(std::stack<int> &s, int u, int v) {
    if (deep[u] >= deep[v]) {
        while (u != fa[v]) s.push(u), u = fa[u];
    } else {
        std::stack<int> t;
        while (v != fa[u]) t.push(v), v = fa[v];
        while (!t.empty()) s.push(t.top()), t.pop();
    }
}

inline void out(std::stack<int> &s) {
    std::cout << s.size();
    while (!s.empty()) std::cout << ' ' << s.top(), s.pop();
    std::cout << std::endl;
}

inline void dfs(int u, int f) {
    deep[u] = deep[f] + 1, low[u] = up[u] = u, fa[u] = f;
    int Low = u, Up = u, TLow, TUp;
    for (int v : to[u]) {
        if (deep[v]) {
            if (v == f || deep[v] >= deep[u]) continue;
            TUp = v, TLow = u;
        } else {
            dfs(v, u), TUp = up[v], TLow = low[v];
        }
        if (deep[TUp] < deep[up[u]]) {
            Up = up[u], Low = low[u];
            up[u] = TUp, low[u] = TLow;
        } else if (deep[TUp] < deep[Up]) {
            Up = TUp, Low = TLow;
        }
    }
    if (deep[Up] < deep[u]) {
        std::stack<int> S;
        std::cout << "YES" << std::endl;
        push(S, u, Up), out(S);
        push(S, u, Low), push(S, Up, Up), out(S);
        push(S, u, low[u]), push(S, up[u], Up), out(S);
        exit(0);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    while (m--) {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!deep[i]) dfs(i, 0);
    }
    std::cout << "NO" << std::endl;
    return 0;
}