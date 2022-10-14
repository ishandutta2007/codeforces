// Problem: B. Almost Sorted
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const ll inf = 1ll<<60;
ll p2(ll x) {
	if(x >= 60) return inf;
	return 1ll<<x;
}
ll A(ll n, ll f) {
	if(n == f) return 1;
	ll left = n-f;
	return p2(left-1);
}
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n, k;
		cin >> n >> k;k--;
		if(k >= p2(n-1)) {
			cout << "-1\n";
			return;
		}
		vector<int> res;
		ordered_set use;
		for(int i = 1; i <= n; i++) use.insert(i);
		int id = 1;
		for(;n; n--) {
			while(k >= A(n, id))
				k -= A(n, id++);
			res.push_back(id);
			id = max(1, id-1);
		}
		for(auto &i : res) {
			int x = *use.find_by_order(i-1);
			use.erase(x);
			i = x;
		}
		for(auto i : res) cout << i << " "; cout << '\n';
	});
}