#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
int mxn = 100005;
vector<vector<int>>adj(mxn);
vector<vector<int>>high(mxn,vector<int>(10,(int)1e9));
int ln = 20;
vector<vector<int>>dp(mxn,vector<int>(ln));
vector<vector<vector<int>>>dp2(mxn,vector<vector<int>>(ln,vector<int>(10,(int)1e9)));
vector<int>lvl(mxn);
void dfs(int u, int p){
	lvl[u] = lvl[p]+1;
	dp[u][0] = p;
	for(int i = 0; i<10; i++){
		dp2[u][0][i] = high[u][i];
	}
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
		vector<int>a;
		for(int j = 0; j<10; j++){
			a.push_back(dp2[u][i-1][j]);
			a.push_back(dp2[dp[u][i-1]][i-1][j]);
		}
		sort(a.begin(),a.end());
		for(int j = 0; j<10; j++){
			dp2[u][i][j] = a[j];
		}
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y])swap(x,y);
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i<ln; i++){
		if(dif&(1<<i)){
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
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i<=m; i++){
		int x;
		cin >> x;
		vector<int>a;
		for(int nxt: high[x]){
			a.push_back(nxt);
		}
		a.push_back(i);
		sort(a.begin(),a.end());
		for(int i = 0; i<10; i++){
			high[x][i] = a[i];
		}
	}
	dfs(1,0);
	while(q--){
		int x,y,k;
		cin >> x >> y >> k;
		int u = lca(x,y);
		int dist = lvl[x]-lvl[u];
		vector<int>a;
		for(int i = 0; i<ln; i++){
			if(dist&(1<<i)){
				for(int j = 0; j<10; j++){
					a.push_back(dp2[x][i][j]);
				}
				x = dp[x][i];
			}
		}
		dist = lvl[y]-lvl[u];
		for(int i = 0; i<ln; i++){
			if(dist&(1<<i)){
				for(int j = 0; j<10; j++){
					a.push_back(dp2[y][i][j]);
				}
				y = dp[y][i];
			}
		}
		for(int j = 0; j<10; j++){
			a.push_back(dp2[u][0][j]);
		}
		sort(a.begin(),a.end());
		vector<int>ans;
		for(int i = 0; i<k; i++){
			if(a[i]==(int)1e9)break;
			ans.push_back(a[i]);
		}
		cout << ans.size() << " ";
		for(int nxt: ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}