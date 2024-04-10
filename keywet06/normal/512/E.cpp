#include <bits/stdc++.h>
using pai = std::pair<int, int>;
using vpa = std::vector<pai>;
const int N = 1005;
int n;
int e[N][N];
inline pai flip(int a, int b, bool inv) {
    int x = -1, y;
    for (int i = 0; i < n; i++) {
        if (e[a][i] && e[b][i]) {
            if (x == -1) {
                x = i;
            } else {
                y = i;
                break;
            }
        }
    }
    e[a][b] = e[b][a] = false;
    e[x][y] = e[y][x] = true;
    return inv ? std::make_pair(x, y) : std::make_pair(a, b);
}
inline vpa solve(bool inv) {
    memset(e, 0, sizeof(e));
    for (int i = 0; i < n; i++) e[i][(i + 1) % n] = e[(i + 1) % n][i] = true;
    for (int i = 0, a, b; i < n - 3; i++) {
        std::cin >> a >> b;
        a--, b--;
        e[a][b] = e[b][a] = 1;
    }
    vpa res;
    for (int i = 1; i < n;) {
        if (e[0][i]) {
            i++;
            continue;
        }
        int j = i + 1;
        while (!e[0][j]) ++j;
        res.push_back(flip(i - 1, j, inv));
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    vpa a = solve(0), b = solve(1);
    std::cout << a.size() + b.size() << std::endl;
    for (int i = 0; i < (int)a.size(); i++) {
        std::cout << a[i].first + 1 << " " << a[i].second + 1 << std::endl;
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        std::cout << b[i].first + 1 << " " << b[i].second + 1 << std::endl;
    }
    return 0;
}