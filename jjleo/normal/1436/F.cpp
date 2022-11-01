#include <bits/stdc++.h>
#define maxn 100086

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

int n;
int cnt[maxn];
int sum[maxn], a[maxn], b[maxn];
long long siz[maxn];
int f[maxn];
int x, y;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &x, &y);
		cnt[x] = y;
	}
	n = 1e5;
	for(int i = 1;i <= n;i++){
		for(int j = 1;i * j <= n;j++){
			siz[i] += cnt[i * j];
			a[i] = (a[i] + 1ll * cnt[i * j] * i * j % p * i * j) % p;
			b[i] = (b[i] + 2ll * cnt[i * j] * i * j % p * sum[i]) % p;
			b[i] = (b[i] + 1ll * cnt[i * j] * (cnt[i * j] - 1) % p * i * j % p * i * j) % p;
			sum[i] = (sum[i] + 1ll * cnt[i * j] * i * j) % p;
		}
		//printf("%d %d %lld %d %d--\n", i, sum[i], siz[i], a[i], b[i]);
	}
	for(int i = n;i;i--){
		if(siz[i] >= 2) f[i] = (f[i] + 1ll * a[i] * fpow(2, (siz[i] - 2) % (p - 1)) % p * ((siz[i] - 1) % p)) % p;
		if(siz[i] >= 3) f[i] = (f[i] + 1ll * b[i] * fpow(2, (siz[i] - 3) % (p - 1)) % p * ((siz[i] - 2) % p)) % p;
		if(siz[i] >= 2) f[i] = (f[i] + 1ll * b[i] * fpow(2, (siz[i] - 2) % (p - 1))) % p;
		for(int j = 2;i * j <= n;j++) f[i] = (f[i] + p - f[i * j]) % p;
	}
	printf("%d", f[1]);
}