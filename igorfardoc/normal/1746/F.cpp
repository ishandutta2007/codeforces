#pragma GCC optimize("Ofast")
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

mt19937 rnd;
#define inf 2000000001
uniform_int_distribution<int> rng(-2000000000, 2000000000);

int get_random() {
	return rng(rnd);
}
const int maxn = 300000;
ll f[maxn];

void clear() {
	for(int i = 0; i < maxn; i++) f[i] = 0;
}

void update(int pos, ll val) {
	for(; pos < maxn; pos = pos | (pos + 1)) {
		f[pos] += val;
	}
}

ll get1(int pos) {
	if(pos == -1) return 0;
	ll res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		res += f[pos];
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, q;
	cin >> n >> q;
	vi a(n);
	vector<array<int, 4>> qu(q);
	vector<bool> ans(q, true);
	{
		set<int> all;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			all.insert(a[i]);
		}
		for(int i = 0; i < q; i++) {
			cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
			if(qu[i][0] == 2) {
				cin >> qu[i][3];
			} else {
				all.insert(qu[i][2]);
			}
		}
		unordered_map<int, int> d;
		int now = 0;
		for(const auto& el : all) {
			d[el] = now++;
		}
		for(int i = 0; i < n; i++) {
			a[i] = d[a[i]];
		}
		for(int i = 0; i < q; i++) {
			if(qu[i][0] == 1) {
				qu[i][2] = d[qu[i][2]];
			}
		}
	}
	vl b(n);
	vi val(n + q);
	for(int _ = 0; _ < 30; _++) {
		val.assign(n + q, inf);
		clear();
		for(int i = 0; i < n; i++) {
			if(val[a[i]] == inf) {
				val[a[i]] = get_random();
			}
			update(i, val[a[i]]);
			b[i] = val[a[i]];
		}
		for(int i = 0; i < q; i++) {
			if(qu[i][0] == 1) {
				int j = qu[i][1] - 1;
				int vl = qu[i][2];
				if(val[vl] == inf) {
					val[vl] = get_random();
				}
				update(j, val[vl] - b[j]);
				b[j] = val[vl];
			} else {
				int l, r, k;
				l = qu[i][1] - 1;
				r = qu[i][2] - 1;
				k = qu[i][3];
				ll rs = get1(r) - get1(l - 1);
				if(rs % k != 0) {
					ans[i] = false;
				}
			}
		}
	}
	for(int i = 0; i < q; i++) {
		if(qu[i][0] == 2) {
			if(ans[i]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}