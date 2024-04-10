#include <bits/stdc++.h>

using int64 = long long;

const int C = 20;
const int N = 500005;

int n, r;
int A[N];
int P[N][C];

int64 s;

std::vector<int> G[N];

void dfs(int u, int p) {
    P[u][0] = p;
    long long x = A[p] + A[u];
    for (int j = 1; j <= 19; ++j)
        P[u][j] = P[P[u][j - 1]][j - 1], x = std::min(x, (long long)(j + 1) * A[P[u][j]] + A[u]);
    if (u != p) s += x;
    for (auto &v : G[u]) {
        if (v != p) dfs(v, u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> A[i];
        if (!r || A[i] < A[r]) r = i;
    }
    for (int i = 1, u, v; i < n; ++i) {
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(r, r);
    std::cout << s << std::endl;
    return 0;
}