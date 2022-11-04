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
	int n;
	cin >> n;
	ll sum = 0;
	vl a(n + 1);
	for(int i = 0; i < n; i++) {
		int c, d;
		cin >> c >> d;
		sum += c;
		a[i] = d - c;
	}
	a[n] = 2000000000;
	sort(a.rbegin(), a.rend());
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}
	int m;
	cin >> m;
	vl ans(m, -1);
	vector<array<int, 3>> q(m);
	for(int i = 0; i < m; i++) {
		cin >> q[i][0] >> q[i][1];
		q[i][2] = i;
	}
	sort(q.begin(), q.end());
	for(int i = 0; i < m; i++) {
		if(i != 0 && q[i][0] == q[i - 1][0] && q[i][1] == q[i - 1][1]) {
			ans[q[i][2]] = ans[q[i - 1][2]];
			continue;
		}
		if(q[i][0] >= q[i][1]) {
			for(int j = 0; j * q[i][0] <= n; ++j) {
				if((n - j * q[i][0]) % q[i][1] == 0) {
					ans[q[i][2]] = max(ans[q[i][2]], sum + a[n - j * q[i][0]]);
				}
			}
		} else {
			for(int j = 0; j * q[i][1] <= n; ++j) {
				if((n - j * q[i][1]) % q[i][0] == 0) {
					ans[q[i][2]] = max(ans[q[i][2]], sum + a[j * q[i][1]]);
				}
			}
		}
	}
	for(const auto& el : ans) {
		cout << el << '\n';
	}
}