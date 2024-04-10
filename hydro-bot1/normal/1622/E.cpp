// Hydro submission #62596d3e37de167dd82c254a@1650027838909
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define N 20
#define M 10010

int n, m, x[N], res, r[M];
pair<int, int> s[M];
char a[N][M];

signed main() {
    for (int T = read(); T --;) {
        n = read(), m = read(), res = -1;
        for (int i = 1; i <= n; i ++) {
            x[i] = read();
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%s", a[i] + 1);
        }
        for (int st = 0; st < 1 << n; st ++) {
            int now = 0;
            for (int i = 1; i <= m; i ++) {
                s[i].first = 0;
                s[i].second = i;
            }
            for (int i = 1; i <= n; i ++) {
                int op = (st >> i - 1) & 1;
                now += op ? -x[i] : x[i];
                for (int j = 1; j <= m; j ++) {
                    if (a[i][j] == '1') {
                        s[j].first += op ? 1 : -1;
                    }
                }
            }
            sort(s + 1, s + m + 1);
            for (int i = 1; i <= m; i ++) {
                now += i * s[i].first;
            }
            if (now > res) {
                res = now;
                for (int i = 1; i <= m; i ++) {
                    r[s[i].second] = i;
                }
            }
        }
        for (int i = 1; i <= m; i ++) {
            printf("%d ", r[i]);
        }
        puts("");
    }
    return 0;
}