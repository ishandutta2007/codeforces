#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	bool operator< (const pt& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

basic_string<pt> halfhull(basic_string<pt> a) {
	basic_string<pt> s;
	for (pt u : a) {
		while (s.size() >= 2 && det(s[s.size()-2], s.back(), u) <= 0)
			s.pop_back();
		s += u;
	}
	return s;
}

ll area(pt a, pt b, pt c) {
	return abs(det(a, b, c));
}

basic_string<pt> hull(basic_string<pt> a) {
	sort(a.begin(), a.end());
	auto v = halfhull(a);
	v.pop_back();
	reverse(a.begin(), a.end());
	v += halfhull(a);
	v.pop_back();
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	ll s;
	cin >> n >> s;
	basic_string<pt> a;
	for (int i=0; i<n; i++) {
		pt b;
		cin >> b.x >> b.y;
		a += b;
	}

	int ii=-1, jj=-1, kk=-1;
	ll best = -1;

	a = hull(a);
	n = a.size();
	
	for (int i=0; i<n; i++) {
		int k;
		for (int j=(i+1)%n; j!=i; j=(j+1)%n) {
			if (j == (i+1)%n) {
				k = (j+1)%n;
			}

			while ((k+1)%n != i && area(a[i], a[j], a[(k+1)%n]) >
				area(a[i], a[j], a[k]))
			{
				k = (k+1)%n;
			}
			if (area(a[i], a[j], a[k]) > best) {
				best = area(a[i], a[j], a[k]);
				ii = i;
				jj = j;
				kk = k;
			}

			if (k == j)
				k = (k+1) % n;
		}
	}

	cout << a[ii].x + a[jj].x - a[kk].x << ' ' << a[ii].y + a[jj].y - a[kk].y << '\n';
	cout << a[jj].x + a[kk].x - a[ii].x << ' ' << a[jj].y + a[kk].y - a[ii].y << '\n';
	cout << a[kk].x + a[ii].x - a[jj].x << ' ' << a[kk].y + a[ii].y - a[jj].y << '\n';
}