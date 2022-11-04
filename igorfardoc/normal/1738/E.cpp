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
const int mod = 998244353;

int fact[maxn + 1], rfact[maxn + 1];
int p[maxn + 1];

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
	if(k == 0) return 1;
	if(n < 0 || k < 0 || k > n) return 0;
	int res = (ll)fact[n] * rfact[k] % mod;
	res = (ll)res * rfact[n - k] % mod;
	return res;
}


void precalc() {
	fact[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		fact[i] = (ll)fact[i - 1] * i % mod;
		rfact[i] = obr(fact[i]);
	}
	rfact[0] = rfact[1];
	p[0] = 1;
	for(int i = 1; i <= maxn; i++) {
		p[i] = (p[i - 1] + p[i - 1]) % mod;
	}
}

int calc(int a, int b) {
	if(a > b) swap(a, b);
	int res = 0;
	for(int i = 0; i <= a; i++) {
		res = (res + (ll)c(a, i) * c(b, i)) % mod;
	}
	return res;
}
int calc1(int a, int b) {
	if(a > b) swap(a, b);
	int res = 0;
	for(int i = 1; i <= a + 1; i++) {
		res = (res + (ll)c(a + 1, i) * c(b + 1, i)) % mod;
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
	precalc();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		int bef = 0;
		vi b;
		vi c;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 0) {
				++bef;
			} else {
				b.push_back(a[i]);
				c.push_back(bef);
				bef = 0;
			}
		}
		if(b.size() == 0) {
			cout << p[n - 1] << '\n';
			continue;
		}
		c.push_back(bef);
		map<ll, int> suff;
		ll now = 0;
		for(int i = (int)b.size() - 1; i >= 0; i--) {
			now += b[i];
			suff[now] = i;
		}
		vl pref(b.size() + 1);
		pref[0] = 0;
		for(int i = 1; i <= (int)b.size(); i++) {
			pref[i] = pref[i - 1] + b[i - 1];
		}
		int ans = 0;
		int sumall = 1;
		for(int i = (int)b.size() - 1; i >= 0; i--) {
			auto it = suff.find(pref[i + 1]);
			if(it == suff.end()) continue;
			if(it->second <= i) continue;
			int j = it->second;
			int fir = c[i + 1];
			int sec = c[j];
			int sumhere = 0;
			if(j == i + 1) {
				sumhere = p[c[j] + 1] - 1;
			} else {
				sumhere = (ll)sumall * calc1(fir, sec) % mod;
			}
			sumall = (sumall + sumhere) % mod;
		}
		ans = (ll)sumall * calc(c[0], c.back()) % mod;
		cout << ans << '\n';
	}
}