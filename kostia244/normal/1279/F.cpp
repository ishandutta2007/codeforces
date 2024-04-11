#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<20;
using ld = int;
bool lower(char c) {
	return c >= 'a' && c <= 'z';
}
int n, k, l, a[maxn];
pair<ld, int> dp[maxn];
void insert(deque<pair<ld, int>> &q, pair<ld, int> x) {
	while(!q.empty() && q.back() > x) q.pop_back();
	q.push_back(x);
}
void erase(deque<pair<ld, int>> &q, pair<ld, int> x) {
	if(q.front() == x) q.pop_front();
}
pair<ld, int> solve(ld y) {
	dp[0] = {0, 0};
	deque<pair<ld, int>> q;
	insert(q, {y, 1});
	//cout << "F: " << y << endl;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		dp[i].first += a[i];
		dp[i] = min(dp[i], q.front());
		if(i >= l) erase(q, {dp[i-l].first+y, dp[i-l].second+1});
		insert(q, {dp[i].first+y, dp[i].second+1});
		//cout << dp[i].first << " " << dp[i].second << '\n';
	}
	return dp[n];
}
int solve() {
	ld lo = 0, hi = n+1;
	while(hi-lo > 0) {
		ld mid = lo + (hi-lo)/2;
		if(solve(mid).second > k) lo = mid+1;
		else hi = mid;
	}
	return round(solve(hi).first - lo*k);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k >> l;
	char c;
	for(int i = 1; i <= n; i++) {
		cin >> c;
		a[i] = lower(c);
	}
	int ans = solve();
	for(int i = 1; i <= n; i++) a[i] ^= 1;
	cout << min(ans, solve()) << '\n';
}