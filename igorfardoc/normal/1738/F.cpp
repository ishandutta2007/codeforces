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
const int maxn = 1000;
int p[maxn];

int get_par(int a) {
	if(a == p[a]) return a;
	int par = get_par(p[a]);
	p[a] = par;
	return par;
}

bool eq(int a, int b) {
	return get_par(a) == get_par(b);
}

void join(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if(a == b) return;
	p[a] = b;
}



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
		vector<pair<int, int>> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
			p[i] = i;
		}
		sort(a.rbegin(), a.rend());
		vector<bool> used(n, false);
		for(int i = 0; i < n; i++) {
			int v = a[i].second;
			int st = a[i].first;
			if(used[v]) continue;
			used[v] = true;
			while(st--) {
				cout << "? " << v + 1 << endl;
				int u;
				cin >> u;
				--u;
				if(used[u]) {
					join(v, u);
					break;
				} else {
					used[u] = true;
					join(v, u);
				}
			}
		}
		vvi here(n);
		for(int i = 0; i < n; i++) {
			here[get_par(i)].push_back(i);
		}
		cout << "! ";
		vi ans(n);
		for(int i = 0; i < n; i++) {
			for(const auto& el1 : here[i]) {
				ans[el1] = i + 1;
			}
		}
		for(const auto& el : ans) {
			cout << el << ' ';
		}
		cout << endl;
	}

}