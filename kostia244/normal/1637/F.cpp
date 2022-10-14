// Problem: F. 
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
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
struct node {
	multiset<ll> ch;
	ll val, cs;
	array<ll, 2> ans;
	node(ll h = 0) : val(h), cs(0), ans{val, val} {
	}
	void upd_child(node &c, int add) {
		if(add) {
			cs += c.ans[0];
			ch.insert(c.ans[1]);
		} else {
			cs -= c.ans[0];
			ch.erase(ch.find(c.ans[1]));
		}
		recalc();
	}
	ll get_max() {
		return ch.empty() ? 0 : *ch.rbegin();
	}
	void recalc(int dbg = 0) {
		ans[0] = cs + max(0ll, val-get_max());
		ans[1] = max(val, get_max());
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	vector<int> h(n);
	for(auto &i : h) cin >> i;
	vector<vector<int>> g(n);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[--f].push_back(--t);
		g[t].push_back(f);
	}
	vector<node> dp(n);
	auto init = [&](auto self, int v) -> void {
		dp[v] = node(h[v]);
		for(auto i : g[v]) {
			g[i].erase(find(all(g[i]), v));
			self(self, i);
			dp[v].upd_child(dp[i], 1);
		}
	};
	ll ans = 1ll<<60;
	auto solve = [&](auto self, int v, node &pdp) -> void {
		if(v) dp[v].upd_child(pdp,1);//, cout << "Ad " << pdp.ans[0] << endl;
		ans = min(ans, dp[v].ans[0]);
		for(int i : g[v]) {
			dp[v].upd_child(dp[i], 0);
			self(self, i, dp[v]);
			dp[v].upd_child(dp[i], 1);
		}
		if(v) dp[v].upd_child(pdp, 0);
	};
	node trash(0);
	init(init, 0);
	solve(solve, 0, trash);
	cout << ans+*max_element(all(h)) << '\n';
}