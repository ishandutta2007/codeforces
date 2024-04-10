#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll blacks(ll x, ll y) {
	return x*y / 2;
}

ll blacks(ll x1, ll y1, ll x2, ll y2) {
	x1--;
	y1--;
	return blacks(x2, y2) + blacks(x1, y1)
		- blacks(x1, y2) - blacks(x2, y1);
}

ll whites(ll x1, ll y1, ll x2, ll y2) {
	return (x2-x1+1)*(y2-y1+1) - blacks(x1, y1, x2, y2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> m >> n;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

		ll x5 = max(x1, x3);
		ll x6 = min(x2, x4);
		ll y5 = max(y1, y3);
		ll y6 = min(y2, y4);

		if (x5 > x6 || y5 > y6) {
			// nula povrsina
			x6 = x5-1;
			y6 = y5-1;
		}

		ll tabla_blacks = blacks(n, m);
		// koliko je bilo crnih polja u A\B
		tabla_blacks -= blacks(x1, y1, x2, y2) - blacks(x5, y5, x6, y6);

		// koliko je bilo belih polja u B
		tabla_blacks += whites(x3, y3, x4, y4);

		cout << n*m - tabla_blacks << ' ' << tabla_blacks << '\n';
	}
}