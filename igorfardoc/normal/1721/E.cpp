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
vi p;
vvi a;
string s;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> s;
	int n = s.size();
	p.push_back(0);
	a.push_back(vi(26, 0));
	a.back()[s[0] - 'a'] = 1;
	for(int i = 1; i < n; i++) {
		p.push_back(a.back()[s[i] - 'a']);
		a.push_back(vi(26));
		for(int j = 0; j < 26; j++) {
			if(j == s[p.back()] - 'a') {
				a.back()[j] = p.back() + 1;
			} else if(p.back() == 0) {
				a.back()[j] = 0;
			} else {
				a.back()[j] = a[p.back() - 1][j];
			}
		}
	}
	int q;
	cin >> q;
	for(int _ = 0; _ < q; _++) {
		string t;
		cin >> t;
		int m = t.size();
		s += t;
		for(int i = n; i < n + m; i++) {
			p.push_back(a.back()[s[i] - 'a']);
			cout << a.back()[s[i] - 'a'] << ' ';
			a.push_back(vi(26));
			for(int j = 0; j < 26; j++) {
				if(j == s[p.back()] - 'a') {
					a.back()[j] = p.back() + 1;
				} else if(p.back() == 0) {
					a.back()[j] = 0;
				} else {
					a.back()[j] = a[p.back() - 1][j];
				}
			}
		}
		for(int i = 0; i < m; i++) {
			s.pop_back();
			a.pop_back();
			p.pop_back();
		}
		cout << '\n';
	}
}