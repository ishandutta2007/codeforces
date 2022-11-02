#include <bits/stdc++.h>

const int N = 410;

int n, m, i, k, Ans, r, c, u, j;
int a[N][N], Flag, Vis[N * N], Num[N * N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) std::cin >> a[i][j];
    }
    Flag = Ans = 0;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
            ++Flag, k = m;
            for (r = i; r < n; ++r) {
                if ((k - j) * (n - i) <= Ans) break;
                for (c = j; c < m && c < k; ++c) {
                    u = a[r][c];
                    if (Vis[u] != Flag) {
                        Vis[u] = Flag;
                        Num[u] = c;
                    } else {
                        if (Num[u] <= c) {
                            if (k > c) k = c;
                            break;
                        } else {
                            if (k > Num[u]) k = Num[u];
                            Num[u] = c;
                        }
                    }
                }
                Ans = std::max(Ans, (c - j) * (r - i + 1));
                if (c == j) break;
            }
        }
    std::cout << Ans << std::endl;
    return 0;
}