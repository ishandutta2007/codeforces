#include <bits/stdc++.h>
#define re register
using namespace std;
inline int read() {
    re int t = 0;
    re char v = getchar();
    while (v < '0') v = getchar();
    while (v >= '0') t = (t << 3) + (t << 1) + v - 48, v = getchar();
    return t;
}
struct edge {
    int to, next;
} e[8000002];
int t, n, m, ans, cnt, head[1000002], b[1000002], dfn[400002], low[400002], tot,
    stk[400002], ist[400002], tp, tim, bl[400002], blk, rd[400002], lst[400002];
inline void add(re int x, re int y) {
    e[++cnt] = (edge){y, head[x]}, head[x] = cnt;
}
inline void tj(re int x) {
    dfn[x] = low[x] = ++tim, ist[x] = 1, stk[++tp] = x;
    for (re int i = head[x]; i; i = e[i].next)
        if (!dfn[e[i].to])
            tj(e[i].to), low[x] = min(low[x], low[e[i].to]);
        else if (ist[e[i].to])
            low[x] = min(low[x], dfn[e[i].to]);
    if (dfn[x] == low[x]) {
        ++blk;
        do {
            ist[stk[tp]] = 0;
            bl[stk[tp]] = blk;
            --tp;
        } while (stk[tp + 1] ^ x);
    }
}
vector<char> a[400002];
vector<int> pos[400002];
char s[400002];
signed main() {
    n = read(), m = read();
    a[0].resize(m + 3), pos[0].resize(m + 3);
    for (re int i = 1; i <= n; ++i) {
        a[i].resize(m + 3), pos[i].resize(m + 3);
        scanf("%s", s + 1);
        for (re int j = 1; j <= m; ++j) pos[i][j] = ++tot, a[i][j] = s[j];
    }
    for (re int i = n; i; --i) {
        for (re int j = 1; j <= m; ++j)
            if (a[i][j] == '#') {
                if (a[i][j - 1] == '#')
                    add(pos[i][j], pos[i][j - 1]);
                else if (lst[j - 1])
                    add(pos[i][j], lst[j - 1]);
                if (lst[j]) add(pos[i][j], lst[j]);
                if (a[i][j + 1] == '#')
                    add(pos[i][j], pos[i][j + 1]);
                else if (lst[j + 1])
                    add(pos[i][j], lst[j + 1]);
                if (a[i - 1][j] == '#') add(pos[i][j], pos[i - 1][j]);
            }
        for (re int j = 1; j <= m; ++j)
            if (a[i][j] == '#') lst[j] = pos[i][j];
    }
    for (re int i = 1; i <= n; ++i)
        for (re int j = 1; j <= m; ++j)
            if (a[i][j] == '#' && !dfn[pos[i][j]]) tj(pos[i][j]);
    for (re int i = 1; i <= tot; ++i)
        for (re int j = head[i]; j; j = e[j].next)
            if (bl[i] ^ bl[e[j].to]) ++rd[bl[e[j].to]];
    for (re int i = 1; i <= blk; ++i)
        if (rd[i] == 0) ++ans;
    printf("%d", ans);
}