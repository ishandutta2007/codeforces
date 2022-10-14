#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;//2*5*7*9 3*4*6*8
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<array<ll, 2>> pts;
array<ll, 2> ans;
bool can(ll r, ll recover = 0) {
	ll lx = 0;
	ll rx = (1ll<<60);
	ll ly = 0;
	ll ry = (1ll<<60);
	ll ls = -(1ll<<60);
	ll rs = (1ll<<60);
	for(auto [x, y] : pts) {
		rx = min(rx, x + r);
		lx = max(lx, x - r);
		ry = min(ry, y + r);
		ly = max(ly, y - r);
		rs = min(rs, x - y + r);
		ls = max(ls, x - y - r);
	}
	if(lx > rx || ly > ry || ls > rs) return false;
	if(rs < lx-ry || rx-ly < ls) return false;
	for(int y = ly; y <= ry; y++) {
		ll nls = ls + y, nrs = rs + y;
		ll t = max(nls, lx);
		t += t+y==0;
		if(t <= min(rx, nrs)) {
			if(recover) {
				cout << r << endl;
				cout << string(y, 'N') << string(t, 'B') << endl;
			}
			return true;
		}
	}
	return false;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int sb = 0, sn = 0;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int t = count(all(s), 'B');
		pts.push_back({t, s.size() - t});
	}
	ll ans = -1;
	for(ll x = 1ll<<30; x>>=1;)
		ans += x*!can(ans+x);
	can(ans+1, 1);
}