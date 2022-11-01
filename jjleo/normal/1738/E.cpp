#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

const int p = 998244353;

int t, n;
int a[maxn];
ll f[maxn], g[maxn];
int b[maxn];

void add(int x, int y){
	for(;x;x -= x & -x) b[x] = (b[x] + y) % p;
}

int query(int x){
	int sum = 0;
	for(;x <= n;x += x & -x) sum = (sum + b[x]) % p;
	return sum;
}

int sum[maxn], inv[maxn];

int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i - 1] * inv[i] % p;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = 0;
		for(int i = 1;i <= n;i++) f[i] = f[i - 1] + a[i];
		g[n + 1] = 0;for(int i = n;i;i--) g[i] = g[i + 1] + a[i];
		map<ll, vector<int> > mp;
		for(int i = n;i;i--) mp[g[i]].push_back(i);
		int ans = 1;
		for(int i = 1;i <= n;i++) if(mp.count(f[i])){
			int j = i;
			while(j + 1 <= n && f[j + 1] == f[i]) j++;
			int l = mp[f[i]].back(), r = mp[f[i]][0];
			if(l <= r){
				int val = (query(r + 1) + 1) % p;
				for(int k = 0;k <= r - l;k++){
					add(r - k, 1ll * C(k + 1 + j - i, j - i) * val % p);
				}
				for(int k = 0;k <= j - i;k++){
					int L = max(i + k + 1, l);
					if(L <= r) ans = (ans + 1ll * C(r - L + k + 1, k + 1) * val) % p;
//					printf("%d %d--\n", i + k, ans);
				}
			}
			i = j;
		}
		printf("%d\n", ans);
		 
	} 
}