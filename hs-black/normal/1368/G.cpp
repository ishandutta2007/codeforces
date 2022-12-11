/*
  
 | _ _|
  ` _x 
   /  |
  /   ?
 | |||
 | (__)_)
 
  */

#define DEBUG
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


const int N = 400500;
struct node {
    int pos, L, R, f;
    bool operator < (const node &i) const {
        return pos < i.pos;
    }
}p[N<<1];

#define ls p << 1
#define rs ls | 1
int nmb[N<<2], len[N<<2];
void change(int p, int l, int r, int L, int R, int d) {
    if (L <= l && r <= R) {
        nmb[p] += d;
        if (l == r) len[p] = nmb[p]  ? 1 : 0;
        else len[p] = nmb[p] ? r - l + 1 : len[ls] + len[rs];
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) change(ls, l, mid, L, R, d);
    if (R > mid) change(rs, mid + 1, r, L, R, d);
    len[p] = nmb[p] ? r - l + 1 : len[ls] + len[rs];
}

int cnt; ll ans;
int dfncnt, dep[N], deg[N], X[N], Y[N], dfn[N], siz[N], tp, m, n;
void solve(void) {
    sort(p + 1, p + cnt + 1);
    for (int l = 1, r = 1;l <= cnt; l = r + 1, r = l) {
        while (r <= cnt && p[r+1].pos == p[l].pos) r++;
        for (int i = l;i <= r; i++) change(1, 1, dfncnt, p[i].L, p[i].R, p[i].f);
        if (r != cnt) ans += (ll)(p[r+1].pos - p[r].pos) * len[1];
    }
}

char s[N];
int num(int x, int y) { return (x - 1) * m + y; }
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) { 
    ne[++tot] = h[x], to[h[x] = tot] = y, deg[y]++;
}

void dfs(int x) {
    dfn[x] = ++dfncnt, siz[x] = 1;
    for (int i = h[x]; i; i = ne[i])
        dfs(to[i]), siz[x] += siz[to[i]];
}

#undef DEBUG
int main() {
    read(n), read(m);
    for (int i = 1;i <= n; i++) {
        scanf ("%s", s + 1);
        for (int j = 1;j <= m; j++) {
            if (s[j] == 'L') {
                if ((i + j) & 1) X[++tp] = num(i, j), Y[tp] = num(i, j + 1);
                else X[++tp] = num(i, j + 1), Y[tp] = num(i, j);
                if (j < m - 1) add(num(i, j + 2), num(i, j));
                if (j > 1) add(num(i, j - 1), num(i, j + 1));
            }
            if (s[j] == 'U') {
                if ((i + j) & 1) X[++tp] = num(i, j), Y[tp] = num(i + 1, j);
                else X[++tp] = num(i + 1, j), Y[tp] = num(i, j);
                if (i < n - 1) add(num(i + 2, j), num(i, j));
                if (i > 1) add(num(i - 1, j), num(i + 1, j));
            }
        }
    }
#ifdef DEBUG
    printf ("OK on LINE: %d\n", __LINE__);
#endif
    for (int i = 1;i <= n; i++) 
        for (int j = 1;j <= m; j++) 
            if (((i + j) & 1) && !deg[num(i, j)]) dfs(num(i, j));
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++)
           if (!((i + j) & 1) && !deg[num(i, j)]) dfs(num(i, j));
#ifdef DEBUG
    for (int i = 1;i <= n; i++, puts(""))
        for (int j = 1;j <= m; j++)
            write(deg[num(i, j)], '\t');
#endif
    for (int i = 1;i <= tp; i++) {
        int x = X[i], y = Y[i];
#ifdef DEBUG
        write(x, ' '), write(y);
#endif
        p[++cnt] = (node) {dfn[x], dfn[y], dfn[y] + siz[y] - 1, 1};
        p[++cnt] = (node) {dfn[x] + siz[x], dfn[y], dfn[y] + siz[y] - 1, -1};
    }
    return solve(), write(ans), 0;
}