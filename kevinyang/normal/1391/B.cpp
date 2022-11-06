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
		vector<vector<char>>arr(n,vector<char>(m));
		for(int i = 0; i<n; i++){
			string s;
			cin >> s;
			for(int j = 0; j<m; j++){
				arr[i][j] = s[j];
			}
		}
		int count = 0;
		for(int i = 0; i<m-1; i++){
			if(arr[n-1][i]!='R')count++;
		}
		for(int i = 0; i<n-1; i++){
			if(arr[i][m-1]!='D')count++;
		}
		cout << count << "\n";
	}
	return 0;
}