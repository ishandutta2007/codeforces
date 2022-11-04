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
		if(n > m) {
			cout << "No\n";
			continue;
		}
		if(n % 2 == 0 && m % 2 == 1) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		if(n % 2 == 1) {
			for(int i = 0; i < n - 1; i++) {
				cout << 1 << ' ';
			}
			cout << m - n + 1 << '\n';
		} else {
			for(int i = 0; i < n - 2; i++) {
				cout << 1 << ' ';
			}
			cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
		}
	}
}