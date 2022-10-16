#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

signed main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (i + j == 0) {
    			dp[i][j] = (a[i] == b[j]) * 4 - 2;
    			continue;
    		}
    		if (i == 0) {
    			dp[i][j] = -2;
    			for (int k = j; k > max(-1LL, j - 4); k--) {
    				if (a[i] == b[k]) {
    					dp[i][j] = 4 - (1 + (j - k + 1));
    					break;
    				}
    			}
    			continue;
    		}
    		if (j == 0) {
    			dp[i][j] = -2;
    			for (int k = i; k > max(-1LL, i - 4); k--) {
    				if (a[k] == b[j]) {
    					dp[i][j] = 4 - (1 + (i - k + 1));
    					break;
    				}
    			}
    			continue;
    		}
    		if (a[i] == b[j]) {
    			dp[i][j] = 2 + max(dp[i - 1][j - 1], 0LL);
    		} else {
    			dp[i][j] = max(-2LL, max(dp[i][j - 1] - 1, dp[i - 1][j] - 1));
    		}
    		//dp[i][j] = dp[i - 1][j - 1] + ((a[i] == b[j]) * 4LL) - 2;

    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		ans = max(ans, dp[i][j]);
    		//cout << dp[i][j] << " ";
    	}
    	//cout << endl;
    }
    //cout << dp[1][1] << endl;
    //cout << dp[n - 1][m - 1];
    cout << ans;
}