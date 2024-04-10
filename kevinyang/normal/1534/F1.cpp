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
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>dx = {-1,0,1,0};
	vector<int>dy = {0,1,0,-1};
	vector<vector<char>>mp(n+2,vector<char>(m+2));
	vector<vector<int>>arr(n+1,vector<int>(m+2));//disjoint set number
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			mp[i][j] = s[j-1];
		}
	}
	for(int i = 0; i<m; i++){
		int monkey; cin >> monkey;
	}
	int nodes = 0;
	if(true){
		vector<vector<bool>>vis(n+1,vector<bool>(m+1));
		int cur = 0;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(vis[i][j])continue;
				if(mp[i][j]!='#')continue;
				cur++;
				vis[i][j] = true;
				arr[i][j] = cur;
				queue<pair<int,int>>q;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int>p = q.front(); q.pop();
					int x = p.first; int y = p.second;
					for(int d = 0; d<4; d++){
						int nx = x+dx[d]; int ny = y+dy[d];
						if(mp[nx][ny]!='#')continue;
						if(vis[nx][ny])continue;
						vis[nx][ny] = true;
						arr[nx][ny] = cur;
						q.push({nx,ny});
					}
				}
			}
		}
		nodes = cur;
	}
	//cerr << "nae\n";
	if(true){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(mp[i][j]!='#')continue;
				int k = i+1;
				while(k<=n){
					if(mp[k][j]=='#')break;
					for(int d = 0; d<4; d++){
						int nx = k+dx[d]; int ny = j+dy[d];
						if(mp[nx][ny]=='#'&&arr[i][j]!=arr[nx][ny]){
							adj[arr[i][j]].push_back(arr[nx][ny]);
							adj2[arr[nx][ny]].push_back(arr[i][j]);
						}
					}
					k++;
				}
			}
		}
	}
	n = nodes;
	//cerr << "nae\n";
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
	for(int i = 1; i<=n; i++){
		int u = order[n-i];
		if(!used[u]){
			dfs2(u);
			count++;
			for(int nxt: component){
				comp[nxt] = count;
			}
			component.clear();
		}
	}
	vector<vector<int>>adj3(count+1);
	vector<int>indegrees(count+1);
	for(int i = 1; i<=n; i++){
		for(int nxt: adj[i]){
			if(comp[i]!=comp[nxt]){
				adj3[comp[i]].push_back(comp[nxt]);
				indegrees[comp[nxt]]++;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=count; i++){
		if(indegrees[i]==0)ans++;
	}
	cout << ans << "\n";
	return 0;
}