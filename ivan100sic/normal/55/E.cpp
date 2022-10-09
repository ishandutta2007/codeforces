#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	pt operator- (pt b) const {
		return {x-b.x, y-b.y};
	}
	bool operator== (pt b) const {
		return x == b.x && y == b.y;
	}
	bool operator< (pt b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

ll sq(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

bool kolin(pt a, pt b, pt c) {
	if (det(a, b, c) != 0)
		return false;
	return b == a || b == c || sp(a-b, b-c) > 0;
}

ll sgn(ll x) {
	if (x < 0) return -1;
	else if (x == 0) return 0;
	else return 1;
}

bool sek(pt a, pt b, pt c, pt d) {
	return
		sgn(det(a, b, c)) * sgn(det(a, b, d)) == -1
	 && sgn(det(c, d, a)) * sgn(det(c, d, b)) == -1;
}

bool pip(pt b, pt* a, int n) {
	ld w = 0;
	for (int i=0; i<n; i++) {
		int j = (i+1) % n;

		ld arg = sp(b - a[i], b - a[j]);
		arg /= sqrt(d2(b, a[i]));
		arg /= sqrt(d2(b, a[j]));
		arg = max(arg, (ld)-1);
		arg = min(arg, (ld)1);

		if (det(b, a[i], a[j]) < 0)
			w += acos(arg);
		else
			w -= acos(arg);
	}

	return abs(w) > 1.5;
}

ll area(pt* a, int n) {
	ll s = 0;
	for (int i=1; i<n-1; i++)
		s += det(a[0], a[i], a[i+1]);
	return s;
}

basic_string<pt> hull_half(basic_string<pt> a) {
	basic_string<pt> b;
	for (pt p : a) {
		while (b.size() >= 2 && det(b[b.size()-2], b[b.size()-1], p) < 0)
			b.pop_back();
		b += p;
	}
	return b;
}

basic_string<pt> hull(basic_string<pt> a) {
	sort(a.begin(), a.end());
	auto p = hull_half(a);
	p.pop_back();
	reverse(a.begin(), a.end());
	auto q = hull_half(a);
	q.pop_back();
	return p + q;
}


int n;
pt a[100005], b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;

	int t;
	cin >> t;
	while (t--) {
		cin >> b.x >> b.y;
		int j = 1;

		bool ok = 1;
		for (int i=0; i<n; i++)
			if (det(a[i], a[(i+1)%n], b) > 0)
				ok = 0;
		if (!ok) {
			cout << "0\n";
			continue;
		}

		ll glavno = 0, sporedno = 0;
		for (int i=0; i<n; i++) {
			while ((j+1) % n != i && det(a[i], b, a[(j+1) % n]) > 0)
				j = (j+1) % n;

			// cerr << "ij " << i << ' ' << j << '\n';
			ll k = j-i < 0 ? j-i+n : j-i;
			ll l = n - 1 - k;
			glavno += k * l;
			sporedno += k*(k-1) / 2 + l*(l-1) / 2;

			if (j == (i+1) % n)
				j = (j+1) % n;
		}

		// cerr << glavno << '\n';
		// cerr << sporedno << '\n';
		cout << (glavno-sporedno/2) / 3 << '\n';
	}
}