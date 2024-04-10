#include <bits/stdc++.h>

const int N = 16;
const int M = 1 << N;

int T, n, x, y;
int p[M], q[M];

std::set<int> s;
std::set<int> ed[M];

inline void link(int x, int y) { p[x] = y, q[y] = x; }

inline int popcount(int x) {
    int ret = 1;
    while (x = x & (x - 1)) ++ret;
    return ret;
}

inline std::set<int> cap(const std::set<int> a, const std::set<int> b) {
    std::set<int> ret;
    for (int x : a) {
        if (b.count(x)) ret.insert(x);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < 1 << n; ++i) p[i] = q[i] = 0, ed[i].clear();
        for (int i = 0; i < (1 << n - 1) * n; ++i) {
            std::cin >> x >> y;
            ed[x].insert(y);
            ed[y].insert(x);
        }
        y = 0;
        for (int x : ed[0]) link(1 << (y++), x);
        for (int i = 1; i < 1 << n; ++i) {
            if (popcount(i) == 1) continue;
            x = 0;
            for (int j = 0; j < n; ++j) {
                if (!((i >> j) & 1)) continue;
                s = x ? cap(s, ed[p[i ^ (1 << j)]])
                      : (x = 1, ed[p[i ^ (1 << j)]]);
            }
            for (int x : s) {
                if (x && !q[x]) link(i, x);
            }
        }
        for (int i = 0; i < 1 << n; ++i) std::cout << p[i] << ' ';
        std::cout << std::endl;
        if (n != 1 && n != 2 && n != 4 && n != 8 && n != 16) {
            std::cout << -1 << std::endl;
            continue;
        }
        for (int i = 0; i < 1 << n; ++i) {
            x = 0;
            for (int j = 0; j < n; ++j) x ^= (q[i] >> j) & 1 ? j : 0;
            std::cout << x << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}