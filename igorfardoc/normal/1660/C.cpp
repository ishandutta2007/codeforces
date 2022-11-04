#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		vvi poses(26);
		vi bef(n, -1);
		for(int i = 0; i < n; i++) {
			if(!poses[s[i] - 'a'].empty()) {
				bef[i] = poses[s[i] - 'a'].back();
			}
			poses[s[i] - 'a'].push_back(i);
		}
		vi dp(n + 1);
		dp[0] = 0;
		for(int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			if(bef[i - 1] != -1) {
				dp[i] = min(dp[i], dp[bef[i - 1]] + i - bef[i - 1] - 2);
			}
		}
		cout << dp[n] << '\n';
	}
}