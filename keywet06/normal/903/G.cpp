#include <bits/stdc++.h>

using int64 = long long;

const int N = 2e5 + 10;

int64 x[N], y[N], tmp[N];
int64 Tree[N << 2], lazy[N << 2];

std::pair<int, std::pair<int, int> > e[N];

void PushUp(int pos) { Tree[pos] = std::min(Tree[pos << 1], Tree[pos << 1 | 1]) + lazy[pos]; }

void Update(int l, int r, int pos, int l1, int r1, int64 v) {
    if (l >= l1 && r <= r1) return Tree[pos] += v, lazy[pos] += v, void(0);
    int mid = (l + r) >> 1;
    if (l1 <= mid) Update(l, mid, pos << 1, l1, r1, v);
    if (r1 >= mid + 1) Update(mid + 1, r, pos << 1 | 1, l1, r1, v);
    PushUp(pos);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    for (int i = 2; i <= n; ++i) std::cin >> x[i - 1] >> y[i];
    for (int i = 0; i < m; ++i) std::cin >> e[i].first >> e[i].second.first >> e[i].second.second;
    for (int i = 2; i <= n; ++i) Update(1, n, 1, i, i, y[i]);
    std::sort(e, e + m);
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        for (; j < m && e[j].first <= i; ++j) Update(1, n, 1, 1, e[j].second.first, e[j].second.second);
        tmp[i] = x[i], x[i] += Tree[1];
    }
    memset(Tree, 0, sizeof(Tree));
    memset(lazy, 0, sizeof(lazy));
    for (int i = 1; i <= n; ++i) Update(1, n, 1, i, i, x[i]);
    std::cout << Tree[1] << '\n';
    for (int i = 0, u, w; i < q; ++i) {
        std::cin >> u >> w;
        Update(1, n, 1, u, u, w - tmp[u]), tmp[u] = w;
        std::cout << Tree[1] << '\n';
    }
    return 0;
}