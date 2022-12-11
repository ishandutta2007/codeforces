/*
  ?
 | _ _|
  ?_x ?
   /  |
  /   ?
 | |||
 | ()_)
 ?
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

const int N = 1000500;
const int P = 1e9 + 7;
ll sum[N], Sum[N], n;
ll x[N], y[N], sx[N], sy[N];
inline ll add(ll x, ll y) { return x + y >= P ? x + y - P : x + y; }
inline ll cross(int a, int b) { return (x[a] * y[b] - y[a] * x[b]) % P; }
inline ll Cross(int a, int b) { return x[a] * y[b] - y[a] * x[b]; }
inline ll get(int l, int r) { return sum[r-1] - sum[l-1] + cross(l, r); }
inline ll Get(int l, int r) { 
	ll t = Sum[r-1] - Sum[l-1] - sum[l-1] * (r - l);
	t = (t + x[l] * (sy[r] - sy[l]) - y[l] * (sx[r] - sx[l])) % P;
    return t;
}

const int inv2 = (P + 1) >> 1;
int main() {
    read(n);
    for (int i = 1;i <= n; i++) 
        read(x[i]), read(y[i]), x[i + n] = x[i], y[i + n] = y[i];
    for (int i = 1;i <= 2 * n; i++) 
		sx[i] = add(sx[i-1], x[i]), sy[i] = add(sy[i-1], y[i]),
		sx[i] = add(sx[i], P), sy[i] = add(sy[i], P);
    for (int i = 1;i <= 2 * n; i++) {
        sum[i] = (cross(i + 1, i) + sum[i-1]) % P;
        Sum[i] = add(Sum[i-1], sum[i] % P);
    }
    int p = 2; ll ans = 0, all = get(1, n + 1);
    ll tall = 0, S = Cross(2, 1);
    for (int i = 1;i <= n; i++) tall += Cross(i + 1, i);
    for (int i = 1;i <= n; i++) {
        while ((S + Cross(p + 1, p) + Cross(i, p + 1)) <= tall / 2) 
			S += Cross(p + 1, p), p++;
        ll s1 = add(P, Get(i, p) % P), s2 = add(add(Get(i, i + n - 2) % P, P), P - s1);
        ll t = -all * (n - 3 - 2 * (p - i - 1));
        ans = (ans + t - 2 * s1 + 2 * s2) % P, S -= Cross(i + 1, i);
    }
     
    write((ans * inv2 % P + P) % P);
    return 0;
}