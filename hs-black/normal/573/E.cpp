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

const int N = 300500;
ll val[N], add[N], ad[N], a[N], ans;
int ls[N], rs[N], cnt, rnd[N], siz[N];
int neq(ll v) {
    cnt++, rnd[cnt] = rand(), val[cnt] = v;
    siz[cnt] = 1; return cnt;
}

void Tag(int x, ll A, ll B) { val[x] += A + B * siz[ls[x]], add[x] += A, ad[x] += B; }

void spread(int x) {
    if (ls[x]) Tag(ls[x], add[x], ad[x]);
    if (rs[x]) Tag(rs[x], add[x] + ad[x] * (siz[ls[x]] + 1), ad[x]);
    ad[x] = add[x] = 0;
}

inline void update(int x) { siz[x] = siz[ls[x]] + siz[rs[x]] + 1; }

void split(int nw, int k, int &x, int &y) {
    if (!nw) return x = y = 0, void();
    spread(nw);
    if (k <= siz[ls[nw]]) y = nw, split(ls[y], k, x, ls[y]);
    else x = nw, split(rs[x], k - siz[ls[nw]] - 1, rs[x], y);
    update(nw);
}

int merge(int x, int y) {
    if (!x || !y) return x | y; spread(x), spread(y);
    if (rnd[x] < rnd[y]) return rs[x] = merge(rs[x], y), update(x), x;
    return ls[y] = merge(x, ls[y]), update(y), y;
}

int rt, n, x, y;
ll getv(int k) {
    int x = rt;
    while (x) {
        spread(x);
        if (siz[ls[x]] >= k) x = ls[x];
        else if (siz[ls[x]] + 1 == k) return val[x];
        else k -= siz[ls[x]] + 1, x = rs[x];
    }
    return 0;
}

void get_ans(int x) {
    spread(x);
    if (ls[x]) get_ans(ls[x]);
    if (rs[x]) get_ans(rs[x]);
    Mx(ans, val[x]);
}

int main() {
    read(n);
    for (int i = 1;i <= n; i++) read(a[i]);
    for (int i = 1;i <= n; i++) {
        int l = 1, r = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (getv(mid) <= getv(mid - 1) + a[i] * mid) r = mid - 1;
            else l = mid + 1;
        }
//        write(l);
        ll t = getv(l - 1);
        split(rt, l - 1, x, y);
        y = merge(neq(t), y), Tag(y, a[i] * l, a[i]);
        rt = merge(x, y);
    }
    get_ans(rt), write(ans);
    return 0;
}

/*

8  
2 5 -2 2 -3 -2 3 5

*/