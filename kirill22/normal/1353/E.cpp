#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, k;
    cin >> q;
    while (q--) {
	    cin >> n >> k;
	    string s;
	    cin >> s;
	    int ans = n, tmp = 0;
	    vector<int> dp(k, 0), cnt(k, 0);
	    for (int i = 0; i < n; i++) {
	    	dp[i % k] = min(dp[i % k], 2 * cnt[i % k] - (i - i % k) / k);
	    	tmp += (s[i] == '1');
	    	cnt[i % k] += (s[i] == '1');
	    	ans = min(ans, (i - i % k) / k + 1 - 2 * cnt[i % k] + dp[i % k]);
	    }
	    cout << min(ans + tmp, tmp) << endl;
    }
}