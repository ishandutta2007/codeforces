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
const int maxm = 16;
int m;
int a[maxm+2][maxm+2];
int b[maxm+2][maxm+2];
const int mod = 998244353;
int ans = 1;


void solve() {
	vi dp0(m), dp1(m);
	dp0[1] = 0;
	dp1[1] = b[0][1];
	for(int i = 2; i < m; i++) {
		dp1[i] = b[0][i];
		for(int j = 1; j < i; j++) {
			dp1[i] = (dp1[i] + (ll)dp0[j] * b[j][i]) % mod;
			dp0[i] = (dp0[i] + (ll)dp1[j] * b[j][i]) % mod;
		}
	}
	int res = 0;
	res = (res + mod - dp0[m - 1]) % mod;
	res = (res + dp1[m - 1]) % mod;
	cout << res << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int d, n;
	cin >> d >> n >> m;
	vi l(n);
	for(int i = 0; i < n; i++) {
		cin >> l[i];
	}
	vi ps(m);
	for(int i = 0; i < m; i++) {
		cin >> ps[i];
	}
	for(int i = 0; i < n + 1; i++) {
		ans = (ll)ans * (d + 1) % mod;
	}
	ps.push_back(-1000000);
	ps.push_back(1000000);
	sort(ps.begin(), ps.end());
	m += 2;
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			a[i][j] = 1;
			for(const auto& el : l) {
				if(el < ps[i] || el > ps[j]) continue;
				int here = min(el - ps[i], ps[j] - el);
				here = min(here, d + 1);
				a[i][j] = (ll)a[i][j] * here % mod;
			}
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		for(int i = 0; i < m; i++) {
			for(int j = i + 1; j < m; j++) {
				b[i][j] = a[i][j];
				if(x < ps[i] || x > ps[j]) continue;
				int here = min(x - ps[i], ps[j] - x);
				here = min(here, d + 1);
				b[i][j] = (ll)b[i][j] * here % mod;
			}
		}
		solve();
	}

}