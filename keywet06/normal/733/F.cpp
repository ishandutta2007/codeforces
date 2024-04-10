#include <bits/stdc++.h>
using int64 = long long;
const int N = 400005;
const int M = 800005;
const int64 INF = 1000000000000ll;
int64 read() {
    int64 x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}
struct edge {
    int next, to, id;
    int64 ds;
} a[N];
struct node {
    int x, y, id;
    int64 z, c;
} b[M];
struct nod {
    int64 x, d;
} ans1[M];
int head[N], cnt, fa1[N], used[M];
int n, m, fa[N][21], dep[N], A[N][21];
int64 ans, dis[N][21], q[2], tot, S;
int find(int x) {
    if (fa1[x] == x) return x;
    return fa1[x] = find(fa1[x]);
}
void add(int x, int y, int z, int xyz) {
    a[++cnt].next = head[x];
    a[cnt].to = y;
    a[cnt].ds = z;
    a[cnt].id = xyz;
    head[x] = cnt;
}
bool cmp(node a, node b) {
    if (a.z != b.z) return a.z < b.z;
    return a.c < b.c;
}
bool kmp(nod a, nod b) { return a.x < b.x; }
void dfs(int x, int f, int deep) {
    dep[x] = deep;
    fa[x][0] = f;
    for (int i = 1; i <= 20; ++i) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        if (dis[x][i - 1] > dis[fa[x][i - 1]][i - 1]) {
            dis[x][i] = dis[x][i - 1], A[x][i] = A[x][i - 1];
        } else {
            dis[x][i] = dis[fa[x][i - 1]][i - 1];
            A[x][i] = A[fa[x][i - 1]][i - 1];
        }
    }
    for (int i = head[x]; i; i = a[i].next) {
        int y = a[i].to;
        if (y == f) continue;
        dis[y][0] = a[i].ds;
        A[y][0] = a[i].id;
        dfs(y, x, deep + 1);
    }
}
nod ldis(int x, int y) {
    int64 res = 0, yyb;
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (dep[x] - (1 << i) >= dep[y]) {
            if (res < dis[x][i]) res = dis[x][i], yyb = A[x][i];
            x = fa[x][i];
        }
    }
    if (x == y) return (nod){yyb, res};
    for (int i = 20; i >= 0; --i) {
        if (fa[x][i] != fa[y][i]) {
            if (res < dis[x][i]) res = dis[x][i], yyb = A[x][i];
            if (res < dis[y][i]) res = dis[y][i], yyb = A[y][i];
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if (res < dis[x][0]) res = dis[x][0], yyb = A[x][0];
    if (res < dis[y][0]) res = dis[y][0], yyb = A[y][0];
    return (nod){yyb, res};
}
int main() {
    n = read();
    m = read();
    for (int i = 1; i <= m; ++i) b[i].z = read();
    for (int i = 1; i <= m; ++i) b[i].c = read();
    for (int i = 1; i <= m; ++i) b[i].x = read(), b[i].y = read(), b[i].id = i;
    S = read();
    std::sort(b + 1, b + m + 1, cmp);
    for (int i = 1; i <= n; ++i) fa1[i] = i;
    int64 minn = 1e9 + 1, sum = 0, biao;
    for (int i = 1; i <= m; ++i) {
        int xzz = find(b[i].x), yyb = find(b[i].y);
        if (xzz != yyb) {
            fa1[xzz] = yyb;
            sum += b[i].z;
            used[i] = 1;
            if (b[i].c < minn) minn = b[i].c, biao = i;
            add(b[i].x, b[i].y, b[i].z, i);
            add(b[i].y, b[i].x, b[i].z, i);
        }
    }
    ans = sum - S / minn;
    dfs(1, 0, 1);
    for (int i = 1; i <= m; ++i) {
        if (used[i] || minn <= b[i].c) continue;
        nod xzz = ldis(b[i].x, b[i].y);
        int64 yyb = sum - xzz.d + b[i].z - S / b[i].c;
        if (yyb < ans) {
            q[0] = xzz.x;
            q[1] = i;
            ans = yyb;
        }
    }
    std::cout << ans << std::endl;
    if (!q[0]) {
        for (int i = 1; i <= m; ++i) {
            if (used[i]) {
                ans1[++tot].x = b[i].id;
                if (biao == i) {
                    ans1[tot].d = b[i].z - S / b[i].c;
                } else {
                    ans1[tot].d = b[i].z;
                }
            }
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            if (used[i] && q[0] != i) {
                ans1[++tot].x = b[i].id;
                ans1[tot].d = b[i].z;
            } else if (q[1] == i) {
                ans1[++tot].x = b[i].id;
                ans1[tot].d = b[i].z - S / b[i].c;
            }
        }
    }
    std::sort(ans1 + 1, ans1 + tot + 1, kmp);
    for (int i = 1; i <= tot; ++i) {
        std::cout << ans1[i].x << ' ' << ans1[i].d << '\n';
    }
    return 0;
}