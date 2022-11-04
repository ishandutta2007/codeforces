#include<bits/stdc++.h>
#define INF 1000000000
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vvi am(m, vi(m, 0));
    for(int i = 0; i < n - 1; i++) {
    	int fir = s[i] - 'a';
    	int sec = s[i + 1] - 'a';
    	if(fir > sec) {
    		swap(fir, sec);
    	}
    	am[fir][sec]++;
    }
    vi dp(1 << m, INF);
    for(int mask = 0; mask < 1 << m; mask++) {
    	if(mask == 0) {
    		dp[mask] = 0;
    		continue;
    	}
    	int am1 = __builtin_popcount(mask);
    	for(int last = 0; last < m; last++) {
    		if(!((mask >> last) & 1)) {
    			continue;
    		}
    		int mask1 = mask ^ (1 << last);
    		int ans = 0;
    		for(int j = 0; j < m; j++) {
    			if(j == last) continue;
    			if((mask1 >> j) & 1) {
    				ans += am[min(j, last)][max(j, last)] * am1;
    			} else {
    				ans -= am[min(j, last)][max(j, last)] * am1;
    			}
    		}
    		dp[mask] = min(dp[mask], ans + dp[mask1]);
    	}
    }
    cout << dp[(1 << m) - 1];
}