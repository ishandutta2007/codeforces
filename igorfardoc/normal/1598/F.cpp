#include<bits/stdc++.h>
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
    vector<string> s(n);
    vector<int> min1(n, 100);
    vector<vector<vector<int>>> bal(n);
    vector<int> balance(n);
    vector<vector<int>> firstbal(n), firstbal1(n);
    for(int i = 0; i < n; i++) {
    	cin >> s[i];
    	int now = 0;
    	bal[i].resize(s[i].size());
    	firstbal[i].assign(s[i].size(), s[i].size());
    	firstbal1[i].assign(s[i].size(), s[i].size());
    	for(int j = 0; j < s[i].size(); j++) {
    		if(s[i][j] == '(') {
    			++now;
    		} else {
    			--now;
    		}
    		min1[i] = min(min1[i], now);
    	}
    	balance[i] = now;
    	now = 0;
    	for(int j = 0; j < s[i].size(); j++) {
    		if(s[i][j] == '(') {
    			++now;
    		} else {
    			--now;
    		}
    		bal[i][now - min1[i]].push_back(j);
    		firstbal[i][now - min1[i]] = min(firstbal[i][now - min1[i]], j);
    	}
    	firstbal1[i][0] = firstbal[i][0];
    	for(int j = 1; j < s[i].size(); j++) {
    		firstbal1[i][j] = min(firstbal1[i][j - 1], firstbal[i][j]);
    	}
    }
    int ans = 0;
    vector<int> dp(1 << n);
    dp[0] = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
    	int sum = 0;
    	for(int i = 0; i < n; i++) {
    		if(!((mask >> i) & 1)) {
    			continue;
    		}
    		sum += balance[i];
    	}
    	dp[mask] = -1;
    	for(int i = 0; i < n; i++) {
    		if(!((mask >> i) & 1)) {
    			continue;
    		}
    		int balprev = sum - balance[i];
    		if(balprev < 0 || dp[mask ^ (1 << i)] == -1) {
    			continue;
    		}
    		int res = dp[mask ^ (1 << i)];
    		int to = s[i].size();
    		int bad = -balprev - 1;
    		if(bad - min1[i] >= 0 && bad - min1[i] < bal[i].size()) {
    			to = firstbal1[i][bad - min1[i]];
    		}
    		if(-balprev - min1[i] >= 0 && -balprev - min1[i] < bal[i].size()) {
    			res += lower_bound(bal[i][-balprev - min1[i]].begin(), bal[i][-balprev - min1[i]].end(), to) - bal[i][-balprev - min1[i]].begin();
    		}
    		ans = max(ans, res);
    		if(balprev + min1[i] >= 0) {
    			dp[mask] = max(dp[mask], res);
    		}
    	}
    }
    cout << ans;
}