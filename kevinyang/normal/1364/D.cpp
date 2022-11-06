#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 100005;
vector<vector<int>>adj(mxn);
vector<vector<int>>adj2(mxn);
vector<int>parent(mxn);
vector<int>lvl(mxn);
vector<bool>vis(mxn);
int n,m,k;
pair<int,int>ans = {0,0};
void dfs(int u, int p){
	parent[u] = p;
	lvl[u] = lvl[p]+1;
	vis[u] = true;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt]){
			if(lvl[u]>lvl[nxt]&&lvl[u]-lvl[nxt]+1<=k){
				ans = {u,nxt};
			}
		}
		else{
			adj2[u].push_back(nxt);
			adj2[nxt].push_back(u);
			dfs(nxt,u);
		}
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if(m==n-1){
		vector<int>dis(n+1);
		queue<int>q;
		q.push(1);
		vis[1] = true;
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis[nxt])continue;
				vis[nxt] = true;
				dis[nxt] = dis[cur]+1;
				q.push(nxt);
			}
		}
		vector<int>odd;
		vector<int>even;
		for(int i = 1; i<=n; i++){
			if(dis[i]%2==0)even.push_back(i);
			else odd.push_back(i);
		}
		cout << "1\n";
		if(odd.size()<even.size()){
			for(int i = 0; i<(k+1)/2; i++){
				cout << even[i] << " ";
			}
			cout << "\n";
		}
		else{
			for(int i = 0; i<(k+1)/2; i++){
				cout << odd[i] << " ";
			}
			cout << "\n";
		}
		return 0;
	}
	dfs(1,0);
	if(ans.first!=0&&ans.second!=0){
		vector<int>arr;
		int cur = ans.first;
		while(cur!=ans.second){
			arr.push_back(cur);
			cur = parent[cur];
		}
		arr.push_back(ans.second);
		cout << "2\n";
		cout << arr.size() << "\n";
		for(int nxt: arr){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	else{
		int node = 1; int depth = 0;
		for(int i = 1; i<=n; i++){
			if(lvl[i]>depth){
				depth = lvl[i];
				node = i;
			}
		}
		cout << "1\n";
		for(int i = 0; i<(k+1)/2; i++){
			cout << node << " ";
			node = parent[node];
			node = parent[node];
		}
		cout << "\n";
	}
	return 0;
}