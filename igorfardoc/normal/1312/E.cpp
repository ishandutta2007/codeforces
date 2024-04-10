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
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int len = 1; len <= n; len++) {
    	for(int l = 0; l < n - len + 1; l++) {
    		int r = l + len - 1;
    		if(len == 1) {
    			dp[l][r] = a[l];
    			continue;
    		}
    		for(int mid = 0; mid < r; mid++) {
    			if(dp[l][mid] == dp[mid + 1][r] && dp[l][mid] != -1) {
    				dp[l][r] = dp[l][mid] + 1;
    				break;
    			}
    		}
    	}
    }
    vi dp1(n + 1, 100000);
    dp1[0] = 0;
    for(int i = 1; i <= n; i++) {
    	dp1[i] = i;
    	for(int j = i - 1; j >= 0; j--) {
    		if(dp[j][i - 1] != -1) {
    			dp1[i] = min(dp1[i], dp1[j] + 1);
    		}
    	}
    }
    cout << dp1[n];

}