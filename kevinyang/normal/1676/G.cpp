#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 4005;
vector<vector<int>>adj(mxn);
vector<int>sz(mxn);
string s;
void dfs(int u, int p){
	if(s[u-1]=='B')sz[u]--;
	else sz[u]++;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
}
void reset(int n){
	for(int i = 1; i<=n; i++){
		adj[i].clear();
		sz[i] = 0;
	}
	s = "";
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 2; i<=n; i++){
			int x;
			cin >> x;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
		cin >> s;
		dfs(1,0);
		int ans = 0;
		for(int i = 1; i<=n; i++){
			if(sz[i]==0){
				ans++;
			}
		}
		cout << ans << "\n";
		reset(n);
	}
	return 0;
}