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

#include <bitset>
const int N = 100500;
bitset<7005> st[N], bit[7005], Mu[7005];
int mu[N], e[N], prime[N], tot, n, q;
int main() {
    read(n), read(q);
    mu[1] = 1;
    for (int i = 2;i <= 7000; i++) {
        if (!e[i]) e[i] = prime[++tot] = i, mu[i] = -1;
        for (int j = 1;j <= tot && prime[j] * i <= 7000; j++) {
            int t = prime[j] * i; e[t] = prime[j];
            if (prime[j] == e[i]) break; mu[t] = -mu[i];
        }
    }
    for (int i = 1;i <= 7000; i++)
        for (int j = i;j <= 7000; j += i) {
            if (mu[j / i]) Mu[i][j] = 1;
            bit[j][i] = i;
        }
    for (int i = 1;i <= q; i++) {
        int op, x, y, z, v; read(op), read(x);
        if (op == 1) read(v), st[x] = bit[v];
        else if (op == 2) read(y), read(z), st[x] = st[y] ^ st[z];
        else if (op == 3) read(y), read(z), st[x] = st[y] & st[z];
        else read(v), putchar(((st[x] & Mu[v]).count() & 1) | 48);
    }
    return 0;
}