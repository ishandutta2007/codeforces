#include <bits/stdc++.h>

using ldou = long double;

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y), --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    std::vector<std::vector<ldou>> f(n, std::vector<ldou>(n));
    std::vector<std::vector<ldou>> C(n + 1, std::vector<ldou>(n + 1));
    std::vector<int> Siz(n);
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    std::function<void(int, int)> dfs = [&](int x, int parent) {
        Siz[x] = 0;
        f[x][0] = 1;
        for (auto y : adj[x]) {
            if (y != parent) {
                dfs(y, x);
                std::vector<ldou> Tem(Siz[y] + 1);
                for (int i = 0; i <= Siz[y]; ++i) {
                    for (int j = 1; j <= Siz[y]; ++j) {
                        if (j <= i) {
                            Tem[i] += f[y][std::min(i, j - 1)] / 2;
                        } else {
                            
                            Tem[i] += f[y][std::min(i, j - 1)];
                        }
                    }
                }
                std::vector<ldou> Res(Siz[x] + Siz[y] + 1);
                for (int i = 0; i <= Siz[x]; ++i) {
                    for (int j = 0; j <= Siz[y]; ++j) {
                        Res[i + j] += f[x][i] * Tem[j] * C[i + j][i] * C[Siz[x] + Siz[y] - i - j][Siz[x] - i];
                    }
                }
                for (int i = 0; i <= Siz[x] + Siz[y]; ++i) f[x][i] = Res[i];
                Siz[x] += Siz[y];
            }
        }
        ++Siz[x];
    };
    ldou fact = 1;
    for (int i = 1; i < n; ++i) fact *= i;
    for (int i = 0; i < n; ++i) {
        dfs(i, -1);
        printf("%.9lf\n", (double)(f[i][n - 1] / fact));
    }
    return 0;
}