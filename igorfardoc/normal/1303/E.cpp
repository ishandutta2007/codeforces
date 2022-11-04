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
    int t;
    cin >> t;
    while(t--) {
    	string s, t;
    	cin >> s >> t;
    	int n = s.size();
    	int k = t.size();
    	vvi dp(k + 1, vi(k + 1, INF));
    	for(int i = 0; i <= k; i++) {
    		for(int j = 0; j <= k; j++) {
    			if(i == 0) {
    				dp[i][j] = j;
    			}
    		}
    	}
    	for(int i = 1; i <= n; i++) {
    		vvi dpnew(k + 1, vi(k + 1, INF));
    		for(int j = 0; j <= k; j++) {
    			for(int l = j; l <= k; l++) {
    				if(j == 0 && l == 0) {
    					dpnew[j][l] = 0;
    					continue;
    				}
    				dpnew[j][l] = dp[j][l];
    				if(j != 0 && t[j - 1] == s[i - 1]) {
    					dpnew[j][l] = min(dpnew[j][l], dp[j - 1][l]);
    				}
    				if(l != 0 && t[l - 1] == s[i - 1]) {
    					dpnew[j][l] = min(dpnew[j][l], dp[j][l - 1]);
    				}
    				if(j == 0) {
    					dpnew[j][l] = min(dpnew[j][l], l);
    				}
    			}
    		}
    		dp = dpnew;
    	}
    	bool ok = false;
    	for(int i = 0; i <= k; i++) {
    		if(dp[i][k] <= i) {
    			ok = true;
    			break;
    		}
    	}
    	if(ok) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}