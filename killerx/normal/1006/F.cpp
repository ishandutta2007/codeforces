#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
using u64 = unsigned long long;

int n, m;
u64 K;
u64 a[20][20];
std::map <u64, int> map0[20][20], map1[20][20];

void dfs(int x, int y, int steps, std::map <u64, int> map[20][20], int dx0, int dy0, int dx1, int dy1, u64 val) {
    if (steps == 0) {
        map[x][y][val] += 1;
        return ;
    }
    if (x + dx0 >= 0 && x + dx0 < n && y + dy0 >= 0 && y + dy0 < m) {
        dfs(x + dx0, y + dy0, steps - 1, map, dx0, dy0, dx1, dy1, val ^ a[x + dx0][y + dy0]);
    }
    if (x + dx1 >= 0 && x + dx1 < n && y + dy1 >= 0 && y + dy1 < m) {
        dfs(x + dx1, y + dy1, steps - 1, map, dx0, dy0, dx1, dy1, val ^ a[x + dx1][y + dy1]);
    }
}

int main() {
    scanf("%d %d %llu", &n, &m, &K);
    rep(i, n) rep(j, m) scanf("%llu", &a[i][j]);
    int steps = n - 1 + m - 1;
    int s0 = steps / 2;
    int s1 = steps - s0;
    dfs(0, 0, s0, map0, 0, +1, +1, 0, a[0][0]);
    dfs(n - 1, m - 1, s1, map1, 0, -1, -1, 0, a[n - 1][m - 1]);
    i64 ans = 0;
    rep(x, n) rep(y, m) {
        for (auto pr : map0[x][y]) {
            u64 S = pr.first, T = K ^ S ^ a[x][y];
            ans += 1LL * map0[x][y][S] * map1[x][y][T];
        }
    }
    printf("%lld\n", ans);
	return 0;
}