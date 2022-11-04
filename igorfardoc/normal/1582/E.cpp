#include<bits/stdc++.h>
#define INF 10000000000000000ll
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
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	vector<ll> pref(n + 1, 0);
    	for(int i = 1; i <= n; i++) {
    		pref[i] = pref[i - 1] + a[i - 1];
    	}
    	vector<vector<ll>> dp(n, vector<ll>(500, -INF));
    	for(int i = n - 1; i >= 0; i--) {
    		for(int j = 1; j < 500; j++) {
    			if(i != n - 1) {
    				dp[i][j] = dp[i + 1][j];
    			}
    			if(j * (j + 1) / 2 > n - i) {
    				continue;
    			}
    			ll sumlast = pref[i + j] - pref[i];
    			if(j == 1) {
    				dp[i][j] = max(dp[i][j], sumlast);
    				continue;
    			}
    			if(sumlast < dp[i + j][j - 1]) {
    				dp[i][j] = max(dp[i][j], sumlast);
    			}
    		}
    	}
    	for(int i = 499; i > 0; i--) {
    		if(dp[0][i] != -INF) {
    			cout << i << '\n';
    			break;
    		}
    	}
    }
}