#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int n, m;
int a[maxn];
int b[maxn];
int x;

int sum[maxn], inv[maxn];
int c[maxn];

inline void add(int x, int y){
	for(;x < maxn;x += x & -x) c[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += c[x];
	return sum;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i - 1] * inv[i] % p;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d" ,&x), b[x]++;
	for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
	int val = sum[n];
	for(int i = 1;i < maxn;i++) val = 1ll * val * inv[b[i]] % p, add(i, b[i]);
	int ans = 0;
	for(int i = 1;i <= m;i++){
		val = 1ll * val * inv[n - i + 1] % p;
		val = 1ll * val * sum[n - i] % p;
		ans = (ans + 1ll * val * query(a[i] - 1)) % p;
		if(b[a[i]] == 0) break;
		val = 1ll * val * sum[b[a[i]]] % p;
		b[a[i]]--;
		add(a[i], -1);
		val = 1ll * val * inv[b[a[i]]] % p;
		if(i == n && n < m) ans = (ans + 1) % p;
	}
	printf("%d", ans);
}