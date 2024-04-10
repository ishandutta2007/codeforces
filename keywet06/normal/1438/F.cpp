#include <bits/stdc++.h>

int query(int u, int v, int w) {
    std::cout << "? " << u << " " << v << " " << w << std::endl;
    int res;
    std::cin >> res;
    return res;
}

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int h;
    std::cin >> h;

    int n = (1 << h) - 1;
    std::vector<int> cnt(n + 1);
    for (int i = 1; i <= 420; ++i) {
        int u = rnd() % n + 1, v = rnd() % n + 1, w = rnd() % n + 1;
        while (u == v) v = rnd() % n + 1;
        while (u == w || v == w) w = rnd() % n + 1;
        ++cnt[query(u, v, w)];
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 1);
    std::sort(p.begin(), p.end(),
              [&](int u, int v) { return cnt[u] > cnt[v]; });

    int u = p[0], v = p[1];
    for (int i = 1; i <= n; ++i) {
        if (u != i && v != i && query(i, u, v) == i) {
            std::cout << "! " << i << std::endl;
            return 0;
        }
    }

    return 0;
}