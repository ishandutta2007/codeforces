#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>arr(1005,vector<int>(1005));
vector<vector<bool>>vis(1005,vector<bool>(1005));
bool good(int x, int y){
	if(x>=1&&x<=n&&y>=1&&y<=m){
		return true;
	}
	return false;
}
bool f(int x, int y){
	if(good(x,y)&&!vis[x][y]){
		return true;
	}
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin >> arr[i][j];
		}
	}
	queue<pair<int,int>>q;
	vector<pair<int,int>>ans;
	vector<int>colour;
	for(int i = 2; i<=n; i++){
		for(int j = 2; j<=m; j++){
			if(arr[i][j]==arr[i-1][j]&&arr[i][j]==arr[i][j-1]&&arr[i-1][j-1]==arr[i][j]&&!vis[i][j]&&!vis[i][j-1]&&!vis[i-1][j]&&!vis[i-1][j-1]){
				q.push({i,j});
				q.push({i,j-1});
				q.push({i-1,j});
				q.push({i-1,j-1});
				ans.push_back({i-1,j-1});
				colour.push_back(arr[i-1][j-1]);
				vis[i][j] = vis[i][j-1] = vis[i-1][j] = vis[i-1][j-1] = true;
			}
		}
	}
	vector<int>dx = {0,-1,-1,0};
	vector<int>dy = {-1,-1,0,0};

	while(q.size()){
		pair<int,int>cur = q.front(); q.pop();
		int x = cur.first; int y = cur.second;
		for(int d = 0; d<4; d++){
			int a = x+dx[d]; int b = y+dy[d];
			if(good(a,b)&&good(a+1,b+1)){
				set<int>s;
				for(int i = 0; i<2; i++){
					for(int j = 0; j<2; j++){
						if(vis[a+i][b+j])continue;
						s.insert(arr[a+i][b+j]);
					}
				}
				if(s.size()!=1)continue;
				ans.push_back({a,b});
				colour.push_back(*s.begin());
				for(int i = 0; i<2; i++){
					for(int j = 0; j<2; j++){
						if(vis[a+i][b+j])continue;
						vis[a+i][b+j] = true;
						q.push({a+i,b+j});
					}
				}
			}
		}
	}
	reverse(colour.begin(),colour.end());
	reverse(ans.begin(),ans.end());
	vector<vector<int>>a(n+1,vector<int>(m+1));
	for(int i = 0; i<ans.size(); i++){
		int x = ans[i].first; int y = ans[i].second;
		int c = colour[i];
		for(int dtx = 0; dtx<2; dtx++){
			for(int dty = 0; dty<2; dty++){
				a[x+dtx][y+dty] = c;
			}
		}
	}
	bool f = true;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(a[i][j]!=arr[i][j])f = false;
		}
	}
	if(f){
		cout << ans.size() << "\n";
		for(int i = 0; i<ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << " " << colour[i] << "\n";
		}
	}
	else{
		cout << "-1\n";
	}
	return 0;
}