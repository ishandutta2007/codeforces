#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e5 + 10, mlg = 17, mod = 1e9 + 7;
ll tree[2 * maxn], n;
vi a;
void modify(int i, ll v) {
	for (i += n, tree[i] = max(tree[i], v); i >>= 1;)
		tree[i] = max(tree[i<<1], tree[i<<1|1]);
}
ll get(int r) {
	ll ans = 0;
	int l = n;
	for(r+=n+1; l<r;r>>=1, l>>=1) {
		if(r&1) ans = max(ans, tree[--r]);
		if(l&1) ans = max(ans, tree[l++]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vi _b;
	for (ll x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		ll t = x * x * y;
		a.pb(t);
		_b.pb(t);
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	ll ans = 0;
	for (auto t : _b) {
		int p = lower_bound(all(a), t)-a.begin();
		ll r = get(p-1) + t;
		modify(p, r);
		ans = max(ans, r);
	}
	cout << fixed << setprecision(15) << (ld)ans*acos(-1);
	return 0;
}