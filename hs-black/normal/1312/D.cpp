#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int P = 998244353;
ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P;
		mi >>= 1;
	}
	return res;
}
const int N = 300500;
const int Maxn = 300000;
ll jie[N], inv[N];
void init(void) {
	jie[0] = jie[1] = inv[0] = inv[1] = 1;
	for (int i = 2;i <= Maxn; i++)
		jie[i] = jie[i-1] * i % P,
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= Maxn; i++)
		inv[i] = inv[i-1] * inv[i] % P; 
}

ll C(ll n, ll m) {
	return jie[n] * inv[m] % P * inv[n-m] % P;
}

int main() {
	init();
	int n, m; read(n), read(m);
	if (n == 2) return puts("0");
	ll ans = fpw(2, n - 3);
	printf ("%lld\n", ans * C(m, n - 1) % P * (n - 2) % P);
	return 0;
}
/*

n ,m - n - 1

*/