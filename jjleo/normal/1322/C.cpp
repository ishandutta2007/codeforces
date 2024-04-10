#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int t, n, m;
map<vector<int>, ll> mp;

vector<int> v[maxn];
ll c[maxn];
int x, y;
ll ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		mp.clear();
		for(int i = 1;i <= n;i++) scanf("%lld", &c[i]), v[i].clear();
		while(m--){
			scanf("%d%d", &x, &y);
			v[y].push_back(x);
		} 
		for(int i = 1;i <= n;i++){
			if(!v[i].size()) continue;//debug: 
			sort(v[i].begin(), v[i].end());
			mp[v[i]] += c[i];
		}
		ans = 0;//debug: 
		for(map<vector<int>, ll>::iterator it = mp.begin();it != mp.end();it++){
			if(!ans) ans = it->second;
			else ans = __gcd(ans, it->second);
		}
		printf("%lld\n", ans);
	}
}