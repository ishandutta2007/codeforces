#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	}
	return ans;
}

const int G = 3, invG = fpow(G, p - 2);
int pos[maxn], prt[2][30]; 

inline void init(){
	for(int i = 1, j = 2;i <= 23;i++, j <<= 1) prt[0][i] = fpow(G, (p - 1) / j);
	for(int i = 1, j = 2;i <= 23;i++, j <<= 1) prt[1][i] = fpow(invG, (p - 1) / j);
}

inline void NTT(int *a, int lim, int type){
	for(register int i = 0;i < lim;i++){
		pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
		if(i < pos[i]) swap(a[i], a[pos[i]]);
	}
	for(register int mid = 1, pw = 1;mid < lim;mid <<= 1, pw++){
		int wn = prt[type == -1][pw];
		for(register int i = mid << 1, j = 0;j < lim;j += i){
			int w = 1;
			for(register int k = 0;k < mid;k++, w = 1ll * w * wn % p){
				int x = a[j + k], y = 1ll * w * a[j + k + mid] % p;
				a[j + k] = x + y;
                if(a[j + k] >= p) a[j + k] -= p;
				a[j + k + mid] = x - y + p;
                if(a[j + k + mid] >= p) a[j + k + mid] -= p;
			} 
		}
	}
	if(type == -1){
		int invlim = fpow(lim, p - 2);
		for(register int i = 0;i < lim;i++) a[i] = 1ll * a[i] * invlim % p;
	}
} 

int sum[maxn], inv[maxn];
inline int C(int n, int m){
	if(n < m || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int n, m;
int a, b;
int f[maxn], g[maxn];

int main(){
	init();
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	scanf("%d", &n);
	m = 1, f[1] = 1;
	while(n--){
		scanf("%d%d", &a, &b);
		int lim = 1;
		while(lim <= (m + 5) * 2) lim <<= 1;
		for(int i = 0;i <= (m + 5) * 2;i++) g[i] = C(a + b, b + i - (m + 5));
		for(int i = (m + 5) * 2 + 1;i < lim;i++) g[i] = 0;
		NTT(f, lim, 1), NTT(g, lim, 1);
		for(int i = 0;i < lim;i++) f[i] = 1ll * f[i] * g[i] % p;
		NTT(f, lim, -1);
		for(int i = 0;i < lim;i++){
			if(i >= 1 && i <= m + a - b) f[i] = f[i + m + 5];
			else f[i] = 0;
		}
		m += a - b;
	}
	int ans = 0;
	for(int i = 1;i <= m;i++) ans = (ans + f[i]) % p;
	printf("%d", ans);
}