#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n;
map<ll, ll> mp;

ll dfs(ll x){
	if(!x) return 0;
	if(mp[x]) return mp[x];
	for(ll i = 1ll << 62;i;i >>= 1){
		if(x & i){
			return mp[x] = (dfs(i >> 1) << 1) + 1 + dfs(x - i);
		}
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", dfs(n));
	}	
}