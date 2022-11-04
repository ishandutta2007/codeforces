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
		int n, q;
		cin >> n >> q;
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vi dv;
		int nw = n;
		int curr = 2;
		while(curr * curr <= nw) {
			if(nw % curr == 0) {
				dv.push_back(n / curr);
			}
			while(nw % curr == 0) nw /= curr;
			++curr;
		}
		if(nw != 1) dv.push_back(n / nw);
		vector<vl> weight(dv.size());
		vvi where(dv.size(), vi(n, -1));
		multiset<ll> ans;
		for(int i = 0; i < dv.size(); i++) {
			int here = dv[i];
			for(int j = 0; j < n; j++) {
				if(where[i][j] != -1) continue;
				weight[i].push_back(0);
				int v = j;
				int amount = 0;
				while(where[i][v] == -1) {
					++amount;
					where[i][v] = weight[i].size() - 1;
					weight[i].back() += a[v];
					v = (v + here) % n;
				}
				weight[i].back() *= n / amount;
				ans.insert(weight[i].back());
			}
		}
		cout << *(ans.rbegin()) << '\n';
		for(int i = 0; i < q; i++) {
			int p, x;
			cin >> p >> x;
			--p;
			for(int j = 0; j < dv.size(); j++) {
				int here = dv[j];
				ans.erase(ans.find(weight[j][where[j][p]]));
				weight[j][where[j][p]] += (ll)(x - a[p]) * weight[j].size();
				ans.insert(weight[j][where[j][p]]);
			}
			a[p] = x;
			cout << *(ans.rbegin()) << '\n';
		}
	}
}