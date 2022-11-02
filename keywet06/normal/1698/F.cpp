#include <bits/stdc++.h>

const int N = 505;

int n;
int a[N], b[N];

void Main() {
    std::vector<std::pair<int, int>> ans;
    auto Push = [&](int l, int r) {
        ans.emplace_back(l, r);
        std::reverse(a + l + 1, a + r);
    };
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) std::cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] ^ b[i]) return void(std::cout << "NO\n");
        if (a[i + 1] == b[i + 1]) continue;
        int f = 0;
        for (int j = i + 2; j <= n; ++j) {
            if (a[j] == b[i] && a[j - 1] == b[i + 1]) {
                Push(i, j), f = 1;
                break;
            }
        }
        if (f) continue;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == b[i] && a[j + 1] == b[i + 1]) {
                for (int u = j; u > i && !f; --u) {
                    for (int v = j + 1; v <= n; ++v) {
                        if (a[u] == a[v]) {
                            Push(u, v), Push(i, u + v - j), f = 1;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    std::cout << "YES\n" << ans.size() << '\n';
    for (auto [x, y] : ans) std::cout << x << ' ' << y << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Main();
    return 0;
}