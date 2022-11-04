#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vvi dp(10, vi(200001));
    for(int i = 0; i <= 200000; i++) {
    	for(int j = 0; j < 10; j++) {
    		if(i == 0) {
    			dp[j][i] = 1;
    			continue;
    		}
    		if(j < 9) {
    			dp[j][i] = dp[j + 1][i - 1];
    		} else {
    			dp[j][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
    		}
    	}
    }
    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	int res = 0;
    	while(n) {
    		res = (res + dp[n % 10][m]) % mod;
    		n /= 10;
    	}
    	cout << res << '\n';
    }
}