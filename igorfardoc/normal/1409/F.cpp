#include<bits/stdc++.h>
#define MAX 200
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dp[MAX + 1][MAX + 1][MAX + 1];
int dp1[MAX + 1][MAX + 1][MAX + 1];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= n; j++) { // know
    		for(int l = 0; l <= n; l++) { // amount second right
    			if(i == 0) {
    				if(j == 0) {
						dp[i][j][l] = 0;
					} else {
						dp[i][j][l] = -INF;
					}
    				continue;
    			}
    			int need = l + (s[i - 1] == t[1]);
    			dp[i][j][l] = dp[i - 1][j][need];
    			if(j != 0 && s[i - 1] != t[0]) {
    				dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l + (t[0] == t[1])] + l);
    			}
    			if(s[i - 1] == t[0]) {
    				dp[i][j][l] += l;
    			}
    		}
    	}
    }
    for(int i = n; i >= 0; i--) {
    	for(int j = 0; j <= n; j++) { // know
    		for(int l = 0; l <= n; l++) { // amount first left
    			if(i == n) {
					if(j == 0) {
						dp1[i][j][l] = 0;
					} else {
						dp1[i][j][l] = -INF;
					}
    				continue;
    			}
    			int need = l + (s[i] == t[0]);
    			dp1[i][j][l] = dp1[i + 1][j][need];
    			if(j != 0 && s[i] != t[1]) {
    				dp1[i][j][l] = max(dp1[i][j][l], dp1[i + 1][j - 1][l + (t[0] == t[1])] + l);
    			}
    			if(s[i] == t[1]) {
    				dp1[i][j][l] += l;
    			}
    		}
    	}
    }
    vi pref(n + 1), suff(n + 1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
    	pref[i] = pref[i - 1] + (s[i - 1] == t[0]);
    }
    suff[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
    	suff[i] = suff[i + 1] + (s[i] == t[1]);
    }

    int res = -INF;
    //cout << dp[2][1][4] << endl;
    //cout << dp1[2][1][2] << endl;
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= k; j++) {
    		for(int l = 0; j + l <= k; l++) {
    			res = max(res, dp[i][j][l + suff[i]] + dp1[i][l][j + pref[i]] - (j + pref[i]) * (l + suff[i]));
    			//cout << i << ' ' << j << ' ' << l << ' ' << res << endl;
    		}
    	}
    }
    cout << res;
}