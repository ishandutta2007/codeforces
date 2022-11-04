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
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	vi ans(n + 1, 1);
    	vi dp(n + 1, 0);
    	for(int i = 0; i <= n; i++) {
    		if(i == 0) {
    			continue;
    		}
    		if(s[i - 1] != 'L') {
    			continue;
    		}
    		++dp[i];
    		if(i == 1) {
    			continue;
    		}
    		if(s[i - 2] == 'R') {
    			dp[i] += 1 + dp[i - 2];
    		}
    	}
    	for(int i = 0; i <= n; i++) {
    		ans[i] += dp[i];
    	}
    	dp.assign(n + 1, 0);
    	for(int i = n; i >= 0; i--) {
    		if(i == n) {
    			continue;
    		}
    		if(s[i] != 'R') {
    			continue;
    		}
    		++dp[i];
    		if(i == n - 1) {
    			continue;
    		}
    		if(s[i + 1] == 'L') {
    			dp[i] += 1 + dp[i + 2];
    		}
    	}
    	for(int i = 0; i <= n; i++) {
    		ans[i] += dp[i];
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    }
}