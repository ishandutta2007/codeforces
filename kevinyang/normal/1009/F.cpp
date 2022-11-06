#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int mxn = 1000005;
vector<vector<int>>adj(mxn);
vector<int>lvl(mxn);
vector<int>ans(mxn);//idx ans 
vector<int>dp(mxn);//mx freq ans
map<int,int> dfs(int u, int p){
	lvl[u] = lvl[p]+1;
	int mx = 1;
	int idx = lvl[u];
	map<int,int>hm;
	hm[lvl[u]] = 1;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		map<int,int>temp = dfs(nxt,u);
		if(hm.size()<temp.size()){
			swap(hm,temp);
			idx = ans[nxt];
			mx = dp[nxt];
		}
		for(pair<int,int>p: temp){
			hm[p.first]+=p.second;
			if(hm[p.first]>mx){
				mx = hm[p.first];
				idx = p.first;
			}
			else if(hm[p.first]==mx){
				idx = min(idx,p.first);
			}
		}
	}
	ans[u] = idx;
	dp[u] = mx;
	return hm;
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
	for(int i = 1; i<=n; i++){
		//cout << ans[i] << " ";
		cout << ans[i]-lvl[i] << "\n";

	}
	return 0;
}