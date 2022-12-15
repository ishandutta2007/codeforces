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

const int N = 305;
int f[10][N][N], t[N][N], g[N][N], m, n;
int main() {
    read(n), read(m);
    memset(f, -0x3f, sizeof(f));
    memset(g, -0x3f, sizeof(g));
    for (int i = 1, x, y, w;i <= m; i++) {
        read(x), read(y);
        read(w), Mx(f[0][x][y], w);
        read(w), Mx(f[0][y][x], w);
    }
    for (int i = 1;i <= n; i++) f[0][i][i] = g[i][i] = 0;
    for (int s = 1;s <= 9; s++) 
        for (int k = 1;k <= n; k++)
            for (int i = 1;i <= n; i++)
                for (int j = 1;j <= n; j++)
                    Mx(f[s][i][j], f[s-1][i][k] + f[s-1][k][j]);
    int ans = 0;
    for (int s = 9;s >= 0; s--) {
        memset(t, -0x3f, sizeof(t));
        for (int k = 1;k <= n; k++)
            for (int i = 1;i <= n; i++)
                for (int j = 1;j <= n; j++)
                    Mx(t[i][j], g[i][k] + f[s][k][j]);
        bool fl = 0;
        for (int i = 1;i <= n; i++) 
            if (t[i][i] > 0) { fl = 1; break; }
        if (fl) continue;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                g[i][j] = t[i][j];
        ans += 1 << s;
    }
    write(ans >= n ? 0 : ans + 1);
    return 0;
}