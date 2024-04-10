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
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<vector<char>>arr(n+1,vector<char>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				arr[i][j] = s[j-1];
			}
		}
		vector<vector<bool>>vis(n+1,vector<bool>(m+1));
		vector<vector<int>>dis(n+1,vector<int>(m+1));
		vector<vector<int>>time(n+1,vector<int>(m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(vis[i][j])continue;
				int nx = i; int ny = j;
				deque<pair<int,int>>dq;
				dq.push_back({i,j});
				nx = i; ny = j;
				int cur = 1;
				time[nx][ny] = 1;
				while(true){
					cur++;
					if(arr[nx][ny]=='U')nx--;
					else if(arr[nx][ny]=='D')nx++;
					else if(arr[nx][ny]=='L')ny--;
					else if(arr[nx][ny]=='R')ny++;
					if(!good(nx,ny)){
						nx = 0; ny = 0;
						while(dq.size()){
							pair<int,int>p = dq.back();
							dq.pop_back();
							if(vis[p.first][p.second])break;
							vis[p.first][p.second] = true;
							dis[p.first][p.second] = dis[nx][ny] + 1;
							nx = p.first; ny = p.second;
						}
						break;
					}
					else if(vis[nx][ny]){
						while(dq.size()){
							pair<int,int>p = dq.back();
							dq.pop_back();
							if(vis[p.first][p.second])break;
							vis[p.first][p.second] = true;
							dis[p.first][p.second] = dis[nx][ny] + 1;
							nx = p.first; ny = p.second;
						}
						break;
					}
					else if(time[nx][ny]){
						int len = cur-time[nx][ny];
						int old = time[nx][ny];
						//cout << len << "\n";
						while(dq.size()){
							pair<int,int>p = dq.back(); dq.pop_back();
							if(vis[p.first][p.second])break;
							if(time[p.first][p.second]>=old){
								vis[p.first][p.second] = true;
								dis[p.first][p.second] = len;
							}
							else{
								vis[p.first][p.second] = true;
								dis[p.first][p.second] = dis[nx][ny] +1;
							}
							nx = p.first; ny = p.second;
						}
						break;
					}
					else{
						time[nx][ny] = cur;
						dq.push_back({nx,ny});
					}
				}
			}
		}
		int mx = 0; int x = 1; int y = 1;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(dis[i][j]>mx){
					mx = dis[i][j]; x = i; y = j;
				}
			}
		}
		cout << x << " " << y << " " << mx << "\n";
	}

	return 0;
}