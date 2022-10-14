#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define A(x) (x).begin(), (x).end()
#define N 1000010

struct seg { ld x; ll m, b; };

vector<seg> hull;

void insert(ll m, ll b) { //lines inserted in inc. slope order for maxhull, desc. for minhull
	while(hull.size()) {
		seg s = hull.back();
		if(s.b + s.m * s.x > b + m * s.x) { //< for minhull
			if(s.m - m) hull.push_back({(b - s.b) / (ld)(s.m - m), m, b});
			return;
		}
		hull.pop_back();
	}
	hull = {{LLONG_MIN, m, b}};
}

ll query(ll x) {
	seg s = *--upper_bound(A(hull), x, [](const ll a, const seg b) { return a < b.x; });
	return s.b + s.m * x;
}

#define K first
#define V second

pair<pl, ll> v[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	G(n)
	F(i, 0, n) cin >> v[i].K.K >> v[i].K.V >> v[i].V;
	sort(v, v + n);
	ll ans = 0;
	insert(0, 0);
	F(i, 0, n) {
		ll ai = v[i].K.K * v[i].K.V - v[i].V + query(-v[i].K.V);
		ans = max(ans, ai);
		insert(v[i].K.K, ai);
	}
	cout << ans << '\n';
}