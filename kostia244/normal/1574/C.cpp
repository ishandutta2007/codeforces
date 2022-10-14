// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/C
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	ll s = 0;
	vector<ll> a(n);
	for(auto &i : a) cin >> i, s += i;
	sort(all(a));
	ll q, x, y;
	cin>>q;
	while(q--) {
		cin >> x >> y;
		auto it = lower_bound(all(a), x);
		ll ans = 1ll<<60;
		if(it != a.end()) {
			ans = min(ans, max(y-(s-*it), 0ll));
		}
		if(it != a.begin()) {
			it--;
			ans = min(ans, x - *it + max(y-(s-*it), 0ll));
		}
		cout << ans << '\n';
	}
}