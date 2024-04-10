
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

const int N = 2005;
const int P = 998244353;
int a[N], b[N], c[N], cnt, n;
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

ll C[N], f[N], inv[N], Inv;
int main() {
	read(n), Inv = 1;
	for (int i = 1;i <= n; i++) {
		read(a[i]), read(b[i]), a[i] += 2, b[i] += 3;
		Inv = Inv * (b[i] - a[i]) % P, c[++cnt] = a[i], c[++cnt] = b[i];
	}
	sort(c + 1, c + cnt + 1), cnt = unique(c + 1, c + cnt + 1) - c - 1;
	inv[0] = inv[1] = 1;
	for (int i = 2;i <= n; i++) 
		inv[i] = inv[P % i] * (P - P / i) % P;
	for (int i = 1;i <= n; i++) {
		a[i] = lower_bound(c + 1, c + cnt + 1, a[i]) - c;
		b[i] = lower_bound(c + 1, c + cnt + 1, b[i]) - c;
	}
	f[n+1] = C[0] = 1;
	for (int i = 1;i < cnt; i++) {
		int len = c[i+1] - c[i];
		// C(len + tp - 1, tp)
		for (int j = 1;j <= n; j++)
			C[j] = C[j-1] * inv[j] % P * (len + j - 1) % P;
		for (int j = 1;j <= n; j++) {
			if (a[j] > i || b[j] <= i) continue;
			for (int k = j + 1;k <= n + 1; k++) {
				f[j] = (f[j] + f[k] * C[k - j]) % P;
				if (a[k] > i || b[k] <= i) break;
			}
		}
	}
	write(f[1] * fpw(Inv, P - 2) % P);
	return 0;
}