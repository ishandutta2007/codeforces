#include <bits/stdc++.h>

const int K = 105;
const int N = 35005;
const int M = N << 2;

int n, k, x;
int dec[K];
int last[N];
int mi[K][M], pl[K][M];

inline void build(int u, int l, int r) {
    mi[1][u] = 0;
    if (l < r) build(u << 1, l, l + r >> 1);
}

inline void plus(int u, int l, int r, int x, int y, int z) {
    if (l >= x && r <= y) {
        for (int i = 1; i <= k; ++i) mi[i][u] += z, pl[i][u] += z;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) plus(u << 1, l, mid, x, y, z);
    if (y > mid) plus(u << 1 | 1, mid + 1, r, x, y, z);
    for (int i = 1; i <= k; ++i) {
        mi[i][u] = std::min(mi[i][u << 1], mi[i][u << 1 | 1]) + pl[i][u];
    }
}

inline void update(int u, int l, int r, int x) {
    if (l == r) {
        for (int i = 2; i <= k; ++i) mi[i][u] = mi[i - 1][1] - dec[i - 1];
        return;
    }
    int mid = l + r >> 1;
    for (int i = 1; i < k; ++i) dec[i] += pl[i][u];
    x <= mid ? update(u << 1, l, mid, x) : update(u << 1 | 1, mid + 1, r, x);
    for (int i = 1; i <= k; ++i) {
        mi[i][u] = std::min(mi[i][u << 1], mi[i][u << 1 | 1]) + pl[i][u];
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    memset(mi, 63, sizeof(mi));
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        for (int i = 1; i <= k; ++i) dec[i] = 0;
        if (i != n) update(1, 1, n, i);
        std::cin >> x;
        if (last[x]) plus(1, 1, n, 1, last[x], i - last[x]);
        last[x] = i;
    }
    std::cout << mi[k][1] << std::endl;
    return 0;
}