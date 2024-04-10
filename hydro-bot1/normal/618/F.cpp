// Hydro submission #630c9203e873da94ac85d574@1661768195825
#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1000000;

int main() {
    int n;
    static int a[MAXN + 1], b[MAXN + 1];

    std::cin >> n;

    static long long sa[MAXN + 1], sb[MAXN + 1];
    sa[0] = sb[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        sb[i] = sb[i - 1] + b[i];
    }

    static bool vis[MAXN + 1];
    static std::pair<int, int> pos[MAXN + 1];
    memset(vis, false, sizeof(vis));
    int p = 1, q = 0;
    vis[0] = true;
    bool find = false;

    for (; p <= n; p++) {
        while (q < n && sb[q + 1] <= sa[p]) q++;
        if (vis[sa[p] - sb[q]]) {
            find = true;
            break;
        } else {
            vis[sa[p] - sb[q]] = true;
            pos[sa[p] - sb[q]] = std::make_pair(p, q);
        }
    }

    if (find) {
        std::cout << p - pos[sa[p] - sb[q]].first << std::endl;
        for (int i = pos[sa[p] - sb[q]].first + 1; i <= p; i++) printf("%d ", i);
        std::cout << std::endl;
        std::cout << q - pos[sa[p] - sb[q]].second << std::endl;
        for (int i = pos[sa[p] - sb[q]].second + 1; i <= q; i++) printf("%d ", i);
        std::cout << std::endl;
    } else std::cout << "-1" << std::endl;

    return 0;
}