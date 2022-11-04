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
const int mod = 998244353;
const int mx = 720720;
const int maxk = 17;
int n, k;
int dp[mx + 1][maxk + 1];
int fact[maxk + 1];
int rfact[maxk + 1];

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


void precalc() {
	fact[0] = 1;
	for(int i = 1; i <= maxk; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
		rfact[i] = obr(fact[i]);
	}
	rfact[0] = rfact[1];
	for(int k1 = k - 1; k1 >= 0; k1--) {
		for(int i = 0; i <= mx; i++) {
			dp[i][k1] = ((ll)(n - 1) * dp[i][k1 + 1] + dp[i - i % (k1 + 1)][k1 + 1] + (ll)i * bin_pow(n, k - k1 - 1)) % mod;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int a, x, y, M;
	cin >> n >> a >> x >> y >> k >> M;
	precalc();
	int amount = 0;
	for(int i = 1; i <= k; i++) {
		amount = (amount + (ll)c(k, i) * i % mod * bin_pow(n - 1, k - i)) % mod;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = (ans + dp[a % mx][0]) % mod;
		int other = a / mx * mx;
		ans = (ans + (ll)amount * other) % mod;
		a = ((ll)a * x + y) % M;
	}
	cout << ans;
}