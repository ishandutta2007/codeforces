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
#define inf 2000000001
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int maxn = 100000;
const int maxm = 5;
const int K = 80;
vvi a;
int amount[maxn * maxm];
bitset<maxn>* b[maxn * maxm];
vi where[maxn * maxm];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	a.assign(n, vi(m + 1));
	{
		set<int> all;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m + 1; j++) {
				cin >> a[i][j];
				if(j < m) all.insert(a[i][j]);
			}
		}
		sort(a.begin(), a.end(), [](const vi& a, const vi& b) {return a.back() < b.back();});
		int now = 0;
		unordered_map<int, int> d;
		for(const auto& el : all) {
			d[el] = now++;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				a[i][j] = d[a[i][j]];
				++amount[a[i][j]];
			}
		}
	}
	for(int i = 0; i < n * m; i++) {
		if(amount[i] >= K) {
			b[i] = new bitset<maxn>();
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(amount[a[i][j]] >= K) {
				(*b[a[i][j]])[i] = true;
			} else {
				where[a[i][j]].push_back(i);
			}
		}
	}
	int ans = inf;
	for(int i = 0; i < n; i++) {
		bitset<maxn> here;
		for(int j = 0; j < m; j++) {
			if(amount[a[i][j]] >= K) {
				here = here | (*b[a[i][j]]);
			} else {
				for(const auto& el : where[a[i][j]]) {
					here[el] = true;
				}
			}
		}
		if(here.count() == n) continue;
		here = ~here;
		ans = min(ans, a[i].back() + a[here._Find_first()].back());
	}
	if(ans == inf) {
		cout << -1;
	} else {
		cout << ans;
	}

}