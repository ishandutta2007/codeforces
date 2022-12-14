#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> a(n * 2, vector<int>(n * 2));
		int ans = 0, low = (int)1e18;
		for(int i = 0; i < n * 2; ++i){
			for(int j = 0; j < n * 2; ++j){
				cin >> a[i][j];
				if(i >= n && j >= n){
					ans += a[i][j];
				}
				if(i == 0 && j == n) mi(low, a[i][j]);
				if(i == 0 && j == 2 * n - 1) mi(low, a[i][j]);
				if(i == n - 1 && j == n) mi(low, a[i][j]);
				if(i == n - 1 && j == 2 * n - 1) mi(low, a[i][j]);
				if(j == 0 && i == n) mi(low, a[i][j]);
				if(j == 0 && i == 2 * n - 1) mi(low, a[i][j]);
				if(j == n - 1 && i == n) mi(low, a[i][j]);
				if(j == n - 1 && i == 2 * n - 1) mi(low, a[i][j]);
			}
		}
		cout << ans + low << '\n';
	}
	return 0;
}