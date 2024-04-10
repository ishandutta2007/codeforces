#include <bits/stdc++.h>

using int64 = long long;

const int64 INF = int64(2e9) + 111;

const int N = 200;

int k, t, len;
int can[16];
int d[N];
int c[N][20];

void init() {
    for (int i = 0; i < 20; ++i) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 20; ++j) c[i][j] = std::min(INF, (int64)c[i - 1][j - 1] + c[i - 1][j]);
    }
}

int solve() {
    memset(d, 0, sizeof d);
    d[0] = 1;
    for (int i = 0; i < 16; ++i) {
        for (int j = len; j >= 0; --j) {
            if (d[j] == 0) continue;
            for (int k = 1; k <= can[i]; ++k) d[j + k] = std::min(INF, d[j + k] + (int64)d[j] * c[j + k][k]);
        }
    }
    return d[len];
}

char getChar(int val) {
    if (val < 10) return char('0' + val);
    return char('a' + (val - 10));
}

char ans[N];

void solve(int len, int dig) {
    ans[0] = getChar(dig);
    for (int i = 1; i < len; ++i) {
        for (int j = 0; i < 16; ++j)
            if (can[j]) {
                --can[j];
                ::len = len - 1 - i;
                int cnt = solve();
                if (cnt >= k) {
                    ans[i] = getChar(j);
                    break;
                }
                ++can[j];
                k -= cnt;
            }
    }
    ans[len] = '\0';
    printf("%s\n", ans);
}

int main() {
    init();
    scanf("%d %d", &k, &t);
    for (int i = 0; i < 16; ++i) can[i] = t;
    for (int i = 0;; ++i) {
        for (int j = 1; j < 16; ++j) {
            --can[j];
            len = i;
            int cnt = solve();
            if (cnt >= k) {
                solve(i + 1, j);
                return 0;
            }
            ++can[j];
            k -= cnt;
        }
    }
    return 0;
}