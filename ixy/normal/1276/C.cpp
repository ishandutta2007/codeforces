#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, ans, pi, pj, ansi, ansj, a[N], b[N], c[N], pre[N], suf[N], cnt[N];
std::vector<std::vector<int>> vec, tmp;

bool check(int i, int j) {
    int hav = pre[i] + suf[i + 1] * i;
    return hav >= i * j;
}

inline int put(int r, int c, int x) {
    if (pi < r && pj < c) {
        tmp[pi][pj] = x; pi++;
        if (pi == r) { pi = 0; pj++; }
    }
}
int solve(int r, int c) {
    vec.resize(r);
    for (int i = 0; i < r; i++) { vec[i].resize(c); }
    tmp = vec; pi = pj = 0;
    for (int i = 0; i < m; i++) {
        if (cnt[i] >= r) {
            int x = b[i];
            for (int j = 0; j < r; j++) { put(r, c, x); }
        }
    }
    for (int i = 0; i < m; i++) {
        if (cnt[i] < r) {
            int x = b[i];
            for (int j = 0; j < cnt[i]; j++) { put(r, c, x); }
        }
    }
    for (int i = 0; i < r; i++) {
        int k = (i + 1) % r;
        for (int j = 0; j < c; j++) {
            vec[i][(j + k) % c] = tmp[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = b[i] = read(); }
    std::sort(b, b + n); m = std::unique(b, b + n) - b;
    for (int i = 0; i < n; i++) { a[i] = std::lower_bound(b, b + m, a[i]) - b; cnt[a[i]]++; }
    for (int i = 0; i < m; i++) { c[cnt[i]]++; }
    for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + c[i] * i; }
    for (int i = n; i >= 1; i--) { suf[i] = suf[i + 1] + c[i]; }
    for (int i = 1; i <= n; i++) {
        for (int j = i; ; j++) {
            if (1ll * i * j > n) { break; }
            if (check(i, j)) {
                if (ans < i * j) {
                    ans = i * j; ansi = i; ansj = j;
                }
            } else {
                break;
            }
        }
    }
    printf("%d\n%d %d\n", ans, ansi, ansj);
    solve(ansi, ansj);
    return 0;
}