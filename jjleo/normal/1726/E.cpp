#include <bits/stdc++.h>
#define maxn 11000086

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
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
	for(int i = 0;i < lim;i++) if(i < pos[i]) swap(a[i], a[pos[i]]);
	for(int mid = 1, pw = 1;mid < lim;mid <<= 1, pw++){
		int wn = prt[type == -1][pw];
		for(int i = mid << 1, j = 0;j < lim;j += i){
			int w = 1;
			for(int k = 0;k < mid;k++, w = 1ll * w * wn % p){
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
		for(int i = 0;i < lim;i++) a[i] = 1ll * a[i] * invlim % p;
	}
} 

int sum[maxn], inv[maxn];
inline int C(int n, int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int t, n;
//int a[maxn], b[maxn];
//bool vis[maxn];

int f[maxn], g[maxn];
int pw[maxn];


int main(){
	init();
	n = 3e5;
	pw[0] = 1;for(int i = 1;i <= n;i++) pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = 1;for(int i = 1;i <= n;i++) inv[i] = 1ll * inv[i - 1] * fpow(i, p - 2) % p;
	f[0] = 1;
	int fac = 1;
	for(int i = 1;i * 2 <= n;i++){
		fac = 1ll * fac * (i * 2 - 1) % p;
		f[i * 2] = 1ll * fac * inv[i * 2] % p;
	}
	for(int i = 0;i <= n;i++) g[i] = inv[i];
	int lim = 1;
	while(lim <= n * 2) lim <<= 1;
	for(int i = 0;i < lim;i++) pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
	NTT(f, lim, 1), NTT(g, lim, 1);
	for(int i = 0;i < lim;i++) f[i] = 1ll * f[i] * g[i] % p;
	NTT(f, lim, -1);
	for(int i = 0;i <= n;i++) f[i] = 1ll * f[i] * sum[i] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int ans = f[n], fac = 1;
		for(int i = 1;i * 4 <= n;i++){
			fac = 1ll * fac * (i * 2 - 1) % p;
			ans = (ans + 1ll * C(n - 1 - i * 2 + 1, i * 2) * fac % p * f[n - i * 4] % p * pw[i]) % p;
		}
		printf("%d\n", ans);
//		
//		int val = 0;
//		for(int i = 1;i <= n;i++) a[i] = i;
//		do{
//			for(int i = 1;i <= n;i++) b[a[i]] = i;
//			bool tag = false;
//			for(int i = 1;i <= n;i++) if(abs(a[i] - b[i]) > 1) tag = true;
//			val += !tag;
//			if(!tag){
//				for(int i = 1;i <= n;i++) vis[i] = false;
//				for(int i = 1;i <= n;i++) if(!vis[i]){
//					int x = i;
//					int cnt = 0;
//					while(!vis[x]){
//						cnt++;
//						vis[x] = true;
//						x = a[x];
//					}
//					printf("%d ", cnt);
//				}
//				puts("");
//				for(int i = 1;i <= n;i++) printf("%d ", a[i]);
//				puts("");
//			}
//		}while(next_permutation(a + 1, a + 1 + n));
//		printf("%d\n", val);
	}
}