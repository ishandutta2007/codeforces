#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int mxn = 200005;
vector<int>bit(mxn);
vector<vector<int>>adj(mxn);
vector<int>loc(mxn);
vector<int>sz(mxn);
int ln = 20;
vector<vector<int>>dp(mxn,vector<int>(20));
vector<int>lvl(mxn);
int timer = 0;
void update(int x, int val){
	for(int a = x; a<=200000; a+=a&-a){
		bit[a]+=val;
	}
}
int query(int x){
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		sum+=bit[a];
	}
	return sum;
}
void dfs(int u, int p){
	sz[u] = 1;
	timer++;
	loc[u] = timer;
	lvl[u] = lvl[p]+1;
	dp[u][0] = p;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y]){
		swap(x,y);
	}
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i<ln; i++){
		if(dif&(1<<i)){
			x = dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i = ln-1; i>=0; i--){
		if(dp[x][i]==dp[y][i])continue;
		x = dp[x][i]; y = dp[y][i];
	}
	return dp[x][0];
}
int dist(int x, int y){
	int u = lca(x,y);
	return lvl[x]+lvl[y]-lvl[u]*2;
}
bool comp(int a, int b){
	return loc[a]< loc[b];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cin >> q;
	while(q--){
		int k;
		cin >> k;
		vector<int>arr(k);
		for(int i = 0; i<k; i++){
			cin >> arr[i];
			update(loc[arr[i]],1);
			update(loc[arr[i]]+sz[arr[i]],-1);
		}
		bool f = false;
		sort(arr.begin(),arr.end(),comp);
		for(int i = 0; i<k-1; i++){
			int x = arr[i]; int y = arr[k-1];
			int u = lca(x,y);
			int v = query(loc[x])+query(loc[y])- query(loc[u])-query(loc[dp[u][0]]);
			if(v==k)f = true;
		}
		for(int i = 0; i<k; i++){
			update(loc[arr[i]],-1);
			update(loc[arr[i]]+sz[arr[i]],1);
		}
		if(k==1)f = true;
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}