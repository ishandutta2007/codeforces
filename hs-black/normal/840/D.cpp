/*
   
  | _ _|
   ` _x 
    /  |
   /   ?
  | |||
  | (__)_)
  
 
     AzusaCat yyds!
 
 */

#define Fin freopen ("hs.in","r",stdin)
#define Fout freopen ("hs.out","w",stdout)
#define OK puts("OK")
#define Iloveccf false
#define AzusaAkIOI true
#define jzpyyds true
#define lhmrsyj true
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

const int N = 405000;
int ls[N<<4], rs[N<<4], siz[N<<4], rt[N], cnt, m, n;
int update(int p, int l, int r, int x) {
    int rt = ++cnt; siz[cnt] = siz[p] + 1;
    ls[cnt] = ls[p], rs[cnt] = rs[p];
    if (l == r) return cnt;
    int mid = (l + r) >> 1;
    if (x <= mid) ls[rt] = update(ls[p], l, mid, x);
    else rs[rt] = update(rs[p], mid + 1, r, x);
    return rt;
}

int query(int u, int v, int l, int r, int sz) {
    if (l == r) return l;
    int mid = (l + r) >> 1, t = -1;
    int tl = siz[ls[u]] - siz[ls[v]];
    int tr = siz[rs[u]] - siz[rs[v]];
    if (tl >= sz) t = query(ls[u], ls[v], l, mid, sz);
    if (~t) return t;
    if (tr >= sz) t = query(rs[u], rs[v], mid + 1, r, sz);
    return t;
}

int main() {
    read(n), read(m);
    for (int i = 1, x; i <= n; i++) 
        read(x), rt[i] = update(rt[i-1], 1, n, x);
    for (int i = 1, l, r, k; i <= m; i++) {
        read(l), read(r), read(k);
        write(query(rt[r], rt[l-1], 1, n, (r - l + 1) / k + 1));
    }
    return 0;
}