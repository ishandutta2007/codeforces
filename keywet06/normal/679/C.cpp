#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = N * N;

int n, k, S1[N][N], S2[N][N], vis[N][N], m, sz[M], xL, xR, yL, yR, Vis[M], tag;
char g[N][N];

void dfs(int x, int y) {
    vis[x][y] = m;
    ++sz[m];
    if (x > 1 && g[x - 1][y] != 'X' && !vis[x - 1][y]) dfs(x - 1, y);
    if (x < n && g[x + 1][y] != 'X' && !vis[x + 1][y]) dfs(x + 1, y);
    if (y > 1 && g[x][y - 1] != 'X' && !vis[x][y - 1]) dfs(x, y - 1);
    if (y < n && g[x][y + 1] != 'X' && !vis[x][y + 1]) dfs(x, y + 1);
    xL = min(xL, x);
    xR = max(xR, x);
    yL = min(yL, y);
    yR = max(yR, y);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == 'X')
                S2[i][j] = 1;
            else if (!vis[i][j]) {
                ++m;
                xL = xR = i;
                yL = yR = j;
                dfs(i, j);
                int XL = max(1, xR + 1 - k), XR = xL + 1,
                    YL = max(1, yR + 1 - k), YR = yL + 1;
                if (XL < XR && YL < YR)
                    S1[XL][YL] += sz[m], S1[XR][YR] += sz[m],
                        S1[XL][YR] -= sz[m], S1[XR][YL] -= sz[m];
            }
            S2[i][j] += S2[i - 1][j] + S2[i][j - 1] - S2[i - 1][j - 1];
        }
    int Ans = 0;
    for (int i = 1; i + k - 1 <= n; ++i)
        for (int j = 1; j + k - 1 <= n; ++j) {
            S1[i][j] += S1[i - 1][j] + S1[i][j - 1] - S1[i - 1][j - 1];
            int Num = S1[i][j] + S2[i + k - 1][j + k - 1] + S2[i - 1][j - 1] -
                      S2[i - 1][j + k - 1] - S2[i + k - 1][j - 1];
            ++tag;
            for (int g = 0; g < k; ++g) {
                int p = vis[i + g][j - 1];
                if (Vis[p] != tag) Vis[p] = tag, Num += sz[p];
                p = vis[i - 1][j + g];
                if (Vis[p] != tag) Vis[p] = tag, Num += sz[p];
                p = vis[i + k][j + g];
                if (Vis[p] != tag) Vis[p] = tag, Num += sz[p];
                p = vis[i + g][j + k];
                if (Vis[p] != tag) Vis[p] = tag, Num += sz[p];
            }
            Ans = max(Ans, Num);
        }
    cout << Ans << endl;
    return 0;
}