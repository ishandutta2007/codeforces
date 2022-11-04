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
    sort(a.begin(), a.end());
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int len = 1; len <= n; len++) {
    	for(int l = 0; l < n - len + 1; l++) {
    		int r = l + len - 1;
    		if(l == r) {
    			dp[l][r] = 0;
    			continue;
    		}
    		dp[l][r] = a[r] - a[l] + min(dp[l + 1][r], dp[l][r - 1]);
    	}
    }
    cout << dp[0][n - 1];
}