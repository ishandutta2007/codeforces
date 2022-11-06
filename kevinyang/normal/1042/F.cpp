#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj(1000001);
int ans = 0;
int n,k;
int dfs(int u, int p){
	if(adj[u].size()==1)return 0;
	vector<int>arr;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		arr.push_back(dfs(nxt,u)+1);
	}
	sort(arr.begin(),arr.end());
	int end = arr.size()-1;
	while(arr.size()>=2&&end>0){
		if(arr[end]+arr[end-1]<=k)break;
		end--;
		ans++;
	}
	return arr[end];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i<=n; i++){
		if(adj[i].size()!=1){
			dfs(i,0);
			break;
		}
	}
	cout << ans+1 << "\n";
	return 0;
}