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
const int maxn = 2000000;
int p[maxn + 1];
int rp[maxn + 1];

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
	p[0] = 1;
	rp[0] = obr(p[0]);
	int o2 = obr(2);
	for(int i = 1; i <= maxn; i++) {
		p[i] = (p[i - 1] + p[i - 1]) % mod;
		rp[i] = ((ll)rp[i - 1] * o2) % mod;
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	precalc();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) {
			cout << "1\n";
			continue;
		}
		vi dp(n);
		for(int i = n - 1; i >= n / 2; i--) {
			dp[i] = 1;
		}
		int st = n / 2 - 1;
		int now = 0;
		for(int i = st + 1; i <= st * 2; i++) {
			now = (now + (ll)dp[i] * rp[i - st]) % mod;
		}
		int r = st * 2;
		for(int i = st; i >= 0; i--) {
			dp[i] = now;
			if(i == 0) break;
			now = (now + dp[i]) % mod;
			now = (ll)now * rp[1] % mod;
			while(r > (i - 1) * 2) {
				int there = (ll)dp[r] * rp[r - i + 1] % mod;
				now = (mod + now - there) % mod;
				--r;
			}
		}
		for(int i = 0; i < n; i++) {
			int l = 1;
			if(i > 0) {
				int am = (i + 2) / 2;
				int lf = i + 1 - am;
				l = (ll)p[lf] * rp[i + 1] % mod;
			}
			if(i == n - 1) {
				l = (l + l) % mod;
			}
			int ans = (ll)l * dp[i] % mod;
			cout << ans << '\n';
		}
	}

}