#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const int C = 61;

int inf = 100000000;
int g1, g2, s1, s2, b1, b2;
int canG[C], canS[C], canB[C], Max[C], Min[C];
int g[C][C];

int64 ans;
int64 opt[C][C][C];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) g[i][j] = inf;
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;
    }
    cin >> g1 >> g2 >> s1 >> s2;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != k && i != j && k != j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for (int i = 1; i <= n; ++i) {
        Max[i] = inf;
        Min[i] = 0;
        for (int j = 1; j <= n; ++j)
            if (i != j) {
                Max[i] = min(Max[i], g[i][j]);
                Min[i] = max(Min[i], g[i][j]);
            }
    }
    b1 = n - g2 - s2;
    b2 = n - g1 - s1;
    for (int G = 1; G <= n; ++G)
        for (int B = 1; B <= n; ++B)
            if (G != B) {
                if (!(Max[G] < Min[B] || (Max[G] == Min[B] && G < B))) continue;
                memset(canG, 0, sizeof(canG));
                memset(canS, 0, sizeof(canS));
                memset(canB, 0, sizeof(canB));
                for (int i = 1; i <= n; ++i) {
                    if (Max[i] < Max[G] || (Max[i] == Max[G] && i <= G))
                        canG[i] = 1;
                    if (Min[i] > Min[B] || (Min[i] == Min[B] && i >= B))
                        canB[i] = 1;
                    for (int j = 1; j <= n; ++j)
                        if (i != j) {
                            int cur = g[i][j];
                            if (cur > Max[G] || (cur == Max[G] && i > G))
                                if (cur < Min[B] || (cur == Min[B] && i < B))
                                    canS[i] = 1;
                        }
                }
                canS[G] = canB[G] = 0;
                canG[B] = canS[B] = 0;

                memset(opt, 0, sizeof(opt));
                opt[0][0][0] = 1;
                for (int i = 0; i < n; ++i)
                    for (int tG = 0; tG <= i; ++tG)
                        for (int tB = 0; tB <= i; ++tB)
                            if (opt[i][tG][tB]) {
                                if (canG[i + 1] && tG < n)
                                    opt[i + 1][tG + 1][tB] += opt[i][tG][tB];
                                if (canS[i + 1])
                                    opt[i + 1][tG][tB] += opt[i][tG][tB];
                                if (canB[i + 1] && tB < n)
                                    opt[i + 1][tG][tB + 1] += opt[i][tG][tB];
                            }
                int64 v = ans;
                for (int tG = g1; tG <= g2; ++tG)
                    for (int tS = s1; tS <= s2; ++tS)
                        if (tG + tS < n) ans += opt[n][tG][n - tG - tS];
            }
    cout << ans << endl;
    return 0;
}