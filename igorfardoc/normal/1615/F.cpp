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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < n; i+=2) {
			if(s[i] != '?') {
				s[i] = '1' + '0' - s[i];
			}
			if(t[i] != '?') {
				t[i] = '1' + '0' - t[i];
			}
		}
		vvi dp1(n + 1, vi(2 * n + 1, 0));
		vvi dp2(n + 1, vi(2 * n + 1, 0));
		dp1[0][n] = 1;
		dp2[n][n] = 1;
		for(int i = 1; i <= n; i++) {
			vi fir;
			vi sec;
			if(s[i - 1] != '0') fir.push_back(1);
			if(s[i - 1] != '1') fir.push_back(0);
			if(t[i - 1] != '0') sec.push_back(1);
			if(t[i - 1] != '1') sec.push_back(0);
			for(int dt = -n; dt <= n; dt++) {
				for(const auto& el1 : fir) {
					for(const auto& el2 : sec) {
						int nxt = dt - el1 + el2;
						if(nxt < -n || nxt > n) continue;
						dp1[i][dt + n] = (dp1[i][dt + n] + dp1[i - 1][nxt + n]) % mod;
					}
				}
			}
		}
		for(int i = n - 1; i >= 0; i--) {
			vi fir;
			vi sec;
			if(s[i] != '0') fir.push_back(1);
			if(s[i] != '1') fir.push_back(0);
			if(t[i] != '0') sec.push_back(1);
			if(t[i] != '1') sec.push_back(0);
			for(int dt = -n; dt <= n; dt++) {
				for(const auto& el1 : fir) {
					for(const auto& el2 : sec) {
						int nxt = dt - el1 + el2;
						if(nxt < -n || nxt > n) continue;
						dp2[i][dt + n] = (dp2[i][dt + n] + dp2[i + 1][nxt + n]) % mod;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n - 1; i++) {
			for(int j = -n; j <= n; j++) {
				int here = dp1[i + 1][j + n];
				here = (ll)here * dp2[i + 1][-j + n] % mod;
				here = (ll)here * abs(j) % mod;
				ans = (ans + here) % mod;
			}
		}
		cout << ans << '\n';
	}
}