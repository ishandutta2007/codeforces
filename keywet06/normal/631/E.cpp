#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

int n, t, w;
int c[N], d[N];

int64 ic;
int64 a[N], b[N];

int testa(int x, int y, int z) {
    return (b[y] - b[z]) * (x - y) < (b[x] - b[y]) * (y - z);
}
int testb(int x, int y, int z) {
    return b[y] - b[x] < (y - x) * z;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], b[i] = b[i - 1] + a[i];
    t = 1;
    for (int i = 1; i <= n; ++i) {
        while (t > 1 && testa(c[t - 1], c[t], i)) --t;
        c[++t] = d[i] = i;
    }
    std::sort(d + 1, d + n + 1, [](int x, int y) { return a[x] < a[y]; });
    w = 1;
    for (int i = 1; i <= n; ++i) {
        while (w < t && testb(c[w], c[w + 1], a[d[i]])) ++w;
        ic = std::max(ic, b[d[i]] - b[c[w]] - (d[i] - c[w]) * a[d[i]]);
    }
    for (int i = 1; i <= n; ++i) ic += i * a[i];
    std::cout << ic << std::endl;
    return 0;
}