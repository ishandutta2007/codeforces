#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 300005;
const int mod = 998244353; // I hate this modulo!

int n, pwr[MAXN], vis[MAXN], col[MAXN], c0, c1, bad;
vector<int> gph[MAXN];

void dfs(int x, int c){
	if(vis[x]){
		if(col[x] != c) bad = 1;
		return;
	}
	col[x] = c;
	vis[x] = 1;
	if(c == 1) c0++;
	else c1++;
	for(auto &i : gph[x]) dfs(i, 3 - c);
}

int main(){
	pwr[0] = 1;
	for(int i=1; i<MAXN; i++) pwr[i] = (pwr[i-1] * 2) % mod;
	int tc; scanf("%d",&tc);
	while(tc--){
		int n, m;
		scanf("%d %d",&n,&m);
		for(int i=1; i<=n; i++) gph[i].clear();
		for(int i=1; i<=n; i++) vis[i] = col[i] = 0;
		while(m--){
			int s, e; scanf("%d %d",&s,&e);
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
		lint ret = 1;
		bad = 0;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				c0 = c1 = 0;
				dfs(i, 1);
				if(bad) ret = 0;
				ret *= pwr[c0] + pwr[c1];
				ret %= mod;
			}
		}
		printf("%lld\n", ret);
	}
}