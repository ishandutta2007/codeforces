#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

const int p = 1e9 + 7;

int n;
int a[maxn];
ll val;
int sum[maxn], inv[maxn];
map<int, int> mp[2];

inline int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
	scanf("%d", &n);
	sum[0] = 1;for(int i = 1;i <= n;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[0] = inv[1] = 1;for(int i = 2;i <= n;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 1;i <= n;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), val += a[i];
	if(val % n) return printf("0"), 0;
	val /= n;
	int x = 0, y = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] > val) mp[0][a[i]]++, x++;
		else if(a[i] < val) mp[1][a[i]]++, y++;
	}
	if(x == 1 || y == 1){
		int ans = sum[n];
		for(map<int, int>::iterator it = mp[0].begin();it != mp[0].end();++it){
			ans = 1ll * ans * inv[it->second] % p;
		}
		for(map<int, int>::iterator it = mp[1].begin();it != mp[1].end();++it){
			ans = 1ll * ans * inv[it->second] % p;
		}
		return printf("%d", 1ll * ans * inv[n - x - y] % p), 0;
	}
	if(!x && !y) return printf("1"), 0;
	int ans = 2ll * sum[x] * sum[y] % p;
	for(map<int, int>::iterator it = mp[0].begin();it != mp[0].end();++it){
		ans = 1ll * ans * inv[it->second] % p;
	}
	for(map<int, int>::iterator it = mp[1].begin();it != mp[1].end();++it){
		ans = 1ll * ans * inv[it->second] % p;
	}
	ans = 1ll * ans * C(n, x + y) % p;
	printf("%d", ans);
}