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
		int n, m, k;
		cin >> n >> m >> k;
		vi a(k);
		for(int i = 0; i < k; i++) {
			cin >> a[i];
			--a[i];
		}
		set<int> curr;
		int ptr = 0;
		bool ok = true;
		for(int i = k - 1; i >= 0; i--) {
			auto it = curr.find(i);
			if(it != curr.end()) {
				curr.erase(it);
				continue;
			}
			while(a[ptr] != i) {
				curr.insert(a[ptr]);
				++ptr;
			}
			if(curr.size() > n * m - 4) {
				ok = false;
				break;
			}
			++ptr;
		}
		if(ok) {
			cout << "YA\n";
		} else {
			cout << "TIDAK\n";
		}
	}
}