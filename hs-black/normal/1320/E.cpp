#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include <queue>
#define ll long long
using namespace std;
const int N = 1005000;
template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    if (f) x=-x;
}
int n, m;
int h[N], ne[N], to[N];
int dep[N], tot;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[h[x] = tot] = y;
}
int siz[N], f[N], son[N];
int Top[N], a[N], s[N], top;
void dfs1(int x, int fa) {
    siz[x] = 1, f[x] = fa, dep[x] = dep[fa] + 1;
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; if (y == fa) continue;
        dfs1(y, x), siz[x] += siz[y];
        if (siz[y] > siz[son[x]]) son[x] = y;
    }
}

int dfn[N], num;
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

bool cmp(int a, int b) {
    return dfn[a] < dfn[b];
}

vector <int> v[N];
inline void add_e(int x,int y) {
    v[x].push_back(y); v[y].push_back(x);
}

void ins(int x) {
    if (top == 1) return (void)(s[++top] = x);
    int lca = Lca(x, s[top]); 
    if (lca == s[top]) return (void)(s[++top] = x);
    while (top > 1 && dfn[s[top-1]] >= dfn[lca]) add_e(s[top-1], s[top]), top--;
    if (lca != s[top]) add_e(lca, s[top]), s[top] = lca;
    s[++top] = x;
}


int ask[N], vis[N];

struct node {
    int col, v, di, ti;
    bool operator < (const node &j) const{
        if (ti != j.ti) return ti < j.ti;
        if (col != j.col) return col < j.col;
        return di > j.di;
    }
}qaq[N], I;

inline int Dis(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[Lca(x, y)];
}
node To(int x, int y) {
    int dis = Dis(x, y);
    node tmp = qaq[x]; 
    if (dis <= qaq[x].di) {
        tmp.di -= dis; return tmp;
    }
    dis -= qaq[x].di;
    int t = (dis - 1) / qaq[x].v + 1;
    tmp.di = t * qaq[x].v - dis, tmp.ti += t;
    return tmp;
}

struct QWQ {
    node p; int x;
    bool operator < (const QWQ &j) const { return j.p < p; }
};

priority_queue<QWQ> q;

int T;

inline bool Cmp(node a, QWQ b) { return a < b.p; }

void diji(void) {
    while (q.size()) {
        QWQ x = q.top(); q.pop();
        if (Cmp(qaq[x.x], x)) continue;
        for (auto y: v[x.x]) {
            node t = To(x.x, y);
            if (t < qaq[y]) {
                qaq[y] = t; q.push((QWQ){qaq[y], y});
            }
        }
    }
}

void refresh(int x, int f) {
    for (auto i: v[x]) {
        if (i == f) continue;
        refresh(i, x);
    }
    v[x].clear(); qaq[x] = I;
}

void init(int m, int k) {   
    int cnt = m;
    for (int i = 1;i <= m; i++) {
        read(a[i]), qaq[a[i]].col = i, read(qaq[a[i]].v);
        qaq[a[i]].ti = 0; q.push((QWQ){qaq[a[i]], a[i]}); 
    }
    for (int i = 1;i <= k; i++) 
        read(ask[i]), a[++cnt] = ask[i];
    sort(a + 1, a + cnt + 1, cmp);
    s[top = 1] = a[0] = 1;
    for (int i = 1;i <= cnt; i++) {
        if (a[i] == a[i-1]) continue;
        ins(a[i]);
    }
    while (top > 0) add_e(s[top - 1], s[top]), top--;
}

int main() {
//  freopen ("hs.in","r",stdin);
//  freopen ("hs.out","w",stdout);
    read(n);
    for (int i = 1;i < n; i++) {
        int x, y; read(x), read(y);
        add(x, y); add(y, x);
    }
    dfs1(1, 0), dfs2(1, 1);
    I.col = n + 1, I.ti = n + 1;
    for (int i = 1;i <= n; i++) qaq[i] = I;
    int ww; read(ww);
    while (ww--) {
        int k, m; read(m), read(k);
        init(m, k), diji();
        for (int i = 1;i <= k; i++) printf ("%d ", qaq[ask[i]].col);
        putchar('\n'); refresh(1, 0);
    }
    return 0;
}