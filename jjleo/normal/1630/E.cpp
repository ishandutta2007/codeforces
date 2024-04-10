#include <bits/stdc++.h>
#define maxn 1000086

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

int t, n;
int a[maxn], x;
int sum[maxn], inv[maxn];
vector<int> v;
int prm[maxn], cnt, phi[maxn];
bool tag[maxn];

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	phi[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(!tag[i]) prm[++cnt] = i, phi[i] = i - 1;
		for(int j = 1;j <= cnt && prm[j] * i < maxn;j++){
			tag[prm[j] * i] = true;
			if(i % prm[j]){
				phi[prm[j] * i] = phi[i] * (prm[j] - 1);
			}else{
				phi[prm[j] * i] = phi[i] * prm[j];
				break;
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
		int gcd = 0;
		v.clear();
		for(int i = 1;i <= n;i++) if(a[i]) gcd = __gcd(gcd, a[i]), v.push_back(i);
		if(gcd == n){
			puts("1");
			continue;
		}
		int x = 0, y = 0;
		for(int d = 1;d <= gcd;d++) if(gcd % d == 0){
			int f = sum[n / d], g = 0;
			for(int i = 0;i < v.size();i++) f = 1ll * f * inv[a[v[i]] / d] % p;
			for(int i = 0;i < v.size();i++) g = (g + 1ll * f * inv[n / d] % p * sum[n / d - 2] % p * (a[v[i]] / d) % p * (a[v[i]] / d - 1)) % p;
			g = 1ll * g * n % p;
			y = (y + 1ll * f * phi[d]) % p;
			x = (x + 1ll * g * phi[d]) % p;
		}
		printf("%d\n", (n + p - 1ll * x * fpow(y, p - 2) % p) % p);
	}
}