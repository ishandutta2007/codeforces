#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, k;
vector<int> v[maxn];
int s[maxn];

map<pair<int, int>, ll> mp;

ll dfs(int i, int x){
	if(x == 0) return 0;
	if(mp.count({i, x})) return mp[{i, x}];
	ll ans = 1ll * s[i] * x;
	if(v[i].empty()) return ans;
	vector<ll> w;
	for(auto to : v[i]){
		ll val = dfs(to, x / v[i].size());
		ans += val;
		w.push_back(dfs(to, x / v[i].size() + (x % v[i].size() != 0)) - val);
	}
	sort(w.begin(), w.end(), greater<ll>());
	for(int j = 0;j < x % v[i].size();j++) ans += w[j];
	return mp[{i, x}] = ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 2;i <= n;i++){
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for(int i = 1;i <= n;i++) scanf("%d", &s[i]);
		mp.clear();
		printf("%lld\n", dfs(1, k));
	}
}