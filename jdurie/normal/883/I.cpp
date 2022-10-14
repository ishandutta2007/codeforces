#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;
#define N 300010

ll n, k, a[N];

bool works(ll m) {
	ll p = 0;
	set<ll> ok = {-1};
	F(i, 0, n) {
		while(p < i && a[i] - a[p] > m) p++;
		if(*ok.rbegin() >= p - 1 && *ok.lower_bound(p - 1) <= i - k) ok.insert(i);
	}
	return ok.count(n - 1);
}

ll bSearch(ll l, ll r) {
	if(l == r) return l;
	ll m = (l + r) / 2;
	return works(m) ? bSearch(l, m) : bSearch(m + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	F(i, 0, n) cin >> a[i];
	sort(a, a + n);
	cout << bSearch(0, 1000000000) << '\n';
}