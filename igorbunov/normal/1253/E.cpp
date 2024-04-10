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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {

    	int c, s;
    	cin >> c >> s;
    	arr[i].first = max(0LL, c - s);
    	arr[i].second = min(m, c + s);
    }

    vector<int> dp(m + 1);

    dp[m] = 0;

    for (int i = m - 1; i >= 0; i--) {
    	dp[i] = m - i;

    	for (int j = 0; j < n; j++) {
    		int l = arr[j].first;
    		int r = arr[j].second;

    		if (l <= i + 1 && i + 1 <= r) {
    			dp[i] = dp[i + 1];
    			break;
    		}

    		if (i < l) {
    			int cost = (l - i - 1);
    			int next = min(r + cost, m);

    			dp[i] = min(dp[i], cost + dp[next]);
    		}
    	}
    }

    cout << dp[0];
}