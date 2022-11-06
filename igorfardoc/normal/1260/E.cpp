#include<bits/stdc++.h>
#define inf 1000000000000000000ll
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
    int id1 = 0;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	if(a[i] == -1) {
    		id1 = i;
    	}
    }
    a[id1] = 0;
    int log1 = 1;
    for(int i = 0; i < n; i++) {
    	if((1 << i) == n) {
    		log1 = i;
    		break;
    	}
    }
    vi am(log1 + 1);
    am[0] = 0;
    for(int i = 1; i <= log1; i++) {
    	am[i] = am[i - 1] + n / (1 << i);
    }
    vector<vector<ll>> dp(log1 + 1, vector<ll>(n + 1, inf));
    for(int i = 0; i <= log1; i++) {
    	for(int j = 0; j <= n; j++) {
    		if(i == 0 && j == 0) {
    			dp[i][j] = 0;
    			continue;
    		}
    		if(i == 0) continue;
    		if(i > j) continue;
    		int can = am[i];
    		if(j > can) continue;
    		dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + a[n - j]);
    	}
    }
    ll ans = inf;
    for(int i = 0; i <= log1; i++) {
    	ans = min(ans, dp[i][n - id1 - 1]);
    }
    cout << ans;
}