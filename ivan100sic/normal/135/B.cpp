#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	int id;

	bool operator< (const pt& o) const {
		return id < o.id;
	}

	pt operator- (const pt& o) const {
		return {x-o.x, y-o.y};
	}
};

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

bool orto(pt a, pt b, pt c) {
	return sp(b-a, b-c) == 0;
}

ll sq(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

bool pravougaonik(pt a, pt b, pt c, pt d) {
	return orto(a, b, c) && orto(b, c, d) && orto(c, d, a) && orto(d, a, b);
}

bool kvadrat(pt a, pt b, pt c, pt d) {
	return pravougaonik(a, b, c, d) && d2(a, b) == d2(b, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pt a[8];
	for (int i=0; i<8; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i+1;
	}

	for (int i=0; i<40320; i++) {
		if (kvadrat(a[0], a[1], a[2], a[3]) &&
			pravougaonik(a[4], a[5], a[6], a[7]))
		{
			cout << "YES\n";
			for (int i=0; i<4; i++)
				cout << a[i].id << ' ';
			cout << '\n';
			for (int i=4; i<8; i++)
				cout << a[i].id << ' ';
			cout << '\n';
			return 0;
		}

		next_permutation(a, a+8);
	}

	cout << "NO\n";
}