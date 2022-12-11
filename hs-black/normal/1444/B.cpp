
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

const int N = 400050;
const int P = 998244353;
ll inv[N], fac[N], mi[N], a[N], n;
ll C(int n, int m) {
	return fac[n] * inv[m] % P * inv[n-m] % P;
}

int main() {
	read(n);
	for (int i = 1;i <= 2 * n; i++) read(a[i]);
	sort(a + 1, a + 2 * n + 1);
	inv[0] = inv[1] = fac[0] = fac[1] = 1;
	for (int i = 2;i <= 2 * n; i++) inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= 2 * n; i++) inv[i] = inv[i-1] * inv[i] % P, fac[i] = fac[i-1] * i % P;
	mi[0] = 1;
	for (int i = 1;i <= n; i++) mi[i] = mi[i-1] * 2 % P;
	ll P1 = 0, P2 = 0;
	for (int i = 1;i <= n; i++) P1 = (P1 + a[i]) % P;
	for (int i = n + 1;i <= 2 * n; i++) P2 = (P2 + a[i]) % P;
	ll ans = 2 * (P2 - P1 + P) % P;
	write(ans * C(2 * n - 1, n - 1) % P);
	return 0; 
}