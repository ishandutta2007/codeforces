/*
   
  | _ _|
   ` _x 
    /  |
   /   ?
  | |||
  | (__)_)
  
 
 */

#define OK printf ("Pass on Line #%d\n", __LINE__)
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
inline void write(T *st, int n, string s = "") {
    if (s.size()) cout << s << ": ";
    while (n--) write(*st++, ' ');
    puts("");
}

const int N = 200005;
int f[N], col[N], siz[N], cnt, n;
int stx[N], sty[N], scc, pp[N], tp;
struct node {
    ll x, y; int id;
    node (ll xx = 0, ll yy = 0, int dd = 0) { x = xx, y = yy, id = dd; }
    node operator - (const node &i) const { return node(x - i.x, y - i.y, id); }
    bool operator < (const node &i) const {
        int a = y > 0 || (y == 0 && x > 0);
        int b = i.y > 0 || (i.y == 0 && i.x > 0);
        if (a != b) return a < b;
        return x * i.y > y * i.x;
    }
}p[N], P[N];

inline void Swap(int x, int y) {
    swap(pp[x], pp[y]), stx[++tp] = x, sty[tp] = y;
}
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline bool check(node A, node B) {
    node t1 = B, t2 = A;
    return t1.x * t2.y > t1.y * t2.x;
}
void solve(int X) {
    /* write(scc); */
    for (int i = 1;i <= n; ++i)
        if (i != X && siz[col[i]] != 1) P[++cnt] = p[i] - p[X];
    sort(P + 1, P + cnt + 1), P[cnt + 1] = P[1];
    for (int i = 1;i <= cnt; ++i) {
        int x = P[i].id, y = P[i + 1].id;
        int cx = col[x], cy = col[y];
        if (find(cx) == find(cy)) continue;
        if (check(P[i], P[i + 1])) continue;
        Swap(x, y), f[find(cx)] = find(cy);
    }
    /* write(tp); */
    for (int i = 1;i <= cnt; ++i) Swap(X, pp[X]);
}
int vis[N];
int main() {
    read(n);
    for (int i = 1;i <= n; ++i) 
        read(p[i].x), read(p[i].y), p[i].id = i, read(pp[i]);
    for (int i = 1;i <= n; ++i) if (!vis[i]) {
        vis[i] = siz[++scc] = 1, f[scc] = scc, col[i] = scc;
        for (int rt = pp[i];rt != i; rt = pp[rt])
            vis[rt] = 1, ++siz[scc], col[rt] = scc;
    }
    for (int i = 1;i <= n; ++i)
        if (siz[col[i]] != 1) { solve(i); break; }
    write(tp);
    for (int i = 1;i <= tp; ++i)
        write(stx[i], ' '), write(sty[i]);
    return 0;
}