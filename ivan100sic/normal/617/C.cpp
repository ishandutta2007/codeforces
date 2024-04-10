#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll xa, ya, xb, yb;
ll da[2005], db[2005];
ll x[2005], y[2005];
int qq[2005];

bool cmp(int i, int j) {
	return da[i] < da[j];
}

ll naj(int l, int r) {
	ll z = 0;
	for (int i=l; i<r; i++) {
		z = max(z, db[qq[i]]);
	}
	return z;
}

ll kv(ll x) {
	return x*x;
}

ll dist(ll p, ll q, ll r, ll s) {
	return kv(p-r) + kv(q-s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> xa >> ya >> xb >> yb;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		da[i] = dist(xa, ya, x[i], y[i]);
		db[i] = dist(xb, yb, x[i], y[i]);
		qq[i] = i;
	}

	sort(qq, qq+n, cmp);

	ll sol = naj(0, n);

	for (int i=0; i<n; i++) {
		sol = min(sol, da[qq[i]] + naj(i+1, n));
	}

	cout << sol << '\n';
}