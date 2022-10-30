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

int n, k;
int a[maxn], b[maxn];
vector<int> v;
int l[maxn], r[maxn];

int sum[maxn], inv[maxn];

inline int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d%d", &l[i], &r[i]), v.push_back(l[i]), v.push_back(r[i] + 1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++){
		a[lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1]++;
		b[lower_bound(v.begin(), v.end(), r[i] + 1) - v.begin() + 1]--;
	}
	int x = 0, ans = 0;
	for(int i = 1;i <= v.size();i++){
		x += b[i];
		for(int j = 1;j <= a[i];j++){
			if(x >= k - 1) ans = (ans + C(x, k - 1)) % p; 
			x++;
		}
	}
	printf("%d", ans);
}