#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 1000005;

lint profit, sum;
int n, q, a[MAXN];

int deg[MAXN];

void add(int s, int t, int u){
	profit -= min(a[u], deg[u]);
	deg[u]++;
	profit += min(a[u], deg[u]);
}

void rem(int s, int t, int u){
	profit -= min(a[u], deg[u]);
	deg[u]--;
	profit += min(a[u], deg[u]);
}

lint solve(){
	return sum - profit;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sum = accumulate(a + 1, a + n + 1, 0ll);
	scanf("%d",&q);
	map<pi, int> mp;
	while(q--){
		int s, t, u; scanf("%d %d %d",&s,&t,&u);
		if(mp.find(pi(s, t)) != mp.end()){
			rem(s, t, mp[pi(s, t)]);
			mp.erase(pi(s, t));
		}
		if(u != 0){
			mp[pi(s, t) ] = u;
			add(s, t, u);
		}
		printf("%lld\n", solve());
	}
}