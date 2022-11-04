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
const int maxn = 100;
int x[maxn];
int y[maxn];

int dst(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vi mn(n, mod);
	vi amount(n, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			mn[i] = min(mn[i], dst(i, j));
		}
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(mn[i] == dst(i, j)) ++amount[i];
		}
	}
	vector<bool> used(n, false);
	vi am;
	for(int i = 0; i < n; i++) {
		if(used[i]) continue;
		vi all;
		all.push_back(i);
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(mn[i] == dst(i, j)) all.push_back(j);
		}
		bool ok = true;
		for(const auto& el : all) {
			if(used[el]) ok = false;
		}
		if(!ok) {
			used[i] = true;
			am.push_back(1);
			continue;
		}
		for(const auto& el1 : all) {
			for(const auto& el2 : all) {
				if(el1 == el2) continue;
				if(dst(el1, el2) != mn[el1] || dst(el1, el2) != mn[el2]) {
					ok = false;
					break;
				}
			}
			if(all.size() - 1 != amount[el1]) ok = false;
			if(!ok) break;
		}
		if(!ok) {
			used[i] = true;
			am.push_back(1);
			continue;
		}
		am.push_back(all.size());
		for(const auto& el : all) {
			used[el] = true;
		}
	}
	vvi dp(am.size() + 1, vi(n + 1, 0));
	for(int i = 0; i <= n; i++) {
		dp[0][i] = 1;
	}
	for(int i = 1; i <= am.size(); i++) {
		for(int j = 0; j <= n; j++) {
			if(am[i - 1] > j) continue;
			dp[i][j] = (ll)j * dp[i - 1][j - 1] % mod;
			if(am[i - 1] == 1) continue;
			int here = 1;
			for(int k = 0; k < am[i - 1]; k++) {
				here = (ll)here * (j - k) % mod;
			}
			here = (ll)here * dp[i - 1][j - am[i - 1]] % mod;
			dp[i][j] = (dp[i][j] + here) % mod;
		}
	}
	cout << dp[am.size()][n];
}