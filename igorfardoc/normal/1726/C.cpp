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
const int maxn = 100000;
int p[2 * maxn + 1];

int get_par(int a) {
	if(p[a] == a) return a;
	int par = get_par(p[a]);
	p[a] = par;
	return par;
}

void join(int a, int b) {
	//cout << a << ' ' << b << endl;
	a = get_par(a);
	b = get_par(b);
	if(a == b) return;
	p[a] = b;
}



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
		string s;
		cin >> s;
		for(int i = 0; i <= 2 * n; i++) {
			p[i] = i;
		}
		map<int, int> d;
		d[0] = 2 * n;
		int now = 0;
		vi dp(2 * n + 1);
		dp[2 * n] = 2 * n;
		for(int i = 2 * n - 1; i >= 0; i--) {
			if(s[i] == ')') {
				--now;
			} else {
				++now;
				int ps = d[now];
				dp[i] = ps - 1;
				if(ps == 2 * n || s[ps] == '(') join(i, dp[ps]);
				join(i, ps - 1);
			}
			d[now] = i;
		}
		set<int> all;
		for(int i = 0; i <= 2 * n; i++) {
			all.insert(get_par(i));
		}
		cout << all.size() << '\n';
	}

}