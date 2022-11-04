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
const int maxk = 2000;
const int mod = 998244353;
int stirling[maxk + 1][maxk + 1];
int fact[maxk + 1];

void precalc() {
	for(int i = 1; i <= maxk; i++) {
		stirling[i][1] = 1;
	}
	for(int i = 2; i <= maxk; i++) {
		for(int j = 2; j <= i; j++) {
			stirling[i][j] = (stirling[i - 1][j - 1] +
						     ((ll)stirling[i - 1][j] * j)) % mod;
	    }
	}
	fact[0] = 1;
	for(int i = 1; i <= maxk; i++) {
		fact[i] = ((ll)fact[i - 1] * i) % mod;
	}
}

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
		int n, m, k;
		cin >> n >> m >> k; // ans = sum(H(i) * m^(n - i) * am^i
		int obr1 = obr(m);
		int am = (m - 1) / 2 + 1; // H(i) = S(k, i) * i! * (n * n - 1 * ... * (n - i + 1))
		int ans = 0;
		int curr = 1;
		int curram = 1;
		int currm = bin_pow(m, n);
		for(int i = 1; i <= min(k, n); i++) {
			curr = (ll)curr * (n - i + 1) % mod;
			curram = (ll)curram * am % mod;
			currm = (ll)currm * obr1 % mod;
			int here = (ll)stirling[k][i] * curr % mod;
			here = (ll)here * curram % mod;
			here = (ll)here * currm % mod;
			ans = (ans + here) % mod;
		}
		cout << ans << '\n';
	}



}