#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool good(int x, int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return true;
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<bool>>vis(n+1,vector<bool>(m+1));
	vector<vector<int>>arr(n+1,vector<int>(m+1));
	vector<int>cmax(100000);
	vector<int>rmax(100000);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i<=n; i++){
		int mx = 0;
		for(int j = 1; j<=m; j++){
			mx = max(mx,arr[i][j]);
		}
		rmax[mx] = 1;
	}
	for(int j = 1; j<=m; j++){
		int mx = 0;
		for(int i = 1; i<=n; i++){
			mx = max(mx,arr[i][j]);
		}
		cmax[mx] = 1;
	}
	vector<vector<int>>ans(n+1,vector<int>(m+1));
	vector<vector<int>>val(n+1,vector<int>(m+1));
	vector<int>dx = {-1,0,1,0};
	vector<int>dy = {0,1,0,-1};
	set<pair<int,int>>q;
	queue<int>use;
	int x = 0; int y = 0;
	for(int v = n*m; v>=1; v--){
		if(cmax[v]&&rmax[v]){
			x++; y++;
			vis[x][y] = true;
			ans[x][y] = v;
		}
		else if(cmax[v]){
			y++;
			vis[x][y] = true;
			ans[x][y] = v;
		}
		else if(rmax[v]){
			x++; vis[x][y] = true;
			ans[x][y] = v;
		}
		else{
			use.push(v);
			continue;
		}
		for(int d = 0; d<4; d++){
			int nx = x+dx[d]; int ny = y+dy[d];
			if(good(nx,ny)&&!vis[nx][ny]){
				val[nx][ny]++;
				if(val[nx][ny]==2){
					vis[nx][ny] = true;
					q.insert({nx,ny});
				}
			}
		}
	}
	while(use.size()){
		int v = use.front(); use.pop();
		pair<int,int>cur = *q.begin(); q.erase(q.begin());
		ans[cur.first][cur.second] = v;
		for(int d = 0; d<4; d++){
			int nx = cur.first + dx[d]; int ny =cur.second + dy[d];
			if(good(nx,ny)&&!vis[nx][ny]){
				val[nx][ny]++;
				if(val[nx][ny]==2){
					vis[nx][ny] = true;
					q.insert({nx,ny});
				}
				
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}