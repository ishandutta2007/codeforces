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
#define A(x) (x).begin(), (x).end()
#define N 100010
#define INF 1000000000000000000ll

struct seg { ld x; ll m, b; };

vector<seg> hull;

void insert(ll m, ll b) { //lines inserted in inc. slope order for maxhull, desc. for minhull
	while(hull.size()) {
		seg s = hull.back();
		if(s.b + s.m * s.x >= b + m * s.x) hull.pop_back(); //>= for minhull
		else break;
	}
	if(hull.empty()) { hull.push_back({-INF, m, b}); return; }
	seg s = hull.back();
	if(s.m - m) hull.push_back({(b - s.b) / (ld)(s.m - m), m, b});
}

ll query(ll x) {
	seg s = *--upper_bound(A(hull), (seg){(ld)x, INF, INF}, [](const seg s1, const seg s2) { return s1.x < s2.x; });
	return s.b + s.m * x;
}

 
ll a[N], b[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	G(n)
	F(i, 0, n) cin >> a[i];
	F(i, 0, n) cin >> b[i];
	insert(b[0], 0);
	F(i, 1, n - 1) insert(b[i], query(a[i]));
	cout << query(a[n - 1]) << '\n';
}