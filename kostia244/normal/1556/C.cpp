// Problem: C. Compressed Bracket Sequence
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	ll ans = 0;
	for(int l = 0; l < n; l+=2) {
		ll bal = 0, mn = 1ll<<30;
		for(int r = l; r < n; r++) {
			if(r&1) {//bal-mn
				ll u = max(1ll, bal-mn);
				ll v = min(bal, a[r]);
				// cout << l << " " << r << " " << u << " " << v << endl;
				ans += max(0ll, v-u+1);
				// cout << l << " " << r << " " << ans << endl;
			}
			if(r&1) bal -= a[r];
			else bal += a[r];
			mn = min(mn, bal);
			if(bal < 0) break;
		}
	}
	cout << ans << '\n';
}