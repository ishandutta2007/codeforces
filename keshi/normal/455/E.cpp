//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)


struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct cht : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll get(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll n, m, a[maxn], ps[maxn];
cht seg[maxn << 2];

void bld(ll id, ll s, ll e){
	for(ll i = s; i < e; i++){
		seg[id].add(-a[i], ps[i] - i * a[i]);
	}
	if(e - s == 1) return;
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	return;
}
ll get(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return -inf;
	if(l <= s && e <= r) return seg[id].get(x);
	ll mid = (s + e) >> 1;
	return max(get(lc, s, mid, l, r, x), get(rc, mid, e, l, r, x));
}

int main(){
    fast_io;

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0) ps[i] = a[i];
		else ps[i] = ps[i - 1] + a[i];
	}
	bld(1, 0, n);
	cin >> m;
	for(ll i = 0; i < m; i++){
		ll x, y;
		cin >> x >> y;
		cout << ps[y - 1] - get(1, 0, n, y - x, y, x - y + 1) << "\n";
	}

    return 0;
}