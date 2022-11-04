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
		int n, m;
		cin >> n >> m;
		vi a(n);
		vi am(m + 1, 0);
		vi amount(m + 1, 0);
		vi dp(m + 1, 0);
		for(int i = 0; i <= m; i++) {
			dp[i] = i;
		}
		int mn = 1000000000;
		int mx = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			++am[a[i]];
			++amount[a[i]];
			mn = min(a[i], mn);
			mx = max(a[i], mx);
		}
		int ans = mx - mn;
		int ptr = m;
		for(int i = m - 1; i >= 1; i--) {
			for(ll j = (ll)i * i; j <= m; j += i) {
				am[dp[j]] -= amount[j];
				dp[j] = min(dp[j], max(dp[j / i], (int)i));
				am[dp[j]] += amount[j];
			}
			if(i > mn) continue;
			while(am[ptr] == 0) --ptr;
			ans = min(ans, ptr - i);
		}
		cout << ans << '\n';
	}
}