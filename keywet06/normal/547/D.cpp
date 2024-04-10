#include <bits/stdc++.h>

const int N = 200005;

bool Col[N], Vis[N];

int n;
int Px[N], Py[N];

std::vector<int> Ex[N], Ey[N], To[N];

inline void Insert(int u, int v) {
    To[u].push_back(v);
    To[v].push_back(u);
}

inline void Add(std::vector<int> &V) {
    for (int i = 0, j = 1; j < V.size(); i += 2, j += 2) Insert(V[i], V[j]);
}

inline void Dfs(int u, bool c) {
    Col[u] = c, Vis[u] = true;
    for (int v : To[u]) {
        if (!Vis[v]) Dfs(v, !c);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> Px[i] >> Py[i];
        Ex[Px[i]].push_back(i);
        Ey[Py[i]].push_back(i);
    }
    for (std::vector<int> &Vec : Ex) Add(Vec);
    for (std::vector<int> &Vec : Ey) Add(Vec);
    for (int i = 1; i <= n; ++i) {
        if (!Vis[i]) Dfs(i, false);
    }
    for (int i = 1; i <= n; ++i) std::cout << "br"[Col[i]];
    std::cout << '\n';
    return 0;
}