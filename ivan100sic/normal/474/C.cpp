#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
};

ll sq(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return sq(a.x - b.x) + sq(a.y - b.y);
}

bool kvadrat(vector<pt> a) {
	basic_string<ll> d;
	for (int i=0; i<4; i++)
		for (int j=i+1; j<4; j++)
			d += d2(a[i], a[j]);
	sort(d.begin(), d.end());
	return d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3]
		&&  d[3]*2 == d[4] && d[4] == d[5];
}

pt rot90(pt a, pt b) {
	a.x -= b.x;
	a.y -= b.y;

	ll t = a.x;
	a.x = -a.y;
	a.y = t;

	a.x += b.x;
	a.y += b.y;

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		vector<pt> p(4), q(4);
		for (int i=0; i<4; i++) {
			cin >> p[i].x >> p[i].y >> q[i].x >> q[i].y;
		}

		int best = 123123123;

		for (int i0=0; i0<4; i0++)
		for (int i1=0; i1<4; i1++)
		for (int i2=0; i2<4; i2++)
		for (int i3=0; i3<4; i3++)
		{
			vector<pt> r = p;
			for (int i=0; i<i0; i++) r[0] = rot90(r[0], q[0]);
			for (int i=0; i<i1; i++) r[1] = rot90(r[1], q[1]);
			for (int i=0; i<i2; i++) r[2] = rot90(r[2], q[2]);
			for (int i=0; i<i3; i++) r[3] = rot90(r[3], q[3]);

			int movs = i0 + i1 + i2 + i3;

			if (kvadrat(r))
				best = min(best, movs);
		}

		if (best == 123123123)
			best = -1;

		cout << best << '\n';
	}
}