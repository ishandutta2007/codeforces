#include <bits/stdc++.h>

const int N = 101000;

int n, m, k, T, sz[N], t1[N], t2[N], tim, w[N], nrt[N];

std::vector<int> r[N];

void Dfs(int x) {
    t1[x] = ++tim, sz[x] = 1;
    for (int y : r[x]) Dfs(y), sz[x] += sz[y];
    t2[x] = ++tim;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m >> k >> T;
    int x, y;
    for (; k--; w[y] = x) {
        std::cin >> x >> y;
        if (w[y]) r[w[y]].push_back(x), nrt[x] = 1;
    }
    for (int i = 1; i <= n; ++i){
        if (!nrt[i]) Dfs(i);}
    for (; T--;) {
        std::cin >> x >> y;
        std::cout << (w[y] && t1[x] < t1[w[y]] && t2[x] > t2[w[y]] ? sz[x] : 0) << '\n';
    }
    return 0;
}