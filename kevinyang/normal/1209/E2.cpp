#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(vector<int>a, vector<int>b){
	int mx = 0; int mx2 = 0;
	for(int nxt: a){
		mx = max(mx,nxt);
	}
	for(int nxt: b){
		mx2 = max(mx2,nxt);
	}
	return mx>mx2;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int tt;
	cin >> tt;
	while(tt--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>arr(m,vector<int>(n));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cin >> arr[j][i];
			}
		}
		sort(arr.begin(),arr.end(),comp);
		vector<vector<int>>a(n,vector<int>(m+1));
		for(int i = 0; i<n; i++){
			for(int j = 1; j<=m; j++){
				a[i][j] = arr[j-1][i];
			}
		}
		vector<vector<int>>dp((1<<n),vector<int>(min(n,m)+1));
		for(int t = 1; t<=min(m,n); t++){
			vector<int>mx(1<<n);
			for(int i = 0; i<(1<<n); i++){
				for(int tr = 0; tr<n; tr++){
					int temp = a[n-1][t];
					for(int j = n-1; j>0; j--){
						a[j][t] = a[j-1][t];
					}
					a[0][t] = temp;
					int v = 0;
					for(int j = 0; j<n; j++){
						if(i&(1<<j)){
							v+=a[j][t];
						}
					}
					mx[i] = max(mx[i],v);
				}	
			}
			for(int i = 0; i<(1<<n); i++){
				dp[i][t] = dp[i][t-1];
				for(int j = i; j>0; j = (j-1)&i){
					dp[i][t] = max(dp[i][t],dp[i^j][t-1]+mx[j]);
				}
			}
		}
		//cerr << "nae\n";
		cout << dp[(1<<n)-1][min(n,m)] << "\n";
	}
	return 0;
}