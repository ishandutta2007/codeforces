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

const int N = 705;
const int P = 1e9 + 7;
ll f[N][N][11][2], sum[N], ans, n;
char s[N];
inline void add(ll &x, ll y) { 
    x += y, x >= P && (x -= P), x >= P && (x -= P);
}
int main() {
    scanf ("%s", s + 1); n = strlen(s + 1);
    sum[0] = 1;
    for (int i = 1;i <= n; i++) sum[i] = (sum[i-1] * 10 + 1) % P;
    for (int i = 0;i <= 9; i++) f[n+1][0][i][0] = 1;
    for (int i = n;i >= 1; i--) {
        int c = s[i] - '0';
        for (int j = 0;j <= n - i; j++)
            for (int k = 0;k <= 9; k++)
                for (int p = 0;p <= 9; p++) {
                    ll &x = f[i][j + (p >= k)][k][0], &y = f[i][j + (p >= k)][k][1];
                    if (p < c) add(x, f[i+1][j][k][0] + f[i+1][j][k][1]);
                    else if (p == c) add(x, f[i+1][j][k][0]), add(y, f[i+1][j][k][1]);
                    else add(y, f[i+1][j][k][0] + f[i+1][j][k][1]);
                }
    }
    for (int i = 1;i <= 9; i++) 
        for (int j = 1;j <= n; j++)
            add(ans, f[1][j][i][0] * sum[j-1] % P);
    write(ans);
    return 0;
}