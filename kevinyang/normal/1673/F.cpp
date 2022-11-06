#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int m = n;
	int k;
	cin >> k;
	vector<vector<int>>arr(n+1,vector<int>(m+1));
	vector<int>order = {0,2,0,4,0,2,0,6,0,2,0,4,0,2,0,8,0,2,0,4,0,2,0,6,0,2,0,4,0,2,0};
	vector<int>order2 = {1,3,1,5,1,3,1,7,1,3,1,5,1,3,1,9,1,3,1,5,1,3,1,7,1,3,1,5,1,3,1};
	for(int i = 2; i<=m; i++){
		arr[1][i] = arr[1][i-1]^(1<<order[i-2]);
	}
	for(int i = 2; i<=n; i++){
		for(int j = 1; j<=m; j++){
			arr[i][j] = arr[i-1][j]^(1<<(order2[i-2]));
		}
	}
	
	int sum = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 2; j<=m; j++){
			cout << (arr[i][j]^arr[i][j-1]) << " ";
		}
		cout << endl;
	}
	for(int i = 2; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cout << (arr[i][j]^arr[i-1][j]) << " ";
		}
		cout << endl;
	}
	int x = 1; int y = 1;
	while(k--){
		int v;
		cin >> v;
		int nx = 0; int ny = 0;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if((arr[i][j]^arr[x][y])==v){
					nx = i; ny = j;
					break;
				}
			}
		}
		cout << nx << " " << ny << endl;
		x = nx; y = ny;
	}
	return 0;
}