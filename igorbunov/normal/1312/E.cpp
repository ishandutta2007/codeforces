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
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    vector<vector<int>> dp1(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
    	dp1[i][i] = arr[i];
    }

    for (int len = 1; len < n; len++) {
    	for (int i = 0; i < n - len; i++) {
    		int l = i;
    		int r = len + i;

    		for (int m = l; m < r; m++) {
    			if (dp1[l][m] == dp1[m + 1][r] && dp1[l][m] != -1) {
    				dp1[l][r] = dp1[l][m] + 1;
    				break;
    			}
    		}
    	}
    }

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
    	for (int j = i; j < n; j++) {
    		dp[i][j] = j - i + 1;

    		if (dp1[i][j] != -1) {
    			dp[i][j] = 1;
    		}
    	}
    }


    for (int len = 1; len < n; len++) {
    	for (int i = 0; i < n - len; i++) {
    		int l = i;
    		int r = len + i;

    		for (int m = l; m < r; m++) {
    			dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
    		}
    	}
    }

    cout << dp[0][n - 1];


}