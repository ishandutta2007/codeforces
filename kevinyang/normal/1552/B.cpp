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
		vector<vector<int>>arr(n,vector<int>(5));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<5; j++){
				cin >> arr[i][j];
			}
		}
		int cur = 0;
		for(int i = 1; i<n; i++){
			int cnt = 0;
			for(int j = 0; j<5; j++){
				if(arr[i][j]<arr[cur][j])cnt++;
			}
			if(cnt>=3){
				cur = i;
			}
		}
		bool f = true;
		for(int i = 0; i<n; i++){
			if(i==cur)continue;
			int cnt = 0;
			for(int j = 0; j<5; j++){
				if(arr[i][j]<arr[cur][j])cnt++;
			}
			if(cnt>=3)f = false;
		}
		if(f)cout << cur+1 << "\n";
		else cout << "-1\n";
	}
	return 0;
}