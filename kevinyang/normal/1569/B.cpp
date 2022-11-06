#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int v = count(s.begin(),s.end(),'2');
		if(v==1||v==2){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<vector<char>>ans(n+1,vector<char>(n+1,'='));
		vector<int>rem;
		for(int i = 1; i<=n; i++){
			if(s[i-1]=='2'){
				rem.push_back(i);
			}
		}
		for(int i = 0; i<(int)rem.size()-1; i++){
			ans[rem[i]][rem[i+1]] = '+';
			ans[rem[i+1]][rem[i]] = '-';
		}
		if(rem.size()>0){
			ans[rem[rem.size()-1]][rem[0]] = '+';
			ans[rem[0]][rem[rem.size()-1]] = '-';
		}
		
		for(int i = 1; i<=n; i++){
			ans[i][i] = 'X';
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}