#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll qcnt = 0, p = 2349, LOCAL = 0;
ll query(ll l, ll r) {
	qcnt++;
	if(LOCAL) {
		return l <= p && r >= p;
	}
	cout << l << " " << r << endl;
	string s;cin >> s;
	return s == "Yes";
}
void solve() {
	ll n, k;
	if(LOCAL) n = 1e18, k = 10;
	else cin >> n >> k;
	ll l = 1, r = n;
	while(qcnt < 4500) {
		while(r-l+1 > 44) {
			ll mid = (l+r)/2;
			if(query(l, mid)) l = max(1ll, l-k), r = min(n, mid+k);
			else l = max(1ll, mid-k), r = min(n, r+k);
		}
		ll p = l + (rng()%(r-l+1));
		if(query(p, p)) return;
		l = max(1ll, l-k);
		r = min(n, r+k);
	}
	while(true);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	cerr << qcnt << endl;
}