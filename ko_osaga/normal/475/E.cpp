#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int adj[2005][2005];
int n, m;
int dfn[2005], low[2005], comp[2005], piv1, piv2;
vector<int> gph[2005];

void dfs(int x, int p){
	dfn[x] = low[x] = ++piv1;
	for(int i=1; i<=n; i++){
		if(adj[x][i] && i != p){
			if(dfn[i]){
				low[x] = min(low[x], dfn[i]);
			}
			else{
				dfs(i, x);
				low[x] = min(low[x], low[i]);
				if(low[i] <= dfn[x]) gph[x].push_back(i), gph[i].push_back(x);
			}
		}
	}
}

void dfs2(int x, int p){
	if(comp[x]) return;
	comp[x] = p;
	for(auto &i : gph[x]) dfs2(i, p);
}

int cnt[2005];
int sz[2005];

int dfs3(int x, int p, int d){
	int ret = d * cnt[x];
	sz[x] = cnt[x];
	for(auto &i : gph[x]){
		if(i == p) continue;
		ret += dfs3(i, x, d+cnt[x]);
		sz[x] += sz[i];
	}
	return ret;
}

int solve(int x){
	bitset<2005> bs;
	int ret = dfs3(x, -1, 0);
	bs[0] = 1;
	for(auto &j : gph[x]){
		bs |= (bs << sz[j]);
	}
	for(int i=(n-cnt[x])/2; i>=0; i--){
		if(bs[i]){
			ret += (n-cnt[x]-i) * i; 
			break;
		}
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		adj[x][y] = adj[y][x] = 1;
	}
	dfs(1, 0);
	for(int i=1; i<=n; i++){
		if(!comp[i]) dfs2(i, ++piv2);
	}
	for(int i=1; i<=n; i++) gph[i].clear();
	for(int i=1; i<=n; i++){
		cnt[comp[i]]++;
		for(int j=1; j<=n; j++){
			if(adj[i][j] && comp[i] != comp[j]) gph[comp[i]].push_back(comp[j]);
		}
	}
	int ret = 0;
	for(int i=1; i<=piv2; i++){
		ret = max(ret, solve(i));
	}
	for(int i=1; i<=piv2; i++){
		ret += (cnt[i] * cnt[i] - cnt[i]);
	}
	ret += n;
	cout << ret;
}