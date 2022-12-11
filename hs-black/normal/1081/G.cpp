
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

const int N = 500005;
ll inv[N]; int n, k, P; ll L1, L2, C1, C2;
ll calc(int L1, int L2) {
	ll ans = 0;
	for (int i = 1;i <= L1; i++)
		ans = ans + inv[i + L2] - inv[i];
	return (ans % P + P) % P;
}

void solve(int l, int r, int k) {
	if (k <= 1 || l == r) {
		int len = r - l + 1;
		(!L1 || len == L1) ? L1 = len : !L2 && (L2 = len);
		len == L1 ? C1++ : C2++;
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid, k - 1), solve(mid + 1, r, k - 1);
}

int main() {
	read(n), read(k), read(P);
	inv[0] = inv[1] = 1; ll inv2 = (P + 1) >> 1;
	for (int i = 2;i <= n; i++)
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= n; i++) inv[i] = inv[i-1] + inv[i] % P;
	solve(1, n, k);
	ll ans = (ll)n * (n - 1) % P * inv2 % P * inv2 % P;
	ans = (ans - C1 * (C1 - 1) / 2 % P * calc(L1, L1) - C2 * (C2 - 1) / 2 % P * calc(L2, L2) % P - C1 * C2 % P * calc(L1, L2)) % P;
	write((ans % P + P) % P);
	return 0;
}