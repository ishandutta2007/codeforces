#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[5004][5004];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	int ans = (int)1e18;
	vector<int> o, z;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i]) o.push_back(i);
		else z.push_back(i);
	}
	for(int i = 0; i < 5004; ++i){
		for(int j = 0; j < 5004; ++j){
			dp[i][j] = (int)1e18;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < (int)o.size(); ++i){
		for(int j = 0; j < (int)z.size(); ++j){
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(o[i] - z[j]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
		}
	}
	for(int j = 0; j <= (int)z.size(); ++j){
		ans = min(ans, dp[(int)o.size()][j]);
	}
	cout << ans;
	return 0;
}