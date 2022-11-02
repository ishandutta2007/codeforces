#include <bits/stdc++.h>

const int N = 4005;
const int K = 805;

int n, k;
int f[N][N], g[N][N], h[K][N];

int Pre(int l, int r, int x, int y) { return f[--l][--x] + f[r][y] - f[l][y] - f[r][x]; }

void Solve(int k, int l, int r, int pl, int pr) {
    if (l > r) return;
    int mid = l + r >> 1, p = 0;
    for (int i = pl; i <= pr; ++i) {
        if (h[k - 1][i - 1] + g[i][mid] < h[k][mid]) p = i, h[k][mid] = h[k - 1][i - 1] + g[i][mid];
    }
    Solve(k, l, mid - 1, pl, p), Solve(k, mid + 1, r, p, pr);
}

class fastistream {
   public:
    fastistream &operator>>(int &x) {
        static int c;
        c = getchar();
        while (c < '0' || c > '9') c = getchar();
        x = c - '0', c = getchar();
        while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
        return *this;
    }
} fin;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    fin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) fin >> f[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) f[i][j] += f[i - 1][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) f[i][j] += f[i][j - 1];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) g[i][j] = Pre(i, j, i, j) / 2;
    }
    memset(h, 63, sizeof(h));
    h[0][0] = 0;
    for (int i = 1; i <= k; ++i) Solve(i, 1, n, 1, n);
    std::cout << h[k][n] << std::endl;
    return 0;
}