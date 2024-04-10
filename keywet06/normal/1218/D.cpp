#include <bits/stdc++.h>

const int P = 1000000007;
const int I = 742744451;
const int C = 131072;

int n, m, tot, dfn;

std::vector<int> in, parent, weight, cnt(C), ex(C);

std::vector<std::vector<std::pair<int, int>>> e;

void dft(std::vector<int> &a) {
    for (int i = 1; i < C; i *= 2) {
        for (int j = 0; j < C; j += 2 * i) {
            for (int k = 0; k < i; ++k) {
                int u = a[j + k];
                int v = a[i + j + k];
                a[j + k] = (u + v) % P;
                a[i + j + k] = (u - v + P) % P;
            }
        }
    }
}
void idft(std::vector<int> &a) {
    dft(a);
    for (int i = 0; i < C; ++i) a[i] = 1LL * a[i] * I % P;
}
auto operator*(std::vector<int> lhs, std::vector<int> rhs) {
    dft(lhs);
    dft(rhs);
    for (int i = 0; i < int(lhs.size()); ++i)
        lhs[i] = 1LL * lhs[i] * rhs[i] % P;
    idft(lhs);
    return lhs;
}
void dfs(int u) {
    in[u] = dfn++;
    for (auto [v, w] : e[u]) {
        if (v == parent[u]) continue;
        if (in[v] == -1) {
            parent[v] = u;
            weight[v] = w;
            dfs(v);
        } else if (in[v] < in[u]) {
            std::vector<int> now(C);
            for (int i = u; i != v; i = parent[i]) ++now[weight[i]];
            ++now[w];
            cnt = cnt * now;
            ex = ex * now;
            for (int i = 0; i < C; ++i) ex[i] = std::min(ex[i], 1);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    e.resize(n);
    parent.resize(n);
    weight.resize(n);
    in.assign(n, -1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
        tot ^= w;
    }
    cnt[0] = ex[0] = 1;
    parent[0] = -1;
    dfs(0);
    for (int i = 0;; ++i) {
        if (ex[i ^ tot] == 1) {
            std::cout << i << " " << cnt[i ^ tot] << "\n";
            return 0;
        }
    }
    return 0;
}