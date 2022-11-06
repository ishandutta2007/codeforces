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
		vector<vector<char>>arr(n+1,vector<char>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				arr[i][j] = s[j-1];
			}
		}
		if(true){
			bool f = true;
			for(int i = 1; i<=n; i++){
				for(int j = 1; j<=m; j++){
					if(arr[i][j]=='.')continue;
					if((i+j)%2==0&&arr[i][j]=='R')continue;
					if((i+j)%2==1&&arr[i][j]=='W')continue;
					f = false;
				}
			}
			if(f){
				cout << "YES\n";
				for(int i = 1; i<=n; i++){
					for(int j = 1; j<=m; j++){
						if((i+j)%2==0)cout << "R";
						else cout << "W";
					}
					cout << "\n";
				}
				continue;
			}
		}
		if(true){
			bool f = true;
			for(int i = 1; i<=n; i++){
				for(int j = 1; j<=m; j++){
					if(arr[i][j]=='.')continue;
					if((i+j)%2==1&&arr[i][j]=='R')continue;
					if((i+j)%2==0&&arr[i][j]=='W')continue;
					f = false;
				}
			}
			if(f){
				cout << "YES\n";
				for(int i = 1; i<=n; i++){
					for(int j = 1; j<=m; j++){
						if((i+j)%2==1)cout << "R";
						else cout << "W";
					}
					cout << "\n";
				}
				continue;
			}
		}
		cout << "NO\n";
	}
	
	return 0;
}