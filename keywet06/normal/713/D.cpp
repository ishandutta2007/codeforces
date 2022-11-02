#include <bits/stdc++.h>

const int N = 1001;

struct query {
    int x1, y1, x2, y2, pos;
} q[N * N];

char S[N][N];

int n, m, i, j, T;
int s[N][N], can[N][N], ot[N * N];

void solve(int l, int r, int L, int R) {
    if (L == R) {
        for (int i = l; i <= r; ++i) ot[q[i].pos] = L;
        return;
    }
    int i, j, mid = (L + R >> 1) + 1, k = n - mid + 1, k_ = m - mid + 1;
    for (i = 0; i < k; ++i) {
        for (j = 0; j < k_; ++j) {
            can[i + 1][j + 1] = can[i][j + 1] + can[i + 1][j] - can[i][j];
            if (!(s[i + mid][j + mid] + s[i][j] - s[i][j + mid] - s[i + mid][j])) ++can[i + 1][j + 1];
        }
    }
    int ll = l, rr = r;
    mid -= 1;
    while (ll <= rr) {
        if (q[ll].x2 >= q[ll].x1 + mid && q[ll].y2 >= q[ll].y1 + mid &&
            can[q[ll].x2 - mid][q[ll].y2 - mid] + can[q[ll].x1 - 1][q[ll].y1 - 1] - can[q[ll].x2 - mid][q[ll].y1 - 1] -
                can[q[ll].x1 - 1][q[ll].y2 - mid]) {
            std::swap(q[ll], q[rr]), --rr;
        } else {
            ++ll;
        }
    }
    solve(l, ll - 1, L, mid);
    solve(ll, r, mid + 1, R);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) std::cin >> s[i][j], s[i][j] ^= 1;
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
    for (std::cin >> T, i = 1; i <= T; ++i) std::cin >> q[i].x1 >> q[i].y1 >> q[i].x2 >> q[i].y2, q[i].pos = i;
    solve(1, T, 0, 1000);
    for (i = 1; i <= T; ++i) std::cout << ot[i] << "\n";
    return 0;
}