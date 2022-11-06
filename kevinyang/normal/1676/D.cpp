#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool good(int x, int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return true;
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;

		vector<vector<int>>arr(n+1,vector<int>(m+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				int sum = 0;
				for(int d = 1; d<=200; d++){
					if(good(i-d,j-d))sum+=arr[i-d][j-d];
					if(good(i-d,j+d))sum+=arr[i-d][j+d];
					if(good(i+d,j-d))sum+=arr[i+d][j-d];
					if(good(i+d,j+d))sum+=arr[i+d][j+d];
				}
				sum+=arr[i][j];
				ans = max(ans,sum);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}