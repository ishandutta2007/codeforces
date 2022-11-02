#include <bits/stdc++.h>

const int N = 1000005;

bool v[N], t[N];

int n, S;
int o[N], G[N];

void dfs(int x) {
    if (v[x]) return;
    S += x, t[x] = v[x] = 1;
    int y = x + n;
    if (y > 2 * n) y -= 2 * n;
    v[y] = 1, dfs(G[y]);
}

int main() {
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << "First" << std::endl;
        for (int j = 1; j <= 2; ++j)
            for (int i = 1; i <= n; ++i) std::cout << i << " ";
        std::cout << std::endl;
    } else {
        std::cout << "Second" << std::endl;
        for (int i = 1, p; i <= n * 2; ++i) {
            std::cin >> p;
            if (o[p]) {
                G[i] = o[p], G[o[p]] = i;
            } else {
                o[p] = i;
            }
        }
        for (int i = 1; i <= n * 2; ++i) {
            if (!v[i]) dfs(i);
        }
        for (int i = 1; i <= n * 2; ++i) {
            if (t[i] != (S & 1)) std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}