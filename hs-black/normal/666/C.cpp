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

const int P = 1e9 + 7;
const int N = 100050;
ll fac[N], inv[N], m25[N], m26[N], im26[N];
ll fpw(ll x, ll mi) {
    ll res = 1;
    for (; mi; mi >>= 1,x = x * x % P)
        if (mi & 1) res = res * x % P;
    return res;
}

void prework(void) {
    int lim = 100000;
    fac[0] = fac[1] = 1;
    for (int i = 2;i <= lim; i++) fac[i] = fac[i-1] * i % P;
    inv[lim] = fpw(fac[lim], P - 2);
    for (int i = lim - 1;i >= 0; i--) inv[i] = inv[i+1] * (i + 1) % P;
    m25[0] = 1, m26[0] = 1; ll inv = fpw(26, P - 2);
    im26[0] = 1;
    for (int i = 1;i <= lim; i++)
        m25[i] = m25[i-1] * 25 % P, m26[i] = m26[i-1] * 26 % P, im26[i] = im26[i-1] * inv % P;
    /* for (int i = 1;i <= 20; i++) write(im26[i], ' '); */
}

ll C(ll n, ll m) {
    return fac[n] * inv[m] % P * inv[n-m] % P;
}

int len, L, q;
char s[N]; int op;

int vis[N], cnt;
int st[505][N];
int Calc(int x) {
    const int lim = 1e5;
    if (vis[x]) return vis[x];
    vis[x] = ++cnt;
    for (int i = x;i <= lim; i++)
        st[cnt][i] = (st[cnt][i-1] + m25[i-x] * C(i - 1, x - 1) % P * im26[i]) % P;
    return cnt;
}

int main() {
    read(q); scanf ("%s", s + 1); len = strlen(s + 1);
    prework();
    while (q--) {
        read(op);
        if (op == 1) 
            scanf ("%s", s + 1), len = strlen(s + 1);
        else {
            read(L); int t = Calc(len);
            write(1ll * st[t][L] * m26[L] % P);
        }
    }
    return 0;
}