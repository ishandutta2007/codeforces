#include <bits/stdc++.h>

using int64 = long long;

std::mt19937 rd(std::chrono::system_clock::now().time_since_epoch().count());

inline int random(int l, int r) { return rd() % (r - l + 1) + l; }

const int D = 10;
const int N = 100005;

int n, m, x, t;

int64 k, y;
int64 a[N], b[N], c[N];
int64 *f, *g;

inline void step() {
    for (int i = 2; i < m; ++i) g[i] = (f[i - 1] + 1 >> 1) + (f[i + 1] >> 1);
    g[0] = (f[m] + 1 >> 1) + (f[1] >> 1);
    g[1] = f[0] + (f[2] >> 1), g[m] = f[m - 1] + 1 >> 1;
    std::swap(f, g);
}

inline int fitl(int x) { return x < 0 ? x + n : x; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k, f = a, g = b, m = n - 1;
    for (int i = 0; i < n; ++i) f[i] = k;
    while (1) {
        std::cout << "? " << (x = random(1, n)) << std::endl, --x;
        std::cin >> y;
        if (y != k) break;
        step();
    }
    for (int i = 0; i < n; ++i) t += c[i] = f[fitl(x - i)] == y;
    step();
    while (t > 1) {
        x = (x + (y > k ? -1 : 1) * random(0, D) + n * D) % n;
        std::cout << "? " << x + 1 << std::endl;
        std::cin >> y, t = 0;
        for (int i = 0; i < n; ++i) t += c[i] &= f[fitl(x - i)] == y;
        step();
    }
    for (int i = 0; i < n; ++i) {
        if (c[i]) std::cout << "! " << i + 1 << std::endl;
    }
    return 0;
}