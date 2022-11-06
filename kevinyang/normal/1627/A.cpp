#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,r,c;
		cin >> n >> m >> r >> c;
		vector<vector<char>>mp(n+1,vector<char>(m+1));
		bool f = false;
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				mp[i][j] = s[j-1];
				if(s[j-1]=='B')f = true;
			}
		}
		if(mp[r][c]=='B'){
			cout << "0\n";
			continue;
		}
		bool flag = false;
		for(int i = 1; i<=n; i++){
			if(mp[i][c]=='B')flag = true;
		}
		for(int j = 1; j<=m; j++){
			if(mp[r][j]=='B')flag = true;
		}
		if(flag){
			cout << "1\n";
			continue;
		}
		if(f){
			cout << "2\n";
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}