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
		string s;
		cin >> s;
		s += s;
		int am = 0;
		for(int i = 0; i < n; i++) {
			am += (s[i] == '1');
		}
		if((ll)am * m % n != 0) {
			cout << -1 << '\n';
			continue;
		}
		int need = (ll)am * m / n;
		int now = 0;
		for(int i = 0; i < m; i++) {
			now += (s[i] == '1');
		}
		for(int i = 0; i < n; i++) {
			if(now == need) {
				if(i < n - m + 1) {
					cout << "1\n";
					cout << i + 1 << ' ' << i + m << '\n';
					break;
				} else {
					cout << "2\n";
					cout << 1 << ' ' << m - (n - i) << '\n';
					cout << i + 1 << ' ' << n << '\n';
					break;
				}
			}
			now -= (s[i] == '1');
			now += (s[i + m] == '1');
		}
	}
}