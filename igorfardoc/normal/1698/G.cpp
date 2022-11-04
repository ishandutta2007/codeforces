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
string s;
int len;
__int128 md;

__int128 mul(__int128 i, __int128 j) {
	__int128 res = 0;
	for(int k = 0; k < 40; k++) {
		if((j >> k) & 1) {
			res = res ^ (i << k);
		}
	}
	for(int k = 80; k >= len - 1; k--) {
		if((res >> k) & 1) {
			res = res ^ (md << (k - len + 1));
		}
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
	cin >> s;
	int am = 0;
	while(am < s.size() && s[am] == '0') {
		++am;
	}
	if(am == s.size()) {
		cout << -1;
		return 0;
	}
	int r = s.size() - 1;
	while(s[r] == '0') {
		--r;
	}
	len = r - am + 1;
	if(len == 1) {
		cout << am + 1 << ' ' << am + 2;
		return 0;
	}
	md = 0;
	for(int i = 0; i < len; i++) {
		if(s[i + am] == '1') {
			md = md | (1ll << i);
		}
	}
	unordered_map<ll, int> d;
	d[1] = 0;
	ll now = 1;
	for(int i = 1; i < (1 << 18); i++) {
		now = mul(now, 2);
		d[now] = i;
	}
	now = mul(now, 2);
	ll curr = now;
	ll ps = 1 << 18;
	while(true) {
		if(d.find(curr) != d.end()) {
			cout << am + 1 << ' ' << am + 1 + ps - d[curr];
			break;
		}
		ps += 1 << 18;
		curr = mul(curr, now);
	}

}