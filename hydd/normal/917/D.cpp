//
// Created by hydd on 2022/10/19.
//
#include<bits/stdc++.h>

using namespace std;
const int Mod = 1e9 + 7;
using ll = long long;

int n, k, sz[110];
ll C[110][110], pw[110], f[110][110][2], g[110][2], h[110];
vector<int> vec[110];

void dfs(int u, int fa) {
    sz[u] = 1;
    f[u][1][0] = f[u][1][1] = 1;
    for (int v: vec[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int i = 1; i <= sz[u]; i++)
            for (int j = 1; j <= sz[v]; j++) {
                g[i + j][0] = (g[i + j][0] + f[u][i][0] * f[v][j][1]) % Mod;
                g[i + j][1] = (g[i + j][1] + f[u][i][1] * f[v][j][1]) % Mod;
                // or merge...
                g[i + j - 1][0] = (g[i + j - 1][0] + f[u][i][0] * f[v][j][0]) % Mod;
                g[i + j - 1][1] = (g[i + j - 1][1] + f[u][i][0] * f[v][j][1] + f[u][i][1] * f[v][j][0]) % Mod;
            }
        sz[u] += sz[v];
        for (int i = 1; i <= sz[u]; i++)
            for (int k = 0; k <= 1; k++) {
                f[u][i][k] = g[i][k];
                g[i][k] = 0;
            }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; ++i)
        pw[i] = pw[i - 1] * n % Mod;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 0; i <= n - 2; i++) h[i] = pw[n - i - 2] * f[1][n - i][1] % Mod;
    h[n - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j <= n - 1; j++)
            h[i] = (h[i] + (Mod - h[j]) * C[j][i]) % Mod;
    for (int i = 0; i <= n - 1; i++) cout << h[i] << ' ';
    return 0;
}