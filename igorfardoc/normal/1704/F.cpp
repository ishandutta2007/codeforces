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


const vi mass = {0, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 0, 5, 2, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 2, 7, 4, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5};

int get_val(int am) {
	if(am < 52) return mass[am];
	return mass[(am - 52) % 34 + 52];
}

int mex(vector<int> a) {
	set<int> s;
	for(const auto& el : a) {
		s.insert(el);
	}
	vector<int> b;
	for(const auto& el : s) b.push_back(el);
	for(int i = 0; i < b.size(); i++) {
		if(a[i] != i) return i;
	}
	return b.size();
}

signed main() {
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
		string s;
		cin >> s;
		int dt = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'R') {
				++dt;
			} else {
				--dt;
			}
		}
		if(dt > 0) {
			cout << "Alice\n";
			continue;
		} else if(dt < 0) {
			cout << "Bob\n";
			continue;
		}
		int ans = 0;
		int bef = 0;
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i - 1]) {
				ans ^= get_val(i - bef);
				bef = i;
			}
		}
		ans ^= get_val(n - bef);
		if(ans == 0) {
			cout << "Bob\n";
		} else {
			cout << "Alice\n";
		}
	}
}