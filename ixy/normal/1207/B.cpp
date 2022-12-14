#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 55;

int n, m, a[N][N];

std::vector<std::pair<int, int>> ans;

bool check() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                ans.push_back({i, j});
            }
        }
    }
    for (auto i : ans) {
        int x = i.first, y = i.second;
        a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) { return false; }
        }
    } return true;
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { a[i][j] = read(); }
    }
    if (check()) {
        printf("%d\n", ans.size());
        for (auto i : ans) { printf("%d %d\n", i.first + 1, i.second + 1); }
    } else {
        printf("-1\n");
    }
    return 0;
}