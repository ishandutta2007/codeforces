#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<int> gph[500005];
int n, par[500005], dep[500005], msk[500005];
int dp[500005], sz[500005];

int mx[1<<22];
int l[23] = {};

void dfs2(int x, vector<pi> &v){
	v.push_back(pi(dep[x], msk[x]));
	for(auto &i : gph[x]) dfs2(i, v);
}

void dfs(int x){
	if(gph[x].empty()){
		mx[msk[x]] = dep[x];
		return;
	}
	for(int i=1; i<gph[x].size(); i++){
		dfs(gph[x][i]);
		vector<pi> w;
		dfs2(gph[x][i], w);
		for(auto &j : w) mx[j.second] = -1;
	}
	dfs(gph[x][0]);
	for(int i=1; i<gph[x].size(); i++){
		vector<pi> w;
		dfs2(gph[x][i], w);
		for(auto &j : w){
			for(int k=0; k<23; k++){
				int val = mx[j.second ^ l[k]];
				if(~val) dp[x] = max(dp[x], j.first + val - 2 * dep[x]);
			}
		}
		for(auto &j : w) mx[j.second] = max(mx[j.second], j.first);
	}
	for(int k=0; k<23; k++){
		if(mx[msk[x] ^ l[k]] != -1){
			dp[x] = max(dp[x], mx[msk[x] ^ l[k]] - dep[x]);
		}
	}
	mx[msk[x]] = max(mx[msk[x]], dep[x]);
}

int main(){
	scanf("%d",&n);
	char ch[6];
	for(int i=0; i<22; i++) l[i] = (1<<i);
	for(int i=2; i<=n; i++){
		scanf("%d %s",&par[i],ch);
		gph[par[i]].push_back(i);
		dep[i] = dep[par[i]] + 1;
		msk[i] = msk[par[i]] ^ (1 << (*ch - 'a'));
	}
	for(int i=n; i; i--){
		sz[i] = 1;
		for(auto &j : gph[i]) sz[i] += sz[j];
		sort(gph[i].begin(), gph[i].end(), [&](const int &a, const int &b){
			return sz[a] > sz[b];
		});
	}
	memset(mx, -1, sizeof(mx));
	dfs(1);
	for(int i=n; i; i--){
		for(auto &j : gph[i]) dp[i] = max(dp[i], dp[j]);
	}
	for(int i=1; i<=n; i++) printf("%d ", dp[i]);
}