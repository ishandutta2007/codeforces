#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 505000;
template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    if (f) x=-x;
}

vector<int> v[N];
int a[N], h[N], to[N], ne[N];
int dfn[N], Top[N], f[N], s[N];
int son[N], siz[N], dep[N];
int n, top, num, tot;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[tot] = y, h[x] = tot;
}

void dfs1(int x, int fa) {
    siz[x] = 1, f[x] = fa, dep[x] = dep[fa] + 1;
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; if (y == fa) continue;
        dfs1(y, x), siz[x] += siz[y];
        if (siz[y] > siz[son[x]]) son[x] = y;
    }
}


void dfs2(int x, int topf) {
    Top[x] = topf, dfn[x] = ++num;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = h[x]; i; i = ne[i]) 
        if (!dfn[to[i]]) dfs2(to[i], to[i]);
}

int Lca(int x, int y) {
    while (Top[x] != Top[y]) {
        if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
        x = f[Top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

inline void add_e(int x,int y) {
    v[x].push_back(y);
}

int inp[N];
void ins(int x) {
    if (top == 1) return s[++top] = x, void();
    int lca = Lca(x, s[top]);
    if (lca == s[top]) return s[++top] = x, void();
    while (top > 1 && dfn[s[top-1]] >= dfn[lca]) add_e(s[top-1], s[top]), top--;
    if (lca != s[top]) add_e(lca, s[top]), s[top] = lca;
    s[++top] = x;
}

int ans;
void dp(int x) {
    if (!v[x].size()) return;
    int cnt = 0;
    for (int i = 0;i < v[x].size(); i++) {
        dp(v[x][i]), cnt += inp[v[x][i]];
        inp[v[x][i]] = 0;
    }
    v[x].clear();
    if (inp[x]) ans += cnt;
    else if (cnt >= 2) ans++;
    else if (cnt) inp[x] = 1;
}

bool cmp(int a, int b) {
    return dfn[a] < dfn[b];
}


int main() {
    read(n);
    for (int i = 1;i < n; i++) {
        int x, y; read(x), read(y);
        add(x, y), add(y, x);
    }
    dfs1(1, 0), dfs2(1, 1);
    int m; read(m);
    while (m--) {
        int k; read(k);
        for (int i = 1;i <= k; i++) read(a[i]), inp[a[i]] = 1;
        int flag = 0;
        for (int i = 1;i <= k; i++) if (inp[f[a[i]]]) {flag = 1;break;}
        if (flag) for (int i = 1;i <= k; i++) inp[a[i]] = 0;
        if (flag) {printf ("-1\n"); continue;}
        sort(a + 1, a + k + 1, cmp); s[top = 1] = 1;
        for (int i = 1;i <= k; i++) {
            inp[a[i]] = 1;
            if (a[i] != 1) ins(a[i]);
        }
        while (top > 0) add_e(s[top-1], s[top]), top--;
        ans = 0, dp(1), inp[1] = 0; printf ("%d\n", ans);
    }
    return 0;
}