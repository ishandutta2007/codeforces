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
		int n, k;
		cin >> n >> k;
		vi a(n);
		vi b(k);
		vi lst;
		for(int i = 0; i < k; i++) {
			cin >> b[i];
			if(i != 0) {
				lst.push_back(b[i] - b[i - 1]);
			}
		}
		if(k == 1) {
			cout << "YES\n";
			continue;
		}
		bool ok = true;
		for(int i = 0; i < (int)lst.size() - 1; i++) {
			if(lst[i + 1] < lst[i]) ok = false;
		}
		if(!ok) {
			cout << "NO\n";
			continue;
		}
		int other = n - k + 1;
		ll mx = (ll)lst[0] * other;
		if(b[0] <= mx) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}