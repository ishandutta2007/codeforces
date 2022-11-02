#include <bits/stdc++.h>

using int64 = long long;

const int N = 400005;

int64 t, n, m;
int64 d[N], F[N], sz[N];

int64 find(int64 x) {
    if (F[x] == x) return x;
    x = F[x] = find(F[x]);
    return F[x];
}

void uni(int64 a, int64 b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] > sz[b]) std::swap(a, b);
    F[a] = b;
    sz[b] += sz[a];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        for (int64 i = 1; i <= 2 * n; i++) {
            F[i] = i;
            sz[i] = 1;
        }
        for (int64 i = 1; i <= n; i++) std::cin >> d[i];
        for (int64 i = 1; i <= n; i++) {
            int64 b;
            std::cin >> b;
            d[i] -= b;
        }
        int64 f = 0;
        for (int i = 1; i <= n; i++) f += d[i];
        while (m--) {
            int64 a, b;
            std::cin >> a >> b;
            uni(b, a + n), uni(a, b + n);
        }
        if (f % 2) {
            std::cout << "NO\n";
            continue;
        }
        if (sz[find(1)] == 2 * n) {
            std::cout << "YES\n";
            continue;
        }
        int64 k = 0;
        for (int64 i = 1; i <= n; i++) {
            k += find(1) == find(i) ? d[i] : -d[i];
        }
        std::cout << (k ? "NO" : "YES") << std::endl;
    }
    return 0;
}