#include <bits/stdc++.h>
#define maxn 300086

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

int n, k;
int inv[maxn];
int a[maxn], b[maxn];

int main(){
	init();
	scanf("%d%d", &n, &k);
	inv[0] = inv[1] = 1;for(int i = 2;i <= k;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 1;i <= k;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	for(int i = 0;i <= k;i++) a[i] = i & 1 ? (p - inv[i]) % p : inv[i];
	for(int i = 0;i <= k;i++) b[i] = 1ll * fpow(i, k) * inv[i] % p;
	int lim = 1;
	while(lim <= 2 * k) lim <<= 1;
	NTT(a, lim, 1), NTT(b, lim, 1);
	for(int i = 0;i < lim;i++) a[i] = 1ll * a[i] * b[i] % p;
	NTT(a, lim, -1);
	int ans = 0, sum = 1;
	for(int i = 0;i <= min(n, k);i++){
		ans = (ans + 1ll * sum * a[i] % p * fpow((n + 1) % p, n - i)) % p;
		sum = 1ll * sum * (n - i) % p;
	}
	printf("%d", ans);
}