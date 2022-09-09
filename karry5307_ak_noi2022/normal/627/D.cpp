#include<bits/stdc++.h>
using namespace std;
#define N 200101
int fi[N], tot;
struct edge {
    int nx, to;
}e[N * 2];
void ps(int x, int y) {
    e[++tot] = (edge){ fi[x],y };
    fi[x] = tot;
}
int v[N], n, m, sz[N], g[N], dp[N], b[N];


int TS = 0;


bool vis[N];
int m2[N];
int ans,r;
void dfs1(int x, int fa) {
    vis[x] = 1;
    sz[x] = 1;
    g[x] = b[x];
    if (!b[x]) { dp[x] = 0;return; }
    dp[x] = 1;
    int mx = 0,mx2=0;
    for (int i = fi[x], y;(y = e[i].to);i = e[i].nx) {
        if (y == fa)continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (g[y])dp[x] += sz[y];
        else {
            if (mx < dp[y])mx2 = mx, mx = dp[y];
            else mx2 = max(mx2, dp[y]);
            g[x] = 0;
        }
    }
    if (g[x])dp[x] = sz[x];
    else dp[x] += mx;
    m2[x] = mx2;
    ans = max(ans, dp[x] + m2[x]);
    if (TS)cout << x << ':' << dp[x] << ' ' << mx << endl;
}
void dfs2(int x, int fa, int s) {
    if(TS) cout << x << ' ' << s << endl;
    ans = max(ans, dp[x] + s+m2[x]);
    int t = 0, p = 0;
    for (int i = fi[x], y;(y = e[i].to);i = e[i].nx) if (y != fa)if (!g[y])++t, p = y;
    if (t > 1)return;
    if(t==1&&b[p])dfs2(p, x, sz[r] - sz[p]);
}
bool check(int x) {
    for (int i = 1;i <= n;i++) {
        if (v[i] >= x)b[i] = 1;
        else b[i] = 0;
        vis[i] = 0;
    }
    ans = -1e9;
    for (int i = 1;i <= n;i++) if (!vis[i] && b[i]) {
        r = i;
        dfs1(i, 0);
        dfs2(i, 0, 0);
    }
    if(TS) cout <<"ans"<< x << ' ' << ans << endl;
    return ans >= m;
}

int main() {
    int mx=-1e9;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &v[i]);mx = max(mx, v[i]);
    }
    for (int i = 1,a,b;i < n;i++) {
        scanf("%d%d", &a, &b);
        ps(a, b);ps(b, a);
    }
    if (TS==2) {
        while (scanf("%d", &m))check(m);
    }
    int l = 0, r = mx + 1;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid))l = mid;
        else r = mid;
    }
    printf("%d\n", l);
}