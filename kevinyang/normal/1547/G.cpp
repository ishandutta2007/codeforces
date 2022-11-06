#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj(400001); vector<vector<int>>adj2(400001);
vector<bool>used(400001);
vector<int>order, component;
void dfs1(int u){
	used[u] = true;
	for(int nxt: adj[u]){
		if(!used[nxt]){
			dfs1(nxt);
		}
	}
	order.push_back(u);
}
void dfs2(int u){
	used[u] = true;
	component.push_back(u);
	for(int nxt: adj2[u]){
		if(!used[nxt]){
			dfs2(nxt);
		}
	}
}
void reset(int n){
	for(int i = 0; i<=n; i++){
		adj[i].clear(); adj2[i].clear();
		used[i] = false;
	}
	order.clear();
	component.clear();
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(m==0){
			cout << "1 ";
			for(int i = 0; i<n-1; i++){
				cout << "0 ";
			}
			cout << "\n";
			continue;
		}
		vector<int>infnode(n+1);
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			if(x==y)infnode[x] = 1;
			adj[x].push_back(y);
			adj2[y].push_back(x);
		}
		for(int i = 1; i<=n; i++){
			if(!used[i]){
				dfs1(i);
			}
		}
		for(int i = 1; i<=n; i++){
			used[i] = false;
		}
		vector<int>comp(n+1);
		int count = 0;
		vector<int>infcomp(n+1);
		for(int i = 1; i<=n; i++){
			int u = order[n-i];
			if(!used[u]){
				dfs2(u);
				count++;
				for(int nxt: component){
					comp[nxt] = count;
					if(infnode[nxt]){
						infcomp[count] = 1;
					}
				}
				if(component.size()>1)infcomp[count] = 1;
				component.clear();
			}
		}
		vector<vector<int>>adj3(count+1);
		vector<int>indegrees(count+1);
		for(int i = 1; i<=n; i++){
			for(int nxt: adj[i]){
				if(comp[i]!=comp[nxt]){
					adj3[comp[i]].push_back(comp[nxt]);
				}
			}
		}
		//cerr << "nae\n";
		//cerr << "nae " << count << "\n";
		if(true){
			queue<int>q;
			q.push(comp[1]);
			vector<bool>vis(count+1);
			vis[comp[1]] = true;
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(int nxt: adj3[cur]){
					if(!vis[nxt]){
						vis[nxt] = true;
						q.push(nxt);
					}
				}
			}
			for(int i = 1; i<=count; i++){
				if(vis[i]){
					for(int nxt: adj3[i]){
						indegrees[nxt]++;
					}
				}
			}
		}
		//cerr << "nae\n";
		vector<int>dp(count+1);
		indegrees[comp[1]] = 0;
		queue<int>q;
		q.push(comp[1]);
		dp[comp[1]] = 1;
		if(infcomp[comp[1]])dp[comp[1]] = -(int)1e18;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int nxt: adj3[cur]){
				indegrees[nxt]--;
				if(dp[cur]<0)dp[nxt] = -(int)1e18;
				else dp[nxt]+=dp[cur];
				dp[nxt] = min(dp[nxt],2LL);
				if(indegrees[nxt]==0){
					q.push(nxt);
					if(infcomp[nxt])dp[nxt] = -(int)1e18;
				}
			}
		}
		for(int i = 1; i<=n; i++){
			if(dp[comp[i]]<0)cout << "-1 ";
			else cout << dp[comp[i]] << " ";
		}
		cout << "\n";
		reset(n);
	}
	return 0;
}