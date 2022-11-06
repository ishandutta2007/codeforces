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
		vector<vector<int>>arr(n+1,vector<int>(m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cin >> arr[i][j];
			}
		}
		int count = 0;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(arr[i][j]%2==(i+j)%2)count++;
			}
		}
		if(count>=n*m-count){
			for(int i = 1; i<=n; i++){
				for(int j = 1; j<=m; j++){
					if(arr[i][j]%2==(i+j)%2)cout << arr[i][j] << " ";
					else cout << arr[i][j]+1 << " ";
				}
				cout << "\n";
			}
		}
		else{
			for(int i = 1; i<=n; i++){
				for(int j = 1; j<=m; j++){
					if(arr[i][j]%2!=(i+j)%2)cout << arr[i][j] << " ";
					else cout << arr[i][j]+1 << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}