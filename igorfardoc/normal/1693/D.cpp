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
const int maxn = 200000;
int dp1[maxn], dp2[maxn]; // dp1 - last increasing
int f[maxn + 1];
int a[maxn];
int n;

void upd(int i) {
	if(i >= n) return;
	int dp1here = 0;
	int dp2here = n + 1;
	if(a[i - 1] < a[i]) {
		dp1here = max(dp1here, dp1[i - 1]);
	}
	if(dp2[i - 1] < a[i]) {
		dp1here = max(dp1here, a[i - 1]);
	}
	if(a[i - 1] > a[i]) {
		dp2here = min(dp2here, dp2[i - 1]);
	}
	if(dp1[i - 1] > a[i]) {
		dp2here = min(dp2here, a[i - 1]);
	}
	if(dp1here == dp1[i] && dp2here == dp2[i]) return;
	dp1[i] = dp1here; dp2[i] = dp2here;
	upd(i + 1);
	f[i] = f[i + 1] + (dp1[i] != 0 || dp2[i] != n + 1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n == 1) {
		cout << 1;
		return 0;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(i != n - 1) {
			dp1[i] = n + 1;
			dp2[i] = 0;
			upd(i + 1);
			f[i] = 1 + f[i + 1];
		}
		ans += f[i];
	}
	cout << ans;
}