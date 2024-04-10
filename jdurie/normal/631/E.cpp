//Convex Hull Trick
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define A(x) (x).begin(), (x).end()
#define N 200010
#define INF 1000000000000000000ll

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
	hull.push_back({-INF, m, b});
}

ll query(ll x) {
	seg s = *--upper_bound(A(hull), (seg){(ld)x, INF, INF}, [](const seg s1, const seg s2) { return s1.x < s2.x; });
	return s.b + s.m * x;
}

ll n, a[N], ssum[N];

void fillssum() {
	ssum[n] = 0;
	FD(i, n - 1, -1) ssum[i] = a[i] + ssum[i + 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	F(i, 0, n) cin >> a[i];
	ll baseans = 0;
	F(i, 0, n) baseans += (i + 1) * a[i];
	fillssum();
	ll ans = 0;
	F(i, 0, n) {
		if(i) ans = max(ans, -ssum[i] - i * a[i] + query(a[i]));
		insert(i, ssum[i]);
	}
	hull.clear();
	reverse(a, a + n);
	fillssum();
	F(i, 0, n) {
		if(i) ans = max(ans, ssum[i] + i * a[i] + query(-a[i]));
		insert(i, -ssum[i]);
	}
	cout << ans + baseans << '\n';
}