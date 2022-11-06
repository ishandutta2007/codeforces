#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>adj(500001);
vector<vector<int>>ans(500001);
int cur = 1;
void dfs(int u, int p){
	//cerr << u << " " << p << "\n";
	vector<int>arr;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		arr.push_back(nxt);
	}
	if(arr.size()==0){
		cur++;
		ans[u].push_back(cur);
		return;
	}
	for(int i = 0; i<arr.size(); i++){
		cur++;
		ans[arr[i]].push_back(cur);
	}
	cur++;
	ans[u].push_back(cur);
	for(int i = arr.size()-1; i>=0; i--){
		dfs(arr[i],u);
	}
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
	ans[1].push_back(1);
	dfs(1,0);
	for(int i = 1; i<=n; i++){
		cout << ans[i][0] << " " << ans[i][1] << "\n";
	}
	return 0;
}