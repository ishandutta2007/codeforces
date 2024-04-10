#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

/*
namespace FMT {
const int n = 20;
const int N = 1 << n;

void fmt(long long f[]) {
    for (int h = 1; h < N; h <<= 1)
        for (int i = 0; i < N; i += h << 1) {
            long long *f0 = f + i, *f1 = f + i + h;
            for (int j = 0; j < h; ++ j, ++ f0, ++ f1)
                *f1 += *f0;
        }
}

void ifmt(long long f[]) {
    for (int h = 1; h < N; h <<= 1)
        for (int i = 0; i < N; i += h << 1) {
            long long *f0 = f + i, *f1 = f + i + h;
            for (int j = 0; j < h; ++ j, ++ f0, ++ f1)
                *f1 -= *f0;
        }
}
} // FMT
*/

const int mxl = 1e6 + 5, sigma = 20, mxn = 1 << sigma;

int n;
char s[mxl];
int f[mxn], g[mxn];

int main() {
    scanf("%s", s);
    n = strlen(s);
    int ans = 0;
    int len = 0, mask = 0;
    rep(i, n) {
        while (i + len < n && !(mask >> (s[i + len] - 'a') & 1)) {
            mask |= 1 << (s[i + len] - 'a');
            ++ len;
        }
        int S = 0;
        rep(j, len) {
            S |= 1 << (s[i + j] - 'a');
            f[S] = j + 1;
            g[S] = j + 1;
        }
        ans = std::max(ans, len);
        -- len;
        mask ^= 1 << (s[i] - 'a');
    }
    rep(i, mxn) rep(j, sigma) if (i >> j & 1) g[i] = std::max(g[i], g[i ^ 1 << j]);
    rep(i, mxn) if (f[i]) ans = std::max(ans, f[i] + g[(mxn - 1) ^ i]);
    /*
    rep(i, sigma + 1) FMT::fmt(f[i]);
    rep(i, sigma + 1) rep(j, i) rep(S, 1 << sigma) g[i][S] += 1LL * f[j][S] * f[i - j][S];
    rep(i, sigma + 1) FMT::ifmt(g[i]);
    rep(i, sigma + 1) rep(S, 1 << sigma) if (__builtin_popcount(S) == i && g[i][S]) ans = std::max(ans, i);
    */
    ;
    printf("%d\n", ans);
	return 0;
}