#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 10005;
int k[N], p[N], c[N];
int read(void) {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}

int h[N], ne[N<<1], to[N<<1];
int d, n, m, tot;
inline void add(int x,int y) {
    ne[++tot] = h[x], to[tot] = y;
    h[x] = tot;
}

int vis[N], tim;
int match[N];
bool dfs(int x) {
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; if (vis[y] == tim) continue;
        vis[y] = tim;
        if (!(~match[y]) || dfs(match[y])) {
            match[y] = x; return true;
        }
    }
    return false;
}

int ans[N], v[N];
int main() {
    n = read(), m = read();
    memset(match, -1, sizeof(match));
    for (int i = 1;i <= n; i++) p[i] = read();
    for (int i = 1;i <= n; i++) c[i] = read();
    int pre = -1, nw;
    d = read();
    for (int i = 1;i <= d; i++) k[i] = read(), v[k[i]] = 1;
    for (int i = 1;i <= n; i++) 
        if (!v[i] && c[i] <= m) add(p[i], c[i]);
    for (int i = d;i >= 1; i--) {
        for (nw = pre + 1;nw <= n; nw++) {
            tim++; if (!dfs(nw)) break;
        }
        if (c[i] <= m) add(p[k[i]], c[k[i]]); 
        ans[i] = nw; pre = nw - 1;
    }
    for (int i = 1;i <= d; i++) printf ("%d\n", ans[i]);
    return 0;
}