#include <bits/stdc++.h>

const int N = 500;
const long long INF = 1000000000000000000;

int n, m, k;

long long down[N][N], right[N][N], lcost[N][N], ucost[N][N];

std::vector<std::pair<int, int>> left[N][N], up[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        std::fill(down[i], down[i] + m, INF);
        std::fill(right[i], right[i] + m, INF);
    }
    for (int i = 0; i < k; ++i) {
        int x, y, d, t, e;
        std::cin >> x >> y >> d >> t >> e;
        bool a[4];
        a[0] = x + y >= t && (x + y - t) % 4 == 0;
        a[1] = x + y >= t + 1 && (x + y - t - 1) % 4 == 0;
        a[2] = x + y + d >= t + 2 && (x + y + d - t - 2) % 4 == 0;
        a[3] = x + y + d >= t + 3 && (x + y + d - t - 3) % 4 == 0;
        if (a[0]) {
            lcost[x][y] += e;
            ucost[x][y] += e;
        }
        if (a[1]) {
            lcost[x + d][y - d] += e;
            ucost[x + d][y - d] += e;
        }
        if (a[2]) {
            if (a[1]) {
                left[x + d][y].emplace_back(y - d, e);
            } else {
                lcost[x + d][y] += e;
            }
            if (a[0]) {
                up[x + d][y].emplace_back(x, e);
            } else {
                ucost[x + d][y] += e;
            }
        }
        if (a[3]) {
            if (a[0]) {
                left[x][y + d].emplace_back(y, e);
            } else {
                lcost[x][y + d] += e;
            }
            ucost[x][y + d] += e;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::sort(left[i][j].begin(), left[i][j].end(), std::greater<>());
            std::sort(up[i][j].begin(), up[i][j].end(), std::greater<>());
        }
    }
    down[0][0] = right[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long cost = 0;
            for (int k = i + 1; k < n; ++k) {
                while (!up[k][j].empty() && i > up[k][j].back().first) {
                    ucost[k][j] += up[k][j].back().second;
                    up[k][j].pop_back();
                }
                cost += ucost[k][j];
                down[k][j] = std::min(down[k][j], right[i][j] + cost);
            }
            cost = 0;
            for (int k = j + 1; k < m; ++k) {
                while (!left[i][k].empty() && j > left[i][k].back().first) {
                    lcost[i][k] += left[i][k].back().second;
                    left[i][k].pop_back();
                }
                cost += lcost[i][k];
                right[i][k] = std::min(right[i][k], down[i][j] + cost);
            }
        }
    }
    std::cout << std::min(down[n - 1][m - 1], right[n - 1][m - 1]) << "\n";
    return 0;
}