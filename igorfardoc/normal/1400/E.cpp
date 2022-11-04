#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi dp(n + 1, vi(n + 1));
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= n; j++) {
    		if(i == 0) {
    			dp[i][j] = 0;
    			continue;
    		}
    		if(j >= a[i - 1]) {
    			dp[i][j] = dp[i - 1][a[i - 1]];
    			continue;
    		}
    		dp[i][j] = 1 + dp[i - 1][j];
    		if(a[i - 1] <= n) {
    			dp[i][j] = min(dp[i][j], dp[i - 1][a[i - 1]] + a[i - 1] - j);
    		}
    	}
    }
    cout << dp[n][0];
}