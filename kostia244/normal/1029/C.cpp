#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int maxn = 1e6 + 3;
#define left bsalkfjdasld
void solve() {
	int n;
	vector<pi> seg;
	multiset<int> o, c;
	cin >> n;
	for(int l, r, i = 0; i < n; i++) {
		cin >> l >> r;
		o.insert(l);
		c.insert(r);
		seg.pb({l, r});
	}
	int ans = 0;
	for(auto i : seg) {
		o.erase(o.find(i.first));
		c.erase(c.find(i.second));
		ans = max(ans, *c.begin() - *o.rbegin());
		o.insert(i.first);
		c.insert(i.second);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while(t--) solve();
}