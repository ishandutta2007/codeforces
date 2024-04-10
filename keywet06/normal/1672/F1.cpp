#include <bits/stdc++.h>

const int N = 200005;

int T, n;
int a[N], b[N], p[N];

std::vector<int> Dr[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], p[i] = i, Dr[a[i]].push_back(i);
        std::sort(p + 1, p + n + 1, [](int x, int y) { return Dr[x].size() > Dr[y].size(); });
        for (int i = 1; i <= Dr[p[1]].size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                if (Dr[p[j + 1]].size() >= i) {
                    b[Dr[p[j]][i - 1]] = p[j + 1];
                } else {
                    b[Dr[p[j]][i - 1]] = p[1];
                    break;
                }
            }
        }
        for (int i = 1; i <= n; ++i) std::cout << b[i] << " \n"[i == n];
        for (int i = 1; i <= n; ++i) Dr[i] = std::move(std::vector<int>());
    }
    return 0;
}