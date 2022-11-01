#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

typedef long long ll;

int n;
ll a[maxn];
ll ans;

map<ll, int> mp;

inline void cal(ll x){
	if(x <= ans) return;
	int sum = 0;
	for(map<ll, int>::iterator it = mp.begin();it != mp.end();++it){
		if(it->first % x == 0) sum += it->second;
		if(sum * 2 >= n){
			ans = max(ans, x); 
			return;
		}
	}
}


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	srand(time(NULL));
	random_shuffle(a + 1, a + 1 + n);
	for(int i = 1;i <= n && i <= 10;i++){
		mp.clear();
		for(int j = 1;j <= n;j++) mp[__gcd(a[i], a[j])]++;
		for(ll j = 1;j * j <= a[i];j++){
			if(a[i] % j == 0) cal(j), cal(a[i] / j);
		}
	}
	printf("%lld", ans);
}