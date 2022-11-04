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
const int maxn = 300000;
const int mod = 998244353;
int fact[maxn + 1];
int rfact[maxn + 1];

int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = (ll)res * res % mod;
	if(b & 1) res = (ll)res * a % mod;
	return res;
}

int obr(int a) {
	return bin_pow(a, mod - 2);
}

int c(int n, int k) {
	if(n < 0 || k < 0 || k > n) return 0;
	int res = (ll)fact[n] * rfact[k] % mod;
	res = (ll)res * rfact[n - k] % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fact[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
		rfact[i] = obr(fact[i]);
	}
	rfact[0] = rfact[1];
	vi dp1(maxn + 1);
	dp1[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		dp1[i] = dp1[i - 1];
		if(i >= 2) {
			dp1[i] = (dp1[i] + (ll)(i - 1) * dp1[i - 2]) % mod;
		}
	}
	vi dp2(maxn + 1);
	dp2[0] = 1;
	for(int i = 2; i <= maxn; i++) {
		dp2[i] = (ll)(i - 1) * dp2[i - 2] % mod;
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = 0;
		int curr2 = 1;
		for(int i = 0; i * 4 <= n; i++) {
			int res = (ll)c(n - i * 2, i * 2) * dp2[i * 2] % mod * curr2 % mod;
			res = (ll)res * dp1[n - i * 4] % mod;
			ans = (ans + res) % mod;
			curr2 = (curr2 + curr2) % mod;
		}
		cout << ans << '\n';
	}
}