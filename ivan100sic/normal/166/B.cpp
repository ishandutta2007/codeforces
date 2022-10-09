#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	bool operator< (const pt& o) const {
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y
		- a.y*b.x - b.y*c.x - c.y*a.x;
}

int n;
pt a[100005];

bool pip(pt b) {
	// binarno nadji b
	if (b.x <= a[0].x)
		return false;

	if (det(a[0], a[1], b) >= 0)
		return false;

	if (det(a[0], a[n-1], b) <= 0)
		return false;

	int l = 1, r = n-1, o = -1;

	// nalazim upper bound

	while (l <= r) {
		int m = (l+r) >> 1;
		if (det(a[0], a[m], b) > 0) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	if (o == -1 || o == 1)
		return false;

	return det(a[o-1], a[o], b) < 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;

	rotate(a, min_element(a, a+n), a+n);

	int m;
	cin >> m;
	int ok = 1;
	while (m--) {
		pt b;
		cin >> b.x >> b.y;
		if (!pip(b))
			ok = 0;
	}
	cout << (ok ? "YES\n" : "NO\n");
}