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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	int res = 0;
    	vi dp(n);
    	for(int i = n - 1; i >= 0; i--) {
    		if(a[i] + i >= n) {
    			dp[i] = a[i] + i;
    		} else {
    			dp[i] = dp[i + a[i]];
    		}
    		res = max(res, dp[i] - i);
    	}
    	cout << res << '\n';
    }
}