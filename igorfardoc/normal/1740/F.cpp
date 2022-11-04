#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, typename Cmp = less<T>> using ordered_set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename Cmp = less_equal<T>> using ordered_multiset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename T, typename Cmp = less<K>> using ordered_map = tree<K, T, Cmp, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(), order_of_key()
*/
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	map<int, int> d;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		++d[a];
	}
	vi a;
	for(const auto& el : d) {
		a.push_back(el.second);
	}
	int m = a.size();
	sort(a.rbegin(), a.rend());
	vi pref;
	pref.push_back(0);
	while(!d.empty()) {
		pref.push_back(pref.back() + d.size());
		vi del;
		for(auto& el : d) {
			--el.second;
			if(el.second == 0) del.push_back(el.first);
		}
		for(const auto& el : del) d.erase(el);
	}
	while(pref.size() <= n) pref.push_back(pref.back());
	vector<vvi> dp(n + 1, vvi(n + 1));
	for(int i = 0; i <= n; i++) {
		dp[0][0].push_back(1);
	}
	int ans = 0;
	for(int len = 1; len <= n; ++len) {
		for(int sum = len; sum <= pref[len]; ++sum) {
			int mx = min(sum / len, m);
			dp[len][sum].assign(mx + 1, 0);
			for(int mn = 1; mn <= mx; ++mn) {
				if(dp[len - 1][sum - mn].size() <= mn) continue;
				dp[len][sum][mn] = dp[len - 1][sum - mn][mn];
			}
			for(int i = mx - 1; i >= 0; i--) {
				dp[len][sum][i] = (dp[len][sum][i] + dp[len][sum][i + 1]) % mod;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!dp[i][n].empty()) ans = (ans + dp[i][n][0]) % mod;
	}
	cout << ans;
}