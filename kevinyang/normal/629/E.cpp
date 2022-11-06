#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<vector<int>>adj(mxn); int ln = 20;
vector<vector<int>>dp(mxn,vector<int>(ln));
vector<int>dp3(mxn);
vector<int>dp4(mxn);
vector<int>lvl(mxn);
vector<int>sz(mxn);
int n,m;
void dfs(int u, int p){
	lvl[u] = lvl[p]+1;
	dp[u][0] = p;
	sz[u] = 1;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		dp3[u]+=dp3[nxt]+sz[nxt];
		sz[u]+=sz[nxt];
	}
}
void dfs2(int u, int p){
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dp4[nxt] = dp3[u]-dp3[nxt]-sz[nxt]+dp4[u]+n-sz[nxt];
		dfs2(nxt,u);
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y])swap(x,y);
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i<ln; i++){
		if((1<<i)&dif){
			x = dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i = ln-1; i>=0; i--){
		if(dp[x][i]!=dp[y][i]){
			x = dp[x][i]; y = dp[y][i];
		}
	}
	return dp[x][0];
}
int lca2(int x, int y){
	if(lvl[x]<lvl[y])swap(x,y);
	int dif = lvl[x]-lvl[y]; dif--;
	for(int i = 0; i<ln; i++){
		if((1<<i)&dif){
			x = dp[x][i];
		}
	}
	return x;
}
bool isparent(int x, int y){//returns if x is a parent of y
	int u = lca(x,y);
	return x==u;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0);
	cout << fixed << setprecision(10);
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		if(lvl[x]>lvl[y]){
			swap(x,y);
		}
		double ans = 0;
		if(isparent(x,y)){
			int s2 = sz[y];
			int u = lca2(x,y);
			int s1 = n-sz[u];
			int v = dp4[u]-(n-sz[u]);
			ans+=((double)v)/s1;
			ans+=((double)dp3[y])/sz[y];
			ans+=lvl[y]-lvl[x];
		}
		else{
			ans+=(double)dp3[x]/sz[x];
			ans+=(double)dp3[y]/sz[y];
			int u = lca(x,y);
			ans+=lvl[x]+lvl[y]-2*lvl[u];
		}
		cout << ans+1 << "\n";
	}
	return 0;
}