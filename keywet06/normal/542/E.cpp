#include <bits/stdc++.h>

bool isok = true;

int n, m;
int Col[1000];
int Dist[1024][1024];

std::vector<int> nr, Pac[1000];

void Dfs(int node, int c) {
    if (Col[node] != -1 && Col[node] != c) isok = false;
    if (Col[node] != -1) return;
    nr.push_back(node), Col[node] = c;
    for (int i = 0; i < Pac[node].size(); ++i) Dfs(Pac[node][i], 1 - c);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) Dist[i][j] = 1000000000;
    }
    for (int i = 0; i < n; ++i) Dist[i][i] = 0;
    for (int i = 0, za, zb; i < m; ++i) {
        std::cin >> za >> zb, --za, --zb;
        Pac[za].push_back(zb);
        Pac[zb].push_back(za);
        Dist[za][zb] = Dist[zb][za] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) Dist[j][k] = std::min(Dist[j][k], Dist[j][i] + Dist[i][k]);
        }
    }
    std::fill(Col, Col + n, -1);
    int Ans = 0;
    for (int i = 0; i < n; ++i) {
        if (Col[i] == -1) {
            nr.clear(), Dfs(i, 0);
            int Max = 0;
            for (int j = 0; j < nr.size(); ++j) {
                for (int k = 0; k < n; ++k) {
                    if (Dist[nr[j]][k] != 1000000000) Max = std::max(Max, Dist[nr[j]][k]);
                }
            }
            Ans += Max;
        }
    }
    std::cout << (isok ? Ans : -1) << std::endl;
    return 0;
}