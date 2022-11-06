#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>adj(n+1);
	vector<vector<bool>>con(n+1,vector<bool>(n+1));
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
		con[x][y] = true;
		con[y][x] = true;
	}
	vector<char>ans(n+1);
	vector<bool>vis(n+1);
	for(int i = 1; i<=n; i++){
		if(adj[i].size()==n-1){
			ans[i] = 'b';
			vis[i] = true;
		}
	}
	for(int i = 1; i<=n; i++){
		if(!vis[i]){
			vis[i] = true;
			ans[i] = 'a';
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(int nxt: adj[cur]){
					if(!vis[nxt]){
						vis[nxt] = true;
						ans[nxt] = 'a';
						q.push(nxt);
					}
				}
			}
			break;
		}
	}
	for(int i = 1; i<=n; i++){
		if(!vis[i]){
			ans[i] = 'c';
		}
	}
	bool f = true;
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			if(!con[i][j]&&abs(ans[j]-ans[i])==2){

			}
			else if(con[i][j]&&abs(ans[j]-ans[i])<=1){

			}
			else{
				f = false;
			}
		}
	}
	if(f){
		cout << "Yes\n";
		for(int i = 1; i<=n; i++){
			cout << ans[i];
		}
		cout << "\n";
	}
	else{
		cout << "No\n";
	}
	return 0;
}