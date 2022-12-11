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


const int N = 100500;
int sum[301][N<<1], *sm[301], dep[N], ne[N<<1], to[N<<1], h[N], tot; 
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
int f[N], siz[N], son[N], Top[N], id[N], dfn[N], cnt, S;
void dfs1(int x, int fa) {
    dep[x] = dep[f[x] = fa] + (siz[x] = 1);
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; if (y == fa) continue;
        dfs1(y, x), siz[x] += siz[y];
        if (siz[y] > siz[son[x]]) son[x] = y;
    }
}

void dfs2(int x, int topf) {
    Top[x] = topf, id[dfn[x] = ++cnt] = x;
    if (son[x]) dfs2(son[x], topf);
    for (int i = h[x], y; i; i = ne[i])
        if (!dfn[y = to[i]]) dfs2(y, y);
}

int L[N], R[N], bl[N], t[N], tag[N], col[N], ans, m, n;
void prework(void) {
    S = 340, cnt = 0;
    for (int i = 1;i <= n; ++i) t[i] = min(t[i], m + 1);
    for (int l = 1, r = 1;l <= n; l = r = r + 1) {
        r = min(l + S - 1, n), L[++cnt] = l, R[cnt] = r;
        //OK;
        //write(cnt, ' '), write(l, ' '), write(r);
        sm[cnt] = sum[cnt] + m + 1;
        for (int i = l;i <= r; ++i) bl[i] = cnt, sm[cnt][t[id[i]]]++;
    }
}

inline void C(int b, int p, int c) {
    //write(b, ' '), write(p, ' '), write(c);
    p = id[p]; 
    if (!col[p]) --sm[b][t[p]], ans -= tag[b] >= t[p];
    t[p] -= c;
    if (!col[p]) ++sm[b][t[p]], ans += tag[b] >= t[p];
}

void Add(int l, int r, int c) {
    if (bl[l] == bl[r]) {
        for (int i = l;i <= r; ++i) C(bl[l], i, c);
        return;
    }
    for (int i = l;bl[l] == bl[i]; ++i) C(bl[l], i, c);
    for (int i = r;bl[r] == bl[i]; --i) C(bl[r], i, c);
    for (int i = bl[l] + 1;i < bl[r]; ++i) {
        if (c > 0) ans += sm[i][++tag[i]];
        else ans -= sm[i][tag[i]--];
    }
}

void change(int x, int c) {
    int b = bl[dfn[x]];
    if (!col[x]) --sm[b][t[x]], ans -= tag[b] >= t[x];
    col[x] ^= 1;
    if (!col[x]) ++sm[b][t[x]], ans += tag[b] >= t[x];
    while (x) Add(dfn[Top[x]], dfn[x], c), x = f[Top[x]];
}

int main() {
    read(n), read(m);
    for (int i = 2, x;i <= n; ++i) read(x), add(x, i);
    for (int i = 1;i <= n; ++i) read(t[i]), ++t[i];
    dfs1(1, 0), dfs2(1, 1), prework();
    //write(dfn, n + 1, "DFN");
    //write(L, n + 1, "L"), write(R, n + 1, "R");
    //write(bl, n + 1, "BL");
    //OK;
    for (int i = 1, x;i <= m; ++i) 
        read(x), x > 0 ? change(x, 1) : change(-x, -1), write(ans, ' ');
    return 0;
}