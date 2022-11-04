#include<bits/stdc++.h>
#define INF 3000000000000000000ll
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
    	int n, m;
    	cin >> n >> m;
    	vector<vector<ll>> a(n, vector<ll>(m));
    	vector<ll> all;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> a[i][j];
    			a[i][j] -= i + j;
    			all.push_back(a[i][j]);
    		}
    	}
    	ll ans = INF;
    	for(auto now : all) {
    		vector<vector<ll>> dp(n, vector<ll>(m, INF));
    		for(int i = n - 1; i >= 0; i--) {
    			for(int j = m - 1; j >= 0; j--) {
    				if(i == n - 1 && j == m - 1) {
    					if(a[i][j] >= now) {
    						dp[i][j] = a[i][j] - now;
    					}
    					continue;
    				}
    				if(a[i][j] < now) {
    					continue;
    				}
    				ll here = a[i][j] - now;
    				if(i != n - 1 && dp[i + 1][j] != INF) {
    					dp[i][j] = dp[i + 1][j] + here;
    				}
    				if(j != m - 1 && dp[i][j + 1] != INF) {
    					dp[i][j] = min(dp[i][j], dp[i][j + 1] + here);
    				}
    			}
    		}
    		ans = min(ans, dp[0][0]);
    	}
    	cout << ans << '\n';
    }
}