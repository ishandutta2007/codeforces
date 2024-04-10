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
int mod;
const int maxn = 20000;
int fact[maxn];
int rfact[maxn];

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
	for(int i = 1; i < maxn; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
		rfact[i] = obr(fact[i]);
	}
	rfact[0] = rfact[1];
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	cin >> mod;
	precalc();
	int ans = 0;
	int end = n - 1;
	if(n % 2 == 1) end = n - 2;
	for(int i = n / 2; i <= end; i++) {
		for(int j = 0; j <= n - i - 1; j++) {
			if(j == n - i - 1 && (n % 2 == 1 || i != end)) continue;
			int dst = n - i;
			int can = dst;
			int sd = 2;
			if(j == n - i - 1) sd = 1;
			if(n % 2 == 1) {
				--can;
			}
			if(can == 0) continue;
			int here = (ll)n * can % mod;
			here = (ll)here * fact[n - 1 - j - sd] % mod * c(dst - sd, j) % mod;
			//cout << i << ' ' << j << ' ' << dst << ' ' << sd << ' ' << here << endl;
			ans = (ans + here) % mod;
		}
	}
	cout << ans;
}