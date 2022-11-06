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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<vector<int>>psa(n+1,vector<int>(n+1));
		for(int i = 1; i<=n; i++){
			psa[i][arr[i]]++;
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
			}
		}
		int ans = 0;
		for(int i = 1; i<=n; i++){
			for(int j = i+1; j<=n; j++){
				ans += psa[i-1][arr[j]-1] * (psa[n][arr[i]-1]-psa[j][arr[i]-1]);

			}
		}
		cout << ans << "\n";
	}
	return 0;
}