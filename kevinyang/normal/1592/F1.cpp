#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>arr(n+5,vector<int>(m+5));
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			if(s[j-1]=='B')arr[i][j] = 1;
		}
	}
	vector<vector<int>>val(n+5,vector<int>(m+5));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			val[i][j] = arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1];
			val[i][j]%=2;
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans+=count(val[i].begin(),val[i].end(),1);
	}
	bool f = false;
	for(int i = 1; i<n; i++){
		for(int j = 1; j<m; j++){
			if(val[i][j]&&val[i][m]&&val[n][j]&&val[n][m])f = true;
		}
	}
	ans-=f;
	cout << ans << "\n";
	return 0;
}