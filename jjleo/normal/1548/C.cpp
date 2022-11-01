#include <bits/stdc++.h>
#define maxn 3000086

using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

const int inv3 = fpow(3, p - 2);

int n, q;
int sum[maxn], inv[maxn];

inline int C(int n, int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

vector<int> v[maxn];
int x;
int ans[maxn];
int a[maxn], b[maxn], c[maxn];

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= q;i++) scanf("%d", &x), v[x].push_back(i);
	for(int i = 1;i <= n;i++){
		a[0] = (a[0] + C(3 * i, 0)) % p;
		b[0] = (b[0] + C(3 * i - 1, 0)) % p;
		c[0] = (c[0] + C(3 * i - 2, 0)) % p;
	}
	/*for(int i = 1;i <= n;i++){
		a[1] = (a[1] + C(3 * i, 1)) % p;
		b[1] = (b[1] + C(3 * i - 1, 1)) % p;
		c[1] = (c[1] + C(3 * i - 2, 1)) % p;
	}*/
	for(int i = 1;i <= 3 * n;i++){
		//assert((1ll * C(3 * i - 2, 1) + 2ll * C(3 * i - 1, 2) + C(3 * i - 2, 3)) % p == C(3 * i, 3));
		a[i] = (2ll * b[i - 1] + c[i - 1] + C(3 * n + 1, i + 1)) % p * inv3 % p;
		b[i] = (a[i] + p - b[i - 1]) % p;
		c[i] = (1ll * a[i] - b[i - 1] - c[i - 1] + 2ll * p) % p;
		for(int j = 0;j < v[i].size();j++) ans[v[i][j]] = a[i];
	}
	for(int i = 1;i <= q;i++) printf("%d\n", ans[i]);
}