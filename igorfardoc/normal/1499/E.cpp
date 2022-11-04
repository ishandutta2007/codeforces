#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    string x, y;
    cin >> x >> y;
    vi a, b;
    for(int i = 0; i < x.size(); i++) {
    	a.push_back(x[i] - 'a');
    }
    for(int i = 0; i < y.size(); i++) {
    	b.push_back(y[i] - 'a');
    }
    int n = x.size();
    int m = y.size();
    vector<int> dp1(n, n), dp2(m, m);
    for(int i = n - 2; i >= 0; i--) {
    	if(a[i] == a[i + 1]) {
    		dp1[i] = i + 1;
    	} else {
    		dp1[i] = dp1[i + 1];
    	}
    }
    for(int i = m - 2; i >= 0; i--) {
    	if(b[i] == b[i + 1]) {
    		dp2[i] = i + 1;
    	} else {
    		dp2[i] = dp2[i + 1];
    	}
    }
    vector<vvi> dp(n + 1, vvi(m + 1, vi(27, 0)));
    for(int i = n; i >= 0; i--) {
    	for(int j = m; j >= 0; j--) {
    		for(int k = 0; k < 27; k++) {
    			if(i == n || j == m) continue;
    			if(k != a[i]) {
    				dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][a[i]]) % mod;
    			}
    			if(k != b[j]) {
    				dp[i][j][k] = (dp[i][j][k] + dp[i][j + 1][b[j]]) % mod;
    			}
    			if(k != a[i] && b[j] != a[i]) {
    				dp[i][j][k] = (dp[i][j][k] + dp2[j] - j) % mod;
    			}
    			if(k != b[j] && a[i] != b[j]) {
    				dp[i][j][k] = (dp[i][j][k] + dp1[i] - i) % mod;
    			}
    		}
    	}
    }
    //cout << dp[2][1][26] << endl;
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		ans = (ans + dp[i][j][26]) % mod;
    	}
    }
    cout << ans;

}