//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxk = 52;
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

struct Line {
	mutable ld k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ld inf = 1/.0;
	ld div(ld a, ld b) { // floored division
		return a / b; }// - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ld k, ld m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ld get(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll n, k, a[maxn], ps[maxn];
ld dp[2][maxn];
ld sp[maxn], d[maxn];
LineContainer s;

int main(){
    fast_io;
	cout << setprecision(10) << fixed;

	cin >> n >> k;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
		sp[i] = sp[i - 1] + 1.0 / a[i];
		d[i] = d[i - 1] + 1.0 * ps[i] / a[i];
		dp[1][i] = d[i];
	}
	for(ll i = 2; i <= k; i++){
		for(ll j = i; j <= n; j++){
			s.add(ps[j - 1], -dp[i - 1 & 1][j - 1] + d[j - 1] - ps[j - 1] * sp[j - 1]);
			dp[i & 1][j] = d[j] - s.get(sp[j]);
		}
	}
	cout << dp[k & 1][n];

    return 0;
}