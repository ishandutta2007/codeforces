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
		int n;
		cin >> n;
		map<int, int> am;
		for(int i = 0; i < n; i++) {
			int c;
			cin >> c;
			am[c]++;
		}
		int bigger = n;
		long long ans = 0;
		for(const auto& el : am) {
			int here = el.second;
			bigger -= here;
			int smaller = n - bigger - here;
			ans = max(ans, (long long)(smaller + here) * bigger);
			ans = max(ans, (long long)(bigger + here) * smaller);
		}
		if(am.size() == 1) {
			ans = n / 2;
		}
		cout << ans << '\n';
	}
}