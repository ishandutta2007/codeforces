#include <bits/stdc++.h>

using int64 = long long;

int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    std::vector<std::vector<int>> To(2 * n);
    for (int i = 0, x, y; i < 2 * n; ++i) {
        std::cin >> x >> y, --x, --y;
        To[x].push_back(y);
        To[y].push_back(x);
    }
    std::vector<bool> Vis(2 * n);
    int64 Ans = 0;
    for (int i = 0; i < n; ++i) {
        if (Vis[i]) continue;
        std::vector<int> a;
        std::function<void(int)> Dfs = [&](int u) -> void {
            a.push_back(u);
            Vis[u] = true;
            for (auto v : To[u]) {
                if (Vis[v]) continue;
                Dfs(v);
            }
        };
        Dfs(i);
        int N = a.size();
        int ml = n, Ml = -1, mr = n, Mr = -1;
        for (int i = 0; i < N; ++i) {
            if (a[i] < n) {
                ml = std::min(ml, a[i]);
                Ml = std::max(Ml, a[i]);
            } else {
                mr = std::min(mr, a[i] - n);
                Mr = std::max(Mr, a[i] - n);
            }
        }
        Ans += 1LL * N / 2 * (ml + 1) * (n - Ml) * (mr + 1) * (n - Mr);
        for (int i = 0; i < N; ++i) {
            int ml = n, Ml = -1, mr = n, Mr = -1, Tl = 1, Tr = -n;
            for (int j = 0; j < N; ++j) {
                int x = a[(i + j) % N];
                if (x < n) {
                    ml = std::min(ml, x);
                    Ml = std::max(Ml, x);
                } else {
                    mr = std::min(mr, x - n);
                    Mr = std::max(Mr, x - n);
                }
                if (j % 2 == 1) {
                    int ex = a[(i - 1 + N) % N];
                    int l1 = ml, r1 = Ml, l2 = mr, r2 = Mr;
                    if (i % 2 == 1) {
                        std::swap(l1, l2);
                        std::swap(r1, r2);
                    } else {
                        ex -= n;
                    }
                    if (ex < l2) {
                        Ans += 1LL * (l1 + 1) * (n - r1) * (l2 - ex) * (n - r2);
                    }
                    if (ex > r2) {
                        Ans += 1LL * (l1 + 1) * (n - r1) * (l2 + 1) * (ex - r2);
                    }
                }
            }
            for (int j = Tl; j <= Tr; ++j) {
                int x = j % n + j;
                if (x >= n) x -= j;
                x = a[x];
                int u = ml, v = mr;
                if (x < n) {
                    a[u] = std::min(a[u], x);
                    a[v] = std::min(a[v], a[u]);
                } else {
                    a[v] = std::min(a[v], x);
                    a[u] = std::min(a[u], a[v]);
                }
            }
        }
    }
    std::cout << Ans << "\n";
    return 0;
}