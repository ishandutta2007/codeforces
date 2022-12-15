
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

const int P = 998244353;
const int N = 200050;
int h[N], ne[N<<1], to[N<<1], tot, n, k, lim;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
ll dp[N], inv[N], fac, ans;
int siz[N], L[N], R[N], H[N], F[N], tp;

namespace NTT {
	const int P = 998244353;
	int A[N<<2], B[N<<2], C[N<<2], D[N<<2]; ll E[N];
	int r[N], lim = 1; 
	
	inline int add(int x, int y) { return x + y >= P ? x + y - P : x + y; }
	
	void dft(int *A) {
		for (int i = 1;i < lim; i++)
			if (r[i] > i) swap(A[i], A[r[i]]);
		for (int i = 1;i < lim; i <<= 1) {
			for (int j = 0;j < lim; j += (i << 1)) {
				int *f = A + j, *g = f + i; ll *e = E + i;
				for (int k = 0;k < i; k++) {
					int x = f[k], y = e[k] * g[k] % P;
					f[k] = add(x, y), g[k] = add(x , P - y);
				}
			}
		}
	}
	ll fpw(ll x, ll mi) {
		ll res = 1;
		for (; mi; mi >>= 1, x = x * x % P)
			if (mi & 1) res = res * x % P;
		return res;
	}
	void idft(int *A) {
		dft(A), reverse(A + 1, A + lim);
		ll inv = fpw(lim, P - 2);
		for (int i = 0;i < lim; i++) A[i] = inv * A[i] % P;
	}
	void init(void) {
		while (lim <= 2 * n) lim <<= 1;
		int len = lim >> 1;
		for (int i = 1;i < lim; i++)
			r[i] = r[i >> 1] >> 1 | ((i & 1) ? len : 0);
		E[1] = 1;
		for (int i = 2;i < lim; i <<= 1) {
			ll *e0 = E + i / 2, *e1 = E + i;
			ll w = fpw(3, (P - 1) / (i << 1));
			for (int j = 0;j < i; j += 2) 
				e1[j] = e0[j>>1], e1[j+1] = e1[j] * w % P;
		}
	}
	void Mul(int x, int y) {
		int n = R[x] - L[x], m = R[y] - L[y];
		for (int i = 0;i <= n; i++) A[i] = H[L[x] + i], B[i] = F[L[x] + i];
		for (int i = 0;i <= m; i++) C[i] = H[L[y] + i], D[i] = F[L[y] + i];
		lim = 1; while (lim <= (n + m)) lim <<= 1;
		int len = lim >> 1;
		for (int i = 1;i < lim; i++) 
			r[i] = (r[i>>1]>>1) | ((i & 1) ? len : 0);
		for (int i = n + 1;i <= lim; i++) A[i] = B[i] = 0;
		for (int i = m + 1;i <= lim; i++) C[i] = D[i] = 0;
		dft(A), dft(B), dft(C), dft(D);
		for (int i = 0;i < lim; i++) {
			int a = A[i], b = B[i], c = C[i], d = D[i];
			A[i] = 1ll * a * c % P, B[i] = 1ll * b * c % P, D[i] = 1ll * d * a % P;
		}
		idft(A), idft(B), idft(D);
		for (int i = 0;i <= n + m; i++) H[L[x] + i] = A[i];
		for (int i = 0;i <= n + m; i++) F[L[x] + i] = add(B[i], D[i]);
		L[++tp] = L[x], R[tp] = L[x] + n + m;
	}
}

using NTT::dft;
using NTT::idft;
using NTT::init;
using NTT::Mul;

void dfs1(int x, int fa) {
	siz[x] = 1;  ll Mul = 0;
	int t = -1, deg = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x), siz[x] += siz[y];
		ans = (ans + dp[y] * Mul) % P, Mul = (Mul + dp[y]) % P;
	}
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue; deg++;
		H[++t] = 1, L[deg] = t, F[t] = dp[y], H[++t] = siz[y], R[deg] = t, F[t] = 0;
	}
	if (!deg) return dp[x] = 1, void();
	t = deg;
	while (t > 1) { 
		tp = 0; 
		for (int i = 1;i < t; i += 2) NTT::Mul(i, i + 1); 
		if (t & 1) L[++tp] = L[t], R[tp] = R[t]; 
		t = tp;  
	}
	dp[x] = Mul;
	for (int j = 0;j <= min(deg, k); j++) 
		dp[x] = (dp[x] + fac * inv[k-j] % P * H[j]) % P;
//	write(x, ' '), write(dp[x]);
	ll res = n - siz[x];
	for (int j = min(k, deg);j >= 1; j--)
		F[j] = (F[j] + res * F[j-1]) % P;
//	write(x, '\t');
//	for (int j = 0;j <= deg; j++) write(F[j], ' '); 
//	puts("");
	for (int j = 0;j <= min(k, deg); j++) 
		ans = (ans + fac * inv[k-j] % P * F[j]) % P;
//	memset(F, 0, deg * 4 + 20);
//	memset(H, 0, deg * 4 + 20);
}

int main() {
//	freopen ("hs.out","w",stdout);
	read(n), read(k);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	if (k == 1) return write((ll)n * (n - 1) / 2 % P), 0; 
	init(), inv[0] = inv[1] = fac = 1;
	for (int i = 2;i <= max(n, k); i++)
		inv[i] = inv[P % i] * (P - P / i) % P;
	for (int i = 1;i <= max(n, k); i++)
		inv[i] = inv[i-1] * inv[i] % P;
	for (int i = 1;i <= k; i++) fac = fac * i % P;
	dfs1(1, 0), write(ans);
	return 0;
}



/*

6 3
1 2
1 3
1 4
2 5
3 6

*/