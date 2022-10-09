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
		while (b.size() >= 2 && det(b[b.size()-2], b[b.size()-1], p) <= 0)
			b.pop_back();
		b += p;
	}
	return b;
}

basic_string<pt> hull(basic_string<pt> a) {
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	auto p = hull_half(a);
	p.pop_back();
	reverse(a.begin(), a.end());
	auto q = hull_half(a);
	q.pop_back();
	return p + q;
}

const ll H = 100000;

basic_string<pt> find_pts(ll x, ll y, ll r) {
	basic_string<pt> z;
	if (x-r >= 0) {
		z += {x-r, y};
	} else {
		ll u = y-abs(x-r);
		ll v = y+abs(x-r);
		u = max(u, 0ll);
		v = min(v, H);
		z += pt{0, u};
		z += pt{0, v};
	}

	if (x+r <= H) {
		z += {x+r, y};
	} else {
		ll u = y-abs(x+r - H);
		ll v = y+abs(x+r - H);
		u = max(u, 0ll);
		v = min(v, H);
		z += pt{H, u};
		z += pt{H, v};
	}


	if (y-r >= 0) {
		z += {x, y-r};
	} else {
		ll u = x-abs(y-r);
		ll v = x+abs(y-r);
		u = max(u, 0ll);
		v = min(v, H);
		z += pt{u, 0};
		z += pt{v, 0};
	}

	if (y+r <= H) {
		z += {x, y+r};
	} else {
		ll u = x-abs(y+r - H);
		ll v = x+abs(y+r - H);
		u = max(u, 0ll);
		v = min(v, H);
		z += pt{u, H};
		z += pt{v, H};
	}

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	basic_string<pt> b;
	while (n--) {
		ll x, y, v;
		cin >> x >> y >> v;
		b += find_pts(x, y, v);
	}
	b = hull(b);
	b += b.substr(0, 2);

	// for (auto [x, y] : b)
	// 	cerr << x << ", " << y << '\n';

	ld sol = 0;
	basic_string<pt> zz;

	for (int i=0; i+2 < (int)b.size(); i++) {
		ld A = sqrt((ld)d2(b[i+0], b[i+1]));
		ld B = sqrt((ld)d2(b[i+1], b[i+2]));
		ld C = sqrt((ld)d2(b[i+2], b[i+0]));

		ld H = abs(det(b[i], b[i+1], b[i+2]));

		ld R = A*B*C / H;
		if (R > sol) {
			sol = R;
			zz = b.substr(i, 3);
		}
	}

	// cout << fixed << setprecision(20) << sol << '\n';
	for (int i=0; i<3; i++)
		cout << zz[i].x << ' ' << zz[i].y << '\n';
}