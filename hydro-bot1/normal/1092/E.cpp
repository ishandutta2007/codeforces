// Hydro submission #614adb16de83b96f5ecfd5cf@1632295703290
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5010;
int n, m, head[N], to[N * 2], pre[N * 2], tot;
int rt[N], co[N], sum, dep[N], d[N], len[N];

long long read() {
    char ch;
    long long ans = 0, f = 1;
    ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;

        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }

    return ans * f;
}

void add(int u, int v) {
    to[++tot] = v;
    pre[tot] = head[u];
    head[u] = tot;
}

int fur;

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;

    if (dep[fur] < dep[u])
        fur = u;

    co[u] = sum;

    for (int i = head[u]; i; i = pre[i])
        if (to[i] != fa)
            dfs(to[i], u);
}

int dfs2(int u, int fa) {
    dep[u] = dep[fa] + 1;
    int p = 0;

    for (int i = head[u]; i; i = pre[i])
        if (to[i] != fa)
            p |= dfs2(to[i], u);

    if (dep[fur] < dep[u]) {
        fur = u;
        p = 1;
    }

    if (p && dep[u] == dep[fur] / 2 + 1) {
        rt[sum] = u;
        d[sum] = max(dep[u] - 1, dep[fur] - dep[u]);
    }

    return p;
}

int main() {
    n = read();
    m = read();

    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }

    for (int i = 1; i <= n; i++)
        if (!co[i]) {
            co[i] = ++sum;
            dep[0] = 0;
            fur = 0;
            dfs(i, 0);
            int mx = fur;
            fur = 0;
            dfs2(mx, 0);
            len[sum] = dep[fur] - 1;
            //printf("%d %d %d %d %d\n", i, fur, d[sum], len[sum], rt[sum]);
        }

    int asrt = 0, ans = 1e9;

    for (int i = 1; i <= sum; i++) {
        int mx = 0, mxx = 0;

        for (int j = 1; j <= sum; j++)
            if (j != i) {
                int tmp = j;

                if (d[mx] <= d[tmp])
                    swap(mx, tmp);

                if (d[mxx] <= d[tmp])
                    swap(mxx, tmp);
            }

        int tmp = 0;

        if (mx)
            tmp = max(tmp, d[mx] + d[i] + 1);

        if (mxx)
            tmp = max(tmp, d[mx] + d[mxx] + 2);

        if (ans > tmp)
            ans = tmp, asrt = i;
    }

    for (int i = 1; i <= sum; i++)
        ans = max(ans, len[i]);

    printf("%d\n", ans);

    for (int i = 1; i <= sum; i++)
        if (i != asrt)
            printf("%d %d\n", rt[i], rt[asrt]);

    return 0;
}