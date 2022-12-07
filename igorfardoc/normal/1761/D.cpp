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
const int mod = 1000000007;
const int maxn = 2000007;
int fact[maxn];
int rfact[maxn];
int p[maxn];
int p3[maxn];

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

void precalc() {
	fact[0] = 1;
	p[0] = 1;
	p3[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
		rfact[i] = obr(fact[i]);
		p[i] = (p[i - 1] + p[i - 1]) % mod;
		p3[i] = (ll)p3[i - 1] * 3 % mod;
	}
	rfact[0] = rfact[1];
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
	precalc();
	int n, k;
	cin >> n >> k;
	int ans = 0;
	if(k == 0) {
		for(int i = 0; i <= n; i++) {
			ans = (ans + (ll)c(n, i) * p[n - i]) % mod;
		}
		cout << ans;
		return 0;
	}
	for(int am = 1; am <= k; am++) {
		int amount = c(k - 1, am - 1);
		int len = k + (am - 1);
		int mx = n - len;
		if(len > n) break;
		{
			int rs = (ll)amount * c(mx + am - 1, am - 1) % mod;
			rs = (ll)rs * p3[k - am] % mod * p3[mx] % mod;
			ans = (ans + rs) % mod;
		}
		if(len + 1 > n) break;
		{
			int rs = (ll)amount * c(mx + am - 1, am) % mod;
			rs = (ll)rs * p3[k - am] % mod * p3[mx - 1] % mod;
			ans = (ans + rs) % mod;
		}
	}
	cout << ans;
}