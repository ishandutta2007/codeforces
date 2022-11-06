#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int cnt = 0;
		vector<vector<int>>ans(n*m);
		vector<vector<int>>arr(n+1,vector<int>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				arr[i][j] = s[j-1]-'0';
			}
		}
		if(n%2==1&&m%2==1&&arr[n][m]){
			cnt++;
			for(int i = 0; i<6; i++)ans[0].push_back(0);
			ans[0][0] = n; ans[0][1] = m; ans[0][2] = n-1; ans[0][3] = m; ans[0][4] = n; ans[0][5] = m-1;
			arr[n][m]^=1; arr[n-1][m]^=1; arr[n][m-1]^=1;
		}
		if(n%2==1){
			for(int i = 1; i<m; i+=2){
				if(!arr[n][i]&&!arr[n][i+1])continue;
				int rem = 3;
				if(arr[n][i]){
					arr[n][i]^=1; rem--; ans[cnt].push_back(n); ans[cnt].push_back(i);
				}
				if(arr[n][i+1]){
					arr[n][i+1]^=1; rem--; ans[cnt].push_back(n); ans[cnt].push_back(i+1);
				}
				rem--; arr[n-1][i]^=1; ans[cnt].push_back(n-1); ans[cnt].push_back(i);
				if(rem){
					rem--; arr[n-1][i+1]^=1; ans[cnt].push_back(n-1); ans[cnt].push_back(i+1);
				}
				cnt++;
			}
		}
		if(m%2==1){
			for(int i = 1; i<n; i+=2){
				if(!arr[i][m]&&!arr[i+1][m])continue;
				int rem = 3;
				if(arr[i][m]){
					arr[i][m]^=1; rem--; ans[cnt].push_back(i); ans[cnt].push_back(m);
				}
				if(arr[i+1][m]){
					arr[i+1][m]^=1; rem--; ans[cnt].push_back(i+1); ans[cnt].push_back(m);
				}
				rem--; arr[i][m-1]^=1; ans[cnt].push_back(i); ans[cnt].push_back(m-1);
				if(rem){
					rem--; arr[i+1][m-1]^=1; ans[cnt].push_back(i+1); ans[cnt].push_back(m-1);
				}
				cnt++;
			}
		}
		for(int i = 1; i<n; i+=2){
			for(int j = 1; j<m; j+=2){
				while(arr[i][j]||arr[i][j+1]||arr[i+1][j]||arr[i+1][j+1]){
					set<pair<int,int>>s; set<pair<int,int>>s2;
					if(arr[i][j])s.insert({0,0});
					else s2.insert({0,0});
					if(arr[i+1][j])s.insert({1,0});
					else s2.insert({1,0});
					if(arr[i][j+1])s.insert({0,1});
					else s2.insert({0,1});
					if(arr[i+1][j+1])s.insert({1,1});
					else s2.insert({1,1});
					if(s.size()>=3){
						for(int c = 0; c<3; c++){
							pair<int,int>p = *s.begin(); s.erase(p);
							arr[i+p.first][j+p.second]^=1;
							ans[cnt].push_back(i+p.first); ans[cnt].push_back(j+p.second);
						}
					}
					else{
						if(true){
							pair<int,int>p = *s.begin(); s.erase(p);
							arr[i+p.first][j+p.second]^=1;
							ans[cnt].push_back(i+p.first); ans[cnt].push_back(j+p.second);
						}
						for(int c = 0; c<2; c++){
							pair<int,int>p = *s2.begin(); s2.erase(p);
							arr[i+p.first][j+p.second]^=1;
							ans[cnt].push_back(i+p.first); ans[cnt].push_back(j+p.second);
						}
					}
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		for(int i = 0; i<cnt; i++){
			for(int j = 0; j<6; j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}