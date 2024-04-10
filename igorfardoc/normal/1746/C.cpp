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
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vi ans(n, 1);
		set<int> there;
		for(int i = 1; i <= n; i++) {
			there.insert(i);
		}
		for(int i = 1; i < n; i++) {
			if(a[i] < a[i - 1]) {
				int need = a[i - 1] - a[i];
				auto it = there.lower_bound(need);
				ans[*it - 1] = i + 1;
				there.erase(it);
			}
		}
		for(int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}