#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, x, y, uw;
vector<int> a, b;
ll L(vector<int> &A, int x) {
	auto it = upper_bound(all(A), x);
	if(it == A.begin()) return -(1<<30);
	--it;
	return *it;
}
ll R(vector<int> &A, int x) {
	auto it = upper_bound(all(A), x);
	if(it == A.end()) return (1<<30);
	return *it;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> x >> y >> uw;
	a.resize(x);
	b.resize(y);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	sort(all(a));
	sort(all(b));
	int q; cin >> q;
	for(int x, y, u, v, i = 0; i < q; i++) {
		cin >> y >> x >> v >> u;
		if(x > u) swap(x, u), swap(y, v);
		ll ans = 1ll<<60, clev = 1ll<<30, cls = 1ll<<30;
		if(lower_bound(all(a), x) != upper_bound(all(a), u)) cls = 0;
		if(lower_bound(all(b), x) != upper_bound(all(b), u)) clev = 0;
		cls = min(cls, 2*(x-L(a, x)));
		cls = min(cls, 2*(R(a, u)-u));
		clev = min(clev, 2*(x-L(b, x)));
		clev = min(clev, 2*(R(b, u)-u));
		if(y == v) cls = clev = 0;
		ll dx = abs(x-u), dy = abs(y-v);
		//cout << dx << " " << dy << " " << cls << " " << clev << '\n';
		cout << min(clev + dx + (dy+uw-1)/uw, cls + dx + dy) << '\n';
	}
}