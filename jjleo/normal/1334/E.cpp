#include <bits/stdc++.h>
#define maxn 40000086

using namespace std;

typedef long long ll;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	}
	return ans;
} 

int sum[300], inv[300];
int cnt, prm[maxn / 10];
bool tag[maxn];

map<ll, int> mp;

int cal(ll z){
	register int ans1 = 0, ans2 = 1;
	ll k = z;
	register int sup = ((int)sqrt(z)) + 1;
	for(register int i = 1;prm[i] <= sup && i <= cnt && k != 1;i++){
		int j = 0;
		while(k % prm[i] == 0){
			j++, ans1++;
			k /= prm[i];
		}
		ans2 = 1ll * ans2 * inv[j] % p;
	}
	if(k != 1) ans1++;
	return 1ll * sum[ans1] * ans2 % p;
}



ll D;
int q;
ll x, y, z;

int main(){
	scanf("%lld%d", &D, &q);
	sum[0] = inv[0] = 1;
	for(register int i = 1;i <= 100;i++) sum[i] = 1ll * sum[i - 1] * i % p, inv[i] = fpow(sum[i], p - 2);
	int n = ((int)sqrt(D)) + 1;
	for(register int i = 2;i <= n;i++){
		if(!tag[i]) prm[++cnt] = i;
		for(int j = 1;j <= cnt && 1ll * i * prm[j] <= n;j++){
			tag[i * prm[j]] = true;
			if(i % prm[j] == 0) break;
		}
	}
	for(register int i = 1;i <= n;i++){
		if(D % i == 0){
			mp[i] = cal(i);
			if(D / i != i){
				mp[D / i] = cal(D / i);
			}
		}
	}
	while(q--){
		scanf("%lld%lld", &x, &y);
		if(x > y) swap(x, y);
		z = __gcd(x, y);
		if(z == x) printf("%d\n", mp[y / x]);
		else printf("%d\n", 1ll * mp[x / z] * mp[y / z] % p);
	} 
}