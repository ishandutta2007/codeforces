#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	int inf = (int)1e9;
	vector<int> r(n), l(n, inf);
	for(int i = 0; i < n; ++i){
		cin >> a[i]; --a[i];
		r[a[i]] = i;
		l[a[i]] = min(l[a[i]], i);
	}
	int nd = 0;
	vector<int> cnt(n), dp(n);
	for(int i = n - 1; i >= 0; --i){
		++cnt[a[i]];
		if(i < n - 1){
			dp[i] = dp[i + 1];
		}
		if(i == l[a[i]]){
			dp[i] = max(dp[i], cnt[a[i]] + (r[a[i]] + 1 < n ? dp[r[a[i]] + 1] : 0));
		}
		dp[i] = max(dp[i], cnt[a[i]]);
	}
	cout << n - dp[0];
	return 0;
}