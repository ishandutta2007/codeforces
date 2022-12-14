#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 5e5 + 5, S = 8e2 + 5;

int n, q, sqn;
long long a[N], f[S][S];

int main() {
    n = 5e5; sqn = sqrt(n);
    for (q = read(); q; q--) {
        int opt = read(), m = read(), x = read();
        if (opt == 1) {
            a[m] += x;
            for (int i = 1; i <= sqn; i++) { f[i][m % i] += x; }
        } else {
            long long ans = 0;
            if (m <= sqn) {
                ans = f[m][x];
            } else {
                for (int i = x; i <= n; i += m) { ans += a[i]; }
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}