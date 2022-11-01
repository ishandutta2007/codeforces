#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

typedef long long ll;

const int p = 998244353, inv2 = 499122177;

int n, m, cnt;
int mid;

ll b[maxn];
ll x;

int f[50][maxn], g[maxn], h[maxn];
int pcnt[maxn];
int ans[maxn];

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	} 
	return ans;
}

void dfs1(int i, int val){
	if(i > mid){
		++g[val];
		return;
	}
	dfs1(i + 1, val);
	if(b[i]) dfs1(i + 1, val ^ b[i]);
}

void dfs2(int i, ll val){
	if(i > m){
		++f[pcnt[(int)(val >> (mid + 1))]][(int)(val & ((1 << (mid + 1)) - 1))];
		return;
	}
	dfs2(i + 1, val);
	if(b[i]) dfs2(i + 1, val ^ b[i]);
}

inline void XOR(int *a, int lim, int type){
	for(register int mid = 1;mid < lim;mid <<= 1){
		for(register int i = mid << 1, j = 0;j < lim;j += i){
			for(register int k = 0;k < mid;k++){
				a[j + k] += a[j + k + mid];
				if(a[j + k] >= p) a[j + k] -= p;
				a[j + k + mid] = a[j + k] - a[j + k + mid] - a[j + k + mid];
				if(a[j + k + mid] >= p) a[j + k + mid] -= p;
				else while(a[j + k + mid] < 0) a[j + k + mid] += p;
				if(type == -1) a[j + k] = 1ll * a[j + k] * inv2 % p, a[j + k + mid] = 1ll * a[j + k + mid] * inv2 % p;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &x);
		int k = m;
		for(ll j = 1ll << m;j;j >>= 1, k--){
			if(x & j){
				if(b[k]) x ^= b[k];
				else{
					b[k] = x, ++cnt;
					break; 
				}
			} 
		}
	}
	mid = (m + 1) >> 1;
	int lim = 1 << (mid + 1);
	for(int i = 1;i < lim;i++) pcnt[i] = pcnt[i >> 1] + (i & 1);//debug:<lim 1 << m lim-1 
	dfs1(0, 0), dfs2(mid + 1, 0);
	for(int i = 0;i <= mid;i++){
		memcpy(h, g, sizeof(g));
		XOR(f[i], lim, 1), XOR(h, lim, 1);
		for(int j = 0;j < lim;j++) h[j] = 1ll * h[j] * f[i][j] % p;
		XOR(h, lim, -1);
		for(int j = 0;j < lim;j++){
			ans[pcnt[j] + i] += h[j];
			if(ans[pcnt[j] + i] >= p) ans[pcnt[j] + i] -= p;
		}
	}
	for(int i = 0;i <= m;i++) printf("%d ", 1ll * ans[i] * fpow(2, n - cnt) % p);
}