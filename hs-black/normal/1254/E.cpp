/*
  
 | _ _|
  ` _x 
   /  |
  /   ?
 | |||
 | (__)_)
 
  */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#define JzpAkIOI { write(0); exit(0); }

const int N = 1000050;
const int P = 1e9+7;
int ne[N<<1], to[N<<1], h[N], deg[N], tot = 1;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[h[x] = tot] = y, deg[x]++;
}
int f[N<<1], L[N<<1], R[N<<1], ed[N], st[N], vis[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int Merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return 1;
    return f[fx] = fy, 0;
}

ll fac[N];
int s1[N], s2[N], dep[N], fe[N], t1, t2, n;
void work(int x, int y) {
    t1 = 0, t2 = 0; int tx = x, ty = y;
    while (dep[x] > dep[y]) s1[++t1] = fe[x], deg[x]--, x = to[fe[x]];
    while (dep[y] > dep[x]) s2[++t2] = fe[y] ^ 1, deg[y]--, y = to[fe[y]];
    while (x != y) {
        s1[++t1] = fe[x], deg[x]--, x = to[fe[x]];
        s2[++t2] = fe[y] ^ 1, deg[y]--, y = to[fe[y]];
    }
    deg[x]--;
    for (int i = t2;i >= 1; i--) s1[++t1] = s2[i];
    if (st[tx] || L[s1[1]]) JzpAkIOI;
    st[tx] = s1[1], L[s1[1]] = -1;
    for (int i = 2;i <= t1; i++) {
        x = s1[i - 1] ^ 1, y = s1[i];
        if (R[x] || L[y] || Merge(x, y)) JzpAkIOI;
        R[x] = y, L[y] = x;
    }
    int ee = s1[t1] ^ 1;
    if (ed[ty] || R[ee]) JzpAkIOI;
    ed[ty] = ee, R[ee] = -1;
}

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (int i = h[x]; i; i = ne[i]) 
        if (to[i] != fa) fe[to[i]] = i ^ 1, dfs(to[i], x);
}

int main() {
//	freopen ("hs.in","r",stdin);
    read(n); fac[0] = 1;
    for (int i = 1;i <= n; i++) fac[i] = fac[i-1] * i % P;
    for (int i = 1, x, y;i < n; i++)
        read(x), read(y), add(x, y), add(y, x);
    dfs(1, 0);
    for (int i = 1;i <= tot; i++) f[i] = i;
    for (int i = 1, x;i <= n; i++) {
        read(x); if (!x) continue;
        if (vis[x] || x == i) JzpAkIOI;
        work(x, i); vis[x] = 1;
    }
//    puts("OK");
    ll res = 1;
//    for (int i = 1;i <= n; i++) write(deg[i], ' ');
    for (int i = 1;i <= n; i++) 
        if (st[i] && ed[i]) {
            if (find(st[i]) != find(ed[i])) res = res * fac[deg[i]] % P;
            else if (deg[i] != -1) JzpAkIOI;
        } else res = res * fac[deg[i]] % P;
    write(res);
    return 0;
}

/*

10
6 2
8 9
1 4
1 9
8 3
7 1
3 5
9 2
10 1
7 5 0 0 3 0 10 4 0 0

*/