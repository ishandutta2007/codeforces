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
		if(n==2){
			cout << "-1\n";
			continue;
		}
		vector<vector<int>>ans(n,vector<int>(n));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				ans[i][(i+j)%n] = i+1+j*n;
			}
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}