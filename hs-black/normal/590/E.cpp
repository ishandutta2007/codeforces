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

const int S = 10000500;
const int N = 1505;
int en[S], f[S], to[S], ch[S][2], fr[S], jzp[N], cnt;
void insert(char *s, int k) {
    int n = strlen(s + 1), p = 0;
    for (int i = 1;i <= n; i++) {
        int c = s[i] - 'a';
        if (!ch[p][c]) ch[p][c] = ++cnt, fr[cnt] = p;
        p = ch[p][c];
    }
    en[p] = k, jzp[k] = p;
}

int ed[N][N], match[N], vis[N], tim;
int tag[N], ans, n;
void build(void) {
    /* write(cnt); */
    queue<int> q;
    if (ch[0][0]) q.push(ch[0][0]);
    if (ch[0][1]) q.push(ch[0][1]);
    while (q.size()) {
        int x = q.front(); q.pop();
        if (!to[x]) to[x] = to[f[x]];
        /* write(x, ' '), write(to[x], ' '), write(en[x]); */
        /* write(x, ' '), write(ch[x][0], ' '), write(ch[x][1], ' '), write(f[x]); */
        if (en[x]) to[x] = en[x];
        if (ch[x][0]) q.push(ch[x][0]), f[ch[x][0]] = ch[f[x]][0];
        else ch[x][0] = ch[f[x]][0];
        if (ch[x][1]) q.push(ch[x][1]), f[ch[x][1]] = ch[f[x]][1];
        else ch[x][1] = ch[f[x]][1];
    }
}

void work(void) {
    for (int i = 1;i <= n; i++) {
        for (int j = jzp[i]; j; j = fr[j]) {
            if (to[j]) ed[i][to[j]] = 1;
            if (to[f[j]]) ed[i][to[f[j]]] = 1;
        }
        ed[i][i] = 0;
    }
}

char s[S];
void Floyd(void) {
    for (int k = 1;k <= n; k++)
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                ed[i][j] |= ed[i][k] && ed[k][j];
}

int dfs(int x) {
    for (int y = 1;y <= n; y++) {
        if (!ed[x][y]) continue;
        if (vis[y] == tim) continue;
        vis[y] = tim;
        if (!match[y + n] || dfs(match[y + n])) {
            match[x] = y, match[y + n] = x;
            return 1;
        }
    }
    return 0;
}

void Tag(int x) {
    tag[x] = 1;
    for (int y = 1;y <= n; y++) {
        if (!ed[x][y]) continue;
        if (tag[y + n]) continue;
        tag[y + n] = 1, Tag(match[y + n]);
    }
}

#define debug puts("JzpAkIOI")
int main() {
    read(n);
    for (int i = 1;i <= n; i++) 
        scanf ("%s", s + 1), insert(s, i);
    /* debug; */
    build(), work(), Floyd();
    /* debug; */
    /* for (int i = 1;i <= n; i++, puts("")) */
    /*     for (int j = 1;j <= n; j++) */
    /*         write(ed[i][j], ' '); */
    for (int i = 1;i <= n; i++) tim++, ans += dfs(i);
    for (int i = 1;i <= n; i++) if (!match[i]) Tag(i);
    write(n - ans);
    for (int i = 1;i <= n; i++)
        if (tag[i] && !tag[i+n]) write(i, ' ');
    return 0;
}