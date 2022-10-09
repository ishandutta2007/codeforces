#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], z[100005];

ll sq(ll x) {
	return x*x;
}

ll dist(int i, int j) {
	return sq(z[i]-z[j]) + sq(i-j);
}

bool cmp(int i, int j) {
	return z[i] < z[j];
}

ll solve(int l, int r) {
	if (l == r)
		return 8e18;
	if (l+1 == r)
		return dist(l, r);
	int m = (l+r) >> 1;
	ll w = min(solve(l, m), solve(m+1, r));
	basic_string<int> zid;
	for (int i=l; i<=r; i++)
		if (sq(i-m) <= w)
			zid += i;
	sort(zid.begin(), zid.end(), cmp);
	for (int i=0; i<(int)zid.size(); i++) {
		for (int j=i+1; j<min(i+8, (int)zid.size()); j++) {
			w = min(w, dist(zid[i], zid[j]));
		}
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}

	cout << solve(1, n) << '\n';
}