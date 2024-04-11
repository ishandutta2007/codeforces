#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct fenwick {
	vi t;
	int n;
	void init(int _n) {
		t.resize((n=_n)+1);
	}
	void add(int x, int v) {
		while(x <= n) {
			t[x] += v;
			x += x&-x;
		}
	}
	ll get(int x) {
		ll r = 0;
		while(x) {
			r += t[x];
			x -= x&-x;
		}
		return r;
	}
	ll get(ll l, ll r) {
		if(l>r) return 0;
		return get(r) - get(l-1);
	}
};
int n, m;
vi a, p, b, v;
void read() {
	cin >> n;
	a.resize(n);
	p.resize(n);
	for(auto &i : a) cin >> i;
	for(auto &i : p) cin >> i;
	cin >> m;
	b.resize(m);
	for(auto &i : b) cin >> i;
}
void compress() {
	v = a;
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	v.pb(1ll<<60);
	for(auto &i : a) i = upper_bound(all(v), i) - v.begin();
	for(auto &i : b) {
		if(!binary_search(all(v), i)){cout << "NO\n", exit(0);}
		i = upper_bound(all(v), i) - v.begin();
	}
}
fenwick pref, suf;
ll ans = 1ll<<60, negsum = 0;
ll dp[1<<19];
int nxt(int a) {
	return upper_bound(all(v), v[b[a]])-v.begin();
}
void solve() {
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	pref.init(v.size());
	suf.init(v.size());
	for(int i = 0; i < n; i++) suf.add(a[i], max(0ll, p[i]));
	int u = nxt(b.size()-1);
	for(int i = 0; i < n; i++) {
		negsum += min(0ll, p[i]);
		pref.add(a[i], max(0ll, p[i]));
		suf.add(a[i], -max(0ll, p[i]));
		if(!binary_search(all(b), a[i])) continue;
		int x = upper_bound(all(b), a[i])-b.begin();
		if(dp[x-1]>=(1ll<<60)) continue;
		ll cur = dp[x-1];
		if(p[i] < 0) cur -= p[i];
		if(x == 1)
		cur += pref.get(1, v.size())-max(0ll, p[i]);
		else
		cur += pref.get(nxt(x-2), v.size())-max(0ll, p[i]);
		if(x!=m) {
			dp[x] = min(dp[x], cur - pref.get(nxt(x-1), v.size()));
		} else {
			ans = min(ans, cur + suf.get(u, v.size()));
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	compress();
	solve();
	if(ans == 1ll<<60) cout << "NO", exit(0);
	cout << "YES\n";
	cout << ans +negsum;
	return 0;
}