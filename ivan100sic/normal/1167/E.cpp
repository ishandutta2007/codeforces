#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x;
int a[1000005];
int najgora[1000005];

/*
	neka je x,y fiksna inverzija (x > y)
	neka je l fiksno. sta treba da vazi za r tako
	da ova inverzija bude neutralizovana?

	treba da vazi l <= x <= r || l <= y <= r
	odnosno posto je y < x imamo l <= y implicira l <= x
	slicno imamo da r >= x implicira r >= y
	pa imamo laksi uslov:

	(l <= x && x <= r) || (l <= y && y <= r)

	eq

	(l <= x || l <= y) && (x <= r || y <= r) && (l <= x || y <= r)
		&& (l <= y || x <= r)

	eq

	l <= x && y <= r && (l <= x || y <= r) && (l <= y || x <= r)

	eq

	l <= x && y <= r && (l <= y || x <= r)

	za fiksno l, nas ne plase inverzije gde je y >= l
	ali one kod kojih je y < l, kod njih mora da vazi x <= r
	odnosno, r >= max(x | (x,y) je inverzija, y < l)
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	// nadjimo najmanju inverzju
	int mx = 0, limx = x, limy = 1;
	set<int> b;
	for (int i=1; i<=n; i++) {
		if (a[i] < mx) {
			najgora[a[i]] = mx;
		} else {
			mx = a[i];
		}

		auto it = b.upper_bound(a[i]);
		if (it != b.end()) {
			limx = min(limx, *it);
			limy = max(limy, a[i]);
		}

		b.insert(a[i]);
	}
	
	for (int i=1; i<=x; i++)
		najgora[i] = max(najgora[i], najgora[i-1]);

	// l ne sme da bude vece od ovoga
	ll sol = 0;
	for (int l=1; l<=limx; l++) {
		int r = max(l, najgora[l-1]);
		// cerr << l << ' ' << r << '\n';
		r = max(r, limy);
		sol += x-r+1;
	}
	cout << sol << '\n';
}