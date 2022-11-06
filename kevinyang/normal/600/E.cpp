#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int mxn = 100005;
vector<int>sz(mxn);
vector<int>val(mxn);
vector<vector<int>>adj(mxn);
vector<int>dp(mxn);
vector<int>dp2(mxn);//max freq of subtree i
map<int,int> dfs(int u, int p){
	int children = 0;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		children++;
	}
	if(children==0){
		map<int,int>hm;
		hm[val[u]]++;
		dp[u] = val[u];
		dp2[u] = 1;
		return hm;
	}
	else{
		map<int,int>hm;
		int mx = 0;
		int sum = 0;
		for(int nxt: adj[u]){
			if(nxt==p)continue;
			map<int,int>temp = dfs(nxt,u);
			if(hm.size()<temp.size()){
				swap(hm,temp);
				mx = 0; sum = 0;
				if(dp2[nxt]>mx){
					mx = dp2[nxt];
					sum = dp[nxt];
				}
				else if(dp2[nxt]==mx){
					sum+=dp[nxt];
				}
			}
			for(pair<int,int>p: temp){
				hm[p.first]+=p.second;
				if(hm[p.first]>mx){
					mx = hm[p.first];
					sum = p.first;
				}
				else if(hm[p.first]==mx){
					sum+=p.first;
				}
			}
		}
		hm[val[u]]++;
		if(hm[val[u]]>mx){
			mx = hm[val[u]];
			sum = val[u];
		}
		else if(hm[val[u]]==mx){
			sum+=val[u];
		}
		dp[u] = sum;
		dp2[u] = mx;
		return hm;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> val[i];
	}
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	for(int i = 1; i<=n; i++){
		cout << dp[i] << " ";
	}
	return 0;
}