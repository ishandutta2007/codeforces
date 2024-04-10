#include <bits/stdc++.h>

using int64 = long long;

struct Mat {
    double a[105][105];
    friend Mat operator*(Mat x, Mat y) {
        Mat z;
        for (int64 i = 0; i <= 104; ++i) {
            for (int64 j = 0; j <= 104; ++j) z.a[i][j] = 0;
        }
        for (int64 i = 0; i <= 104; ++i) {
            for (int64 j = 0; j <= 104; ++j) {
                for (int64 k = 0; k <= 104; ++k) z.a[i][k] += x.a[i][j] * y.a[j][k];
            }
        }
        return z;
    }
} a;

inline Mat Pow(Mat x, int64 y) {
    Mat rtn;
    for (int64 i = 0; i <= 104; ++i)
        for (int64 j = 0; j <= 104; ++j) rtn.a[i][j] = (i == j);
    while (y) {
        if (y & 1) rtn = rtn * x;
        x = x * x, y >>= 1;
    }
    return rtn;
}

double e[505][505], deg[505], P[505];

int64 b[505], id[505];

std::vector<int64> V;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64 n, m, k;
    std::cin >> n >> m >> k;
    for (int64 i = 1; i <= n; ++i) std::cin >> b[i];
    for (int64 i = 1; i <= m; ++i) {
        int64 u, v;
        std::cin >> u >> v;
        if (u == 1) V.push_back(v);
        e[u][v] += 1, e[v][u] += 1, deg[u] += 1, deg[v] += 1;
    }
    for (int64 i = 1; i <= n; ++i)
        for (int64 j = 1; j <= n; ++j) e[i][j] /= deg[i];
    int64 cnt = 0;
    for (int64 i = n; i >= 1; i--) {
        if (!b[i]) {
            e[i][i] = 0;
            double s = 0;
            for (int64 j = 1; j <= n; ++j) s += e[i][j];
            for (int64 j = 1; j <= n; ++j) e[i][j] /= s;
            if (i == 1) {
                for (int64 j = 1; j <= n; ++j) P[j] = e[i][j];
            }
            for (int64 j = 1; j <= n; ++j)
                for (int64 k = 1; k <= n; ++k)
                    if (j != i && k != i) e[j][k] += e[j][i] * e[i][k];
            for (int64 j = 1; j <= n; ++j) e[i][j] = e[j][i] = 0;
        } else
            id[i] = ++cnt;
    }
    for (int64 i = 1; i <= n; ++i) {
        for (int64 j = 1; j <= n; ++j) {
            if (b[i] && b[j]) a.a[id[i]][id[j]] = e[i][j];
        }
    }
    a = Pow(a, k - 2);
    double Ans = 0;
    for (int64 i = 1; i <= n; ++i) Ans += P[i] * a.a[id[i]][id[n]];
    std::cout << std::fixed << std::setprecision(10) << Ans << std::endl;
    return 0;
}