#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>>arr(n+1,vector<int>(n+1));
	for(int i = 1; i<=n; i++){
		cin >> arr[i][i];
	}
	bool f = true;
	for(int i = n; i>=1; i--){
		int k = arr[i][i]-1;
		int x = i; int y = i;
		while(k){
			if(x+1<=n&&!arr[x+1][y]){
				k--; x++;
				arr[x][y] = arr[i][i];
			}
			else if(y-1>=1&&!arr[x][y-1]){
				k--; y--;
				arr[x][y] = arr[i][i];
			}
			else{
				f = false;
				break;
			}
		}
	}
	if(f){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=i; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else{
		cout << "-1\n";
	}
	return 0;
}