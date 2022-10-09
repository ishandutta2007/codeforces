#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ld e, p;
	int x, y, t;
	bool operator< (const pt& b) const {
		return t < b.t;
	}
} a[1005];
int n;

ll kv(ll x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;

	sort(a, a+n);

	ld sol = 0;

	for (int i=0; i<n; i++) {
		a[i].e = a[i].p;
		for (int j=0; j<i; j++) {
			if (kv(a[i].x - a[j].x) + kv(a[i].y - a[j].y) <= kv(a[i].t - a[j].t)) {
				a[i].e = max(a[i].e, a[j].e + a[i].p);
			}
		}
		sol = max(sol, a[i].e);
	}

	cout << setprecision(20) << fixed << sol << '\n';
}