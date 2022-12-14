#include <bits/stdc++.h>

using namespace std;

int n, m;
char G[55][55];
int P[55 * 55];

int find(int x) {
    if (P[x] != x) return P[x] = find(P[x]);
    return x;
}

bool solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", G[i] + 1);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (G[i][j] == 'B') continue;
        for (int k = 0; k < 4; k++) {
            int x = i + "1012"[k] - '1';
            int y = j + "0121"[k] - '1';
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (G[x][y] == 'B') {
                if (G[i][j] == 'G') return 0;
                G[i][j] = '#';
            }
        }
    }
    for (int i = 0; i <= (n + 1) * (m + 1); i++) P[i] = i;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (G[i][j] == '#') continue;
        if (i < n && G[i + 1][j] != '#') P[find((i + 1) * m + j)] = find(i * m + j);
        if (j < m && G[i][j + 1] != '#') P[find((i) * m + j + 1)] = find(i * m + j);
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (G[i][j] == 'G' && find(i * m + j) != find(n * m + m)) return 0;
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) printf(solve() ? "Yes\n" : "No\n");
}