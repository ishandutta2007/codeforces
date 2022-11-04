#include<bits/stdc++.h>
#define int ll
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, p, k;
    cin >> n >> p >> k;
    vector<pair<int, vector<int>>> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
    	a[i].second.resize(p);
    	for(int j = 0; j < p; j++) {
    		cin >> a[i].second[j];
    	}
    }
    sort(a.rbegin(), a.rend());
    vvi dp(n + 1, vi(1 << p, -INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
    	for(int mask = 0; mask < (1 << p); mask++) {
    		int am = 0;
    		for(int j = 0; j < p; j++) {
    			if((mask >> j) & 1) {
    				++am;
    			}
    		}
    		if(am > i) {
    			continue;
    		}
    		for(int j = 0; j < p; j++) {
    			if((mask >> j) & 1) {
    				dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + a[i - 1].second[j]);
    			}
    		}
    		if(i - am <= k) {
    			dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + a[i - 1].first);
    		} else {
    			dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
    		}
    	}
    }
    cout << dp[n][(1 << p) - 1];
}