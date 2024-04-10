#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>arr(n,vector<int>(m));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cin >> arr[i][j];
			}
		}
		vector<vector<int>>arr2(n,vector<int>(m));
		arr2[0][0] = 2;
		arr2[0][m-1] = 2;
		arr2[n-1][0] = 2;
		arr2[n-1][m-1] = 2;
		for(int i = 0; i<m; i++){
			if(arr2[0][i]==0)arr2[0][i] = 3;
			if(arr2[n-1][i]==0)arr2[n-1][i] = 3;
		}
		for(int i = 0; i<n; i++){
			if(arr2[i][0]==0)arr2[i][0] = 3;
			if(arr2[i][m-1]==0)arr2[i][m-1] = 3;
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(arr2[i][j]==0)arr2[i][j] = 4;
			}
		}
		bool f = true;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(arr[i][j]>arr2[i][j]){
					f = false;
				}
			}
		}
		if(!f){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					cout << arr2[i][j] << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}