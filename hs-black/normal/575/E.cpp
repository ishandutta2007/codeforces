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

%:include <cmath>
const int N = 200005;
const int lim = 1e5;
struct P {
    ll x, y;
}s1[N], s2[N], p1, p2, p3;
int up[N], dw[N], t1, t2, n;
#define ld long double
ld ans;
ll Cross(P a, P b, P c) {
    b.x -= a.x, b.y -= a.y;
    c.x -= a.x, c.y -= a.y;
    return b.x * c.y - b.y * c.x;
}
ld Dis(P a, P b) {
    ll x = a.x - b.x, y = a.y - b.y;
    return sqrt(x * x + y * y);
}
void refresh(P a, P b, P c) {
    /* write(a.x, ' ' ), write(a.y); */
    double len = Dis(a, b) * Dis(b, c) * Dis(c, a);
    double res = fabs(len / (2.0 * Cross(a, b, c)));
    if (res > ans) ans = res, p1 = a, p2 = b, p3 = c;
}

inline void Add(int x, int y) {
    Mx(x, 0), Mn(x, lim);
    Mx(y, 0), Mn(y, lim);
    if (up[x] == -1) return up[x] = dw[x] = y, void();
    Mx(up[x], y), Mn(dw[x], y);
}

int main() {
    read(n);
    memset(up, -1, sizeof(up));
    memset(dw, -1, sizeof(dw));
    for (int i = 1, x, y, v;i <= n; i++) {
        read(x), read(y), read(v);
        int t = max(0, x - v);
        Add(t, y + x - t - v);
        Add(t, y - x + t + v);
        t = max(0, y - v);
        Add(x + y - t - v, t);
        Add(x - y + t + v, t);
        t = min(lim, x + v);
        Add(t, y + t - x - v);
        Add(t, y - t + x + v);
        t = min(lim, y + v);
        Add(x + t - y - v, t);
        Add(x - t + y + v, t);
    }
    auto CCF = [&](int x, int y) {
        P t = (P) {x, y};
        while (t1 >= 2 && Cross(s1[t1-1], s1[t1], t) >= 0) t1--;
        s1[++t1] = t;
    };
    auto ccf = [&](int x, int y) {
        P t = (P) {x, y};
        while (t2 >= 2 && Cross(s2[t2-1], s2[t2], t) <= 0) t2--;
        s2[++t2] = t;
    };
    /* write(up[2], ' '), write(dw[2]); */
    for (int i = 0;i <= lim; i++) {
        if (up[i] == -1) continue;
        CCF(i, up[i]), ccf(i, dw[i]);
    }
    if (s2[t2].y == s1[t1].y) t2--;
    for (int i = t2;i >= 1; i--) s1[++t1] = s2[i]; 
    if (s2[1].y != s1[1].y) s1[++t1] = s1[1];
    s1[++t1] = s1[2];
    for (int i = 1;i <= t1 - 2; i++) refresh(s1[i], s1[i+1], s1[i+2]);
    /* printf ("%.6Lf\n", ans); */
    write(p1.x, ' '), write(p1.y);
    write(p2.x, ' '), write(p2.y);
    write(p3.x, ' '), write(p3.y);
    return 0;
}