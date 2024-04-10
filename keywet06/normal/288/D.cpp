#include <bits/stdc++.h>

using uint64 = unsigned long long;

const int N = 100005;

int n;
int sz[N];

uint64 res;

std::vector<int> e[N];

void dfs(int x, int fat) {
    sz[x] = 1;
    uint64 p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    for (int y : e[x]) {
        if (y == fat) continue;
        dfs(y, x), sz[x] += sz[y];
        uint64 t = sz[y], w = t;
        p1 += w, w *= t, p2 += w, w *= t, p3 += w, w *= t, p4 += w;
    }
    int t = n - sz[x];
    uint64 w = t;
    p1 += w, w *= t, p2 += w, w *= t, p3 += w, w *= t, p4 += w;
    uint64 AB = (p1 * p1 - p2) / 2, A2B = p1 * p2 - p3;
    uint64 ABC = (p1 * AB - A2B) / 3, A3B = p1 * p3 - p4;
    uint64 A2BC = p2 * AB - A3B, ABCD = (p1 * ABC - A2BC) / 4;
    res -= ABC, res -= ABCD;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (n < 4) return std::cout << 0 << '\n', 0;
    res = n * (n - 1LL) / 2 * (n - 2) / 3 * (n - 3) / 4, dfs(1, 1);
    std::cout << (res << 1) << '\n';
    return 0;
}