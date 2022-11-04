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
		vi fir, sec;
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			int b;
			cin >> b;
			ans += b;
			if(a[i]) {
				fir.push_back(b);
			} else {
				sec.push_back(b);
			}
		}
		sort(sec.begin(), sec.end());
		sort(fir.begin(), fir.end());
		reverse(fir.begin(), fir.end());
		reverse(sec.begin(), sec.end());
		int ps1 = 0;
		int ps2 = 0;
		for(int i = 0; i < min((int)fir.size(), (int)sec.size() - 1); i++) {
			ans += fir[i];
			ps1 = i + 1;
		}
		for(int i = 0; i < min((int)fir.size() - 1, (int)sec.size()); i++) {
			ans += sec[i];
			ps2 = i + 1;
		}
		int here = 0;
		if(ps1 < fir.size() && sec.size()) {
			here = max(here, fir[ps1]);
		}
		if(ps2 < sec.size() && fir.size()) {
			here = max(here, sec[ps2]);
		}
		ans += here;
		cout << ans << '\n';
	}
}