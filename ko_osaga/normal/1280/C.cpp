#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 600005;

int n, sz[MAXN], msz[MAXN];
vector<pi> gph[MAXN];
lint dfs2(int x, int p, lint d){
	lint ans = d;
	for(auto &i : gph[x]){
		if(i.second != p){
			ans += dfs2(i.second, x, d + i.first);
		}
	}
	return ans;
}


lint dfs(int x, int p){
	sz[x] = 1;
	msz[x] = 0;
	lint ans = 0;
	for(auto &i : gph[x]){
		if(i.second != p){
			ans += dfs(i.second, x);
			if(sz[i.second] & 1) ans += i.first;
			sz[x] += sz[i.second];
			msz[x] = max(msz[x], sz[i.second]);
		}
	}
	return ans;
}

void solve(){
	scanf("%d",&n);
	for(int i=0; i<2*n-1; i++){
		int s, e, x; scanf("%d %d %d",&s,&e,&x);
		gph[s].emplace_back(x, e);
		gph[e].emplace_back(x, s);
	}
	printf("%lld ", dfs(1, 0));
	pi ret(1e9, 1e9);
	for(int i=1; i<=2*n; i++){
		int cur = max(2 * n - sz[i], msz[i]);
		ret = min(ret, pi(cur, i));
	}
	printf("%lld\n", dfs2(ret.second, 0, 0));
	for(int i=1; i<=2*n; i++) gph[i].clear();
}

int main(){
	int tc = 0;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
}