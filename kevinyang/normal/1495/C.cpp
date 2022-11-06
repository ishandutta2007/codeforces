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
		vector<vector<char>>mp(n+1,vector<char>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				mp[i][j] = s[j-1];
				if(i%3==1)mp[i][j] = 'X';
			}
		}
		for(int i = 3; i<=n; i+=3){
			bool f = false;
			for(int j = 1; j<=m; j++){
				if(mp[i][j]=='X'||mp[i-1][j]=='X'){
					mp[i][j] = 'X'; mp[i-1][j] = 'X';
					f = true;
					break;
				}
			}
			if(!f){
				mp[i][1] = 'X';
				mp[i-1][1] = 'X';
			}
		}
		if(n%3==0){
			for(int j = 1; j<=m; j++){
				if(mp[n][j]=='X'){
					mp[n-1][j] = 'X';
				}
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cout << mp[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}