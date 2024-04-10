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
	bool operator== (const pt& o) const {
		return x == o.x && y == o.y;
	}
};

pt a[2005];
int n;
basic_string<pt> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		ll x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if (i != j)
				b += {a[i].x - a[j].x, a[i].y - a[j].y};
		}

	sort(b.begin(), b.end());
	ll streak = 0, sol = 0;
	pt last = {-12312312312312123ll, 0};
	for (pt u : b) {
		if (u == last)
			streak++;
		else {
			last = u;
			streak = 1;
		}
		sol += streak - 1;
	}

	// unutrasnje?
	cerr << sol << '\n';
	cout << sol / 4 << '\n';
}