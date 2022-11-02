#include <bits/stdc++.h>

#define templ template <typename Type1, typename Type2>
templ inline Type1 &Mid(Type1 &x, Type2 y) { return x < y ? x : x = y; }
templ inline Type1 &Mad(Type1 &x, Type2 y) { return x > y ? x : x = y; }
#undef templ

using int64 = long long;

const int N = 505;
const int M = N * N;

int T, n, m;
int Eu[M], Ev[M], Ew[M];
int d[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        memset(d, 60, sizeof(d));
        for (int i = 1; i <= n; ++i) d[i][i] = 0;
        for (int i = 1; i <= m; ++i) {
            std::cin >> Eu[i] >> Ev[i] >> Ew[i];
            d[Eu[i]][Ev[i]] = d[Ev[i]][Eu[i]] = 1;
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) Mid(d[i][j], d[i][k] + d[k][j]);
            }
        }
        int64 Ans = INT64_MAX;
        for (int i = 1; i <= m; ++i) {
            Mid(Ans, int64(Ew[i]) * (d[1][Eu[i]] + d[n][Ev[i]] + 1));
            Mid(Ans, int64(Ew[i]) * (d[1][Ev[i]] + d[n][Eu[i]] + 1));
            for (int u = 1; u <= n; ++u) {
                Mid(Ans, int64(Ew[i]) * (std::min(d[Eu[i]][u], d[Ev[i]][u]) + d[u][1] + d[u][n] + 2));
            }
        }
        std::cout << Ans << '\n';
    }
    return 0;
}