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

const int N = 5005;
int f[N][N], ans, m, n;
char s[N], t[N];
int main() {
    read(n), read(m);
    scanf ("%s", s + 1), scanf ("%s", t + 1);
    for (int i = 1;i <= n; i++) 
        for (int j = 1;j <= m; j++) {
            if (s[i] == t[j]) Mx(f[i][j], f[i-1][j-1] + 2);
            Mx(f[i][j], f[i-1][j] - 1), Mx(f[i][j], f[i][j-1] - 1);
            Mx(ans, f[i][j]);
        }
    write(ans);
    return 0;
}