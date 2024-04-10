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

int sum[maxn], inv[maxn];
inline int C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int n, m;
int a[maxn], b[maxn], c[maxn];
int f[45][maxn];
int u[25], v[25];
int ans;
bool vis[maxn];

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &a[i], &b[i]);
		c[a[i]]++, c[b[i] + 1]--;
	}
	for(int i = 1;i <= n;i++) c[i] += c[i - 1];
	for(int j = 0;j <= 2 * m;j++){
		for(int i = 1;i <= n;i++){
			f[j][i] = (f[j][i - 1] + C(c[i] - j, i - j)) % p;
		}
	}
	for(int i = 1;i <= m;i++) scanf("%d%d", &u[i], &v[i]);
	for(int i = (1 << m) - 1;~i;i--){
		int l = 1, r = n, cnt = 0;
		for(int j = 1, k = 1;j <= m;j++, k <<= 1){
			if(!(i & k)) continue;
			if(!vis[u[j]]){
				vis[u[j]] = true, cnt++;
				l = max(l, a[u[j]]), r = min(r, b[u[j]]);
			}
			if(!vis[v[j]]){
				vis[v[j]] = true, cnt++;
				l = max(l, a[v[j]]), r = min(r, b[v[j]]);
			}
		}
		if(l <= r){//debug: 
			int sum = (f[cnt][r] + p - f[cnt][l - 1]) % p;
			if(__builtin_popcount(i) & 1) ans = (ans + p - sum) % p;
			else ans = (ans + sum) % p;
		}
		for(int j = 1, k = 1;j <= m;j++, k <<= 1){
			if(!(i & k)) continue;
			vis[u[j]] = vis[v[j]] = false;
		}
	}
	printf("%d", ans);
}