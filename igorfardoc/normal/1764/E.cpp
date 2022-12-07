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
		int a1, b1;
		cin >> a1 >> b1;
		vector<pair<int, int>> a(n - 1);
		for(int i = 0; i < n - 1; i++) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a.begin(), a.end());
		if(a1 >= k) {
			cout << "YES\n";
			continue;
		}
		if(n == 1 || a1 + b1 < k) {
			cout << "NO\n";
			continue;
		}
		int l = k - b1;
		int r = a1;
		if(a.back().first >= l) {
			cout << "YES\n";
			continue;
		}
		bool ok = false;
		while(a.size() >= 2) {
			pair<int, int> p2 = a.back();
			a.pop_back();
			pair<int, int> p1 = a.back();
			if(p2.first >= l || p1.first + p2.second >= l || p1.first + p1.second >= l) {
				ok = true;
				break;
			}
			if(l - p2.second <= p2.first) {
				l = l - p2.second;
			}
		}
		if(a.back().first >= l) ok = true;
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}


}