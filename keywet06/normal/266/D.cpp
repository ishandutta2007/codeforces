#include <bits/stdc++.h>

using pair = std::pair<int, int>;

const int N = 305;
const int M = 50005;

int n, m;
int x[M], y[M], len[M];
int d[N][N];

pair a[N], b[N];

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve() {
    int ans = 0x7fffffff;
    Floyd();
    for (int i = 0; i < m; ++i) {
        int u = x[i], v = y[i];
        for (int j = 1; j <= n; ++j) a[j - 1] = pair(d[j][u], d[j][v]);
        sort(a, a + n);
        int kk = 0;
        for (int j = 0; j < n; ++j) {
            while (kk && b[kk - 1].second <= a[j].second) kk--;
            b[kk++] = a[j];
        }
        if (kk == 1) {
            ans = std::min(ans, std::min(b[0].first, b[0].second) << 1);
        } else {
            for (int j = 1; j < kk; ++j) {
                ans = std::min(ans, len[i] + b[j - 1].first + b[j].second);
            }
        }
    }
    std::cout << ans / 2;
    if (ans % 2) std::cout << ".5";
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) d[i][j] = 0xfffffff;
        d[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> x[i] >> y[i] >> len[i];
        d[x[i]][y[i]] = d[y[i]][x[i]] = len[i];
    }
    solve();
    return 0;
}