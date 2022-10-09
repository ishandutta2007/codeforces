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

	pt operator- (const pt& b) const {
		return {x - b.x, y - b.y};
	}
};

struct seg {
	pt a, b;
};

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

set<pt> s;
seg a[1005];
int n;
ll sol;

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

bool inside(pt a, pt b, pt c) {
	return sp(a-b, b-c) >= 0 && det(a, b, c) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].a.x >> a[i].a.y >> a[i].b.x >> a[i].b.y;
		sol += gcd(abs(a[i].a.x - a[i].b.x), abs(a[i].a.y - a[i].b.y)) + 1;
	}

	cerr << "sol " << sol << '\n';

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			ll ax = a[i].a.x;
			ll ay = a[i].a.y;
			ll bx = a[i].b.x;
			ll by = a[i].b.y;
			ll cx = a[j].a.x;
			ll cy = a[j].a.y;
			ll dx = a[j].b.x;
			ll dy = a[j].b.y;

			ll det = (-(ay - by))*(-cx + dx) + (-ax + bx)*(cy - dy);
			if (det == 0)
				continue;

			ll px = -(((-((-ay)*bx + ax*by))*(-cx + dx) + (-ax + bx)*((-cy)*dx + cx*dy))/
      ((-(ay - by))*(-cx + dx) + (-ax + bx)*(cy - dy)));

			ll py = -((ay*bx*cy - ax*by*cy - ay*cy*dx + by*cy*dx - ay*bx*dy + ax*by*dy + 
     ay*cx*dy - by*cx*dy)/
      ((-ay)*cx + by*cx + ax*cy - bx*cy + ay*dx - by*dx - ax*dy + 
     bx*dy));

			if (abs(px) >= 1231231 || abs(py) >= 1231231)
				continue;

			pt p = {px, py};

			if (inside(a[i].a, p, a[i].b) && inside(a[j].a, p, a[j].b)) {
				s.insert(p);
			}
		}

		sol -= s.size();
		s.clear();
	}

	cout << sol << '\n';
}