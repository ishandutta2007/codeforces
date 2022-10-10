#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i ++){
		int u;
		cin >> u;
		u --;
		adj[i].push_back(u);
		adj[u].push_back(i);
	}
	vector<int> cnt(n);
	vector<bool> visited(n);
	function<void(int)> dfs = [&](int u){
		visited[u] = true;
		bool isleaf = true;
		for(auto v: adj[u]){
			if(!visited[v]){
				isleaf = false;
				dfs(v);
				cnt[u] += cnt[v];
			}
		}
		if(isleaf){
			cnt[u] = 1;
		}
	};
	dfs(0);
	sort(cnt.begin(), cnt.end());
	for(auto x: cnt){
		cout << x << " ";
	}
	return 0;
}