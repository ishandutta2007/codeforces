#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		vector<vector<char>>arr(n+1,vector<char>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				arr[i][j] = s[j-1];
			}
		}
		vector<vector<bool>>vis(n+1,vector<bool>(m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(arr[i][j]=='.')continue;
				bool f = true;
				vector<pair<int,int>>used;
				for(int k = 0; k<i; k++){
					if(j-k>=1&&j+k<=m&&arr[i-k][j-k]=='*'&&arr[i-k][j+k]=='*'){
						used.push_back({i-k,j-k});
						used.push_back({i-k,j+k});
					}
					else{
						break;
					}
				}
				if(used.size()<=2*k)continue;
				for(pair<int,int>nxt: used){
					vis[nxt.first][nxt.second] = true;
				}
			}
		}
		bool f = true;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(arr[i][j]=='.')continue;
				if(vis[i][j])continue;
				f = false;
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}