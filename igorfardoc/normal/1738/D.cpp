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
		vi b(n);
		vvi where(n + 2);
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			where[b[i]].push_back(i + 1);
		}
		vi a;
		set<int> now;
		int kmin = 0;
		int kmax = n;
		bool less;
		int curr = 0;
		if(where[0].size() != 0) {
			less = true;
			for(const auto& el : where[0]) {
				kmax = min(kmax, el - 1);
				now.insert(el);
			}
			curr += where[0].size();
		} else {
			less = false;
			for(const auto& el : where[n + 1]) {
				kmin = max(kmin, el);
				now.insert(el);
			}
			curr += where[n + 1].size();
		}
		while(curr < n) {
			int good = -1;
			for(const auto& el : now) {
				if(where[el].size() != 0) {
					good = el;
					break;
				}
			}
			now.erase(now.find(good));
			for(const auto& el : now) {
				a.push_back(el);
			}
			now.clear();
			a.push_back(good);
			for(const auto& el : where[good]) {
				now.insert(el);
				if(less) {
					kmin = max(kmin, el);
				} else {
					kmax = min(kmax, el - 1);
				}
			}
			curr += now.size();
			less = 1 ^ less;
		}
		for(const auto& el : now) {
			a.push_back(el);
		}
		cout << kmin << '\n';
		for(const auto& el : a) {
			cout << el << ' ';
		}
		cout << '\n';
	}
}