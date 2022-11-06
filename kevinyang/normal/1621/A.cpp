#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if((n+1)/2<k){
			cout << "-1\n";
			continue;
		}
		vector<vector<char>>arr(n+1,vector<char>(n+1,'.'));
		for(int i = 0; i<k; i++){
			arr[2*i+1][2*i+1] = 'R';
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}