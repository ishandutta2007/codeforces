#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
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
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int main() {
    int n; cin >> n;
    LineContainer lc,lc2;
    vi a(n); for(auto& i : a) cin >> i;
    vector<ll> pref(n+1);
    for(int i=1;i<=n;++i) pref[i]=pref[i-1]+a[i-1];
    ll ans=-1e18,total=0;
    for(int i=0;i<n;++i) total+=ll(i+1)*a[i];
    for(int i=0;i<n;++i) {
        lc2.add(i,-pref[i]);
        ans = max(ans, total+lc2.query(a[i])+pref[i]-ll(i)*a[i]);
    }
    for(int i=n-1;i>=0;--i) {
        lc.add(i,-pref[i+1]);
        ans = max(ans, total+lc.query(a[i])+pref[i+1]-ll(i)*a[i]);
    }
    

    for(int i=0;i<n;++i) {
       
    }
    cout << ans << '\n';
}