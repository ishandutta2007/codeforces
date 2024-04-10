#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 405;

int n, m;
char s[mxn][mxn];
short rem0[mxn][mxn][mxn];

int ccc(int r, int i, int j, int c) {
    if (i > j) return 0;
    if (c == 1) return (j - i + 1) - ccc(r, i, j, 0);
    if (~rem0[r][i][j]) return rem0[r][i][j];
    return rem0[r][i][j] = ccc(r, i, j - 1, c) + (s[r][j] != c + '0');
}

int calc0(int r, int i, int j) {
    return ccc(r, i + 1, j - 1, 1);
}

int calc1(int r, int i, int j) {
    return ccc(r, i + 1, j - 1, 0) + (s[r][i] != '1') + (s[r][j] != '1');
}

void Main() {
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%s", s[i]);
    rep(i, n) rep(j, m) rep(k, m) rem0[i][j][k] = -1;
    int ans = 1 << 30;
    for (int i = 0; i < m; ++ i) {
        for (int j = i + 4 - 1; j < m; ++ j) {
            static int sum[mxn];
            for (int r = 0; r < n; ++ r) {
                sum[r] = (r ? sum[r - 1] : 0) + calc1(r, i, j);
            }
            int min = 1 << 30;
            for (int r = n - 1; ~r; -- r) {
                if (r + 4 < n) min = std::min(min, sum[r + 4 - 1] + calc0(r + 4, i, j));
                ans = std::min(ans, calc0(r, i, j) + min - sum[r]);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
	return 0;
}