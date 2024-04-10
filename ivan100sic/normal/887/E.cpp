#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define bcmp opkgerk

typedef complex<ld> cd;
int n;
cd a[100005], b, c, bcmp, bcdir;
ld r[100005];

cd pt(ld x) {
	return bcmp + bcdir*x;
}

ld det(cd a, cd b, cd c) {
	return (conj(b-a)*(c-b)).imag();
}

ld seek_touch(cd a, ld d) {
	bool flip = det(a, b, c) > 0;
	ld l = -1e12, r = 1e12;
	int steps = 90;
	while (steps--) {
		ld m = (l+r) / 2;
		cd z = pt(m);
		((abs(z-b) + d > abs(z-a)) ^ flip ? l : r) = m;
	}
	return l;
}

ld seek_contain(cd a, ld d) {
	bool flip = det(a, b, c) > 0;
	ld l = -1e12, r = 1e12;
	int steps = 90;
	while (steps--) {
		ld m = (l+r) / 2;
		cd z = pt(m);
		((abs(z-b) > d + abs(z-a)) ^ flip ? l : r) = m;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	{
		int p, q, r, s;
		cin >> p >> q >> r >> s;
		b = cd(p, q);
		c = cd(r, s);
		bcmp = (b+c)/cd(2, 0);
		bcdir = (c-b) * cd(0, 1);
	}

	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[i] = cd(x, y);
		r[i] = z;
	}

	map<ld, int> mp;
	for (int i=0; i<n; i++) {
		ld u = seek_touch(a[i], r[i]);
		ld v = seek_contain(a[i], r[i]);
		if (u > v)
			swap(u, v);
		mp[u]++;
		mp[v]--;
	}
	mp[0];

	int z = 0;
	ld d = 1e50;
	for (auto [p, v] : mp) {
		if (z == 0)
			d = min(d, abs(p));
		z += v;
		if (z == 0)
			d = min(d, abs(p));
	}

	cout << setprecision(20) << fixed << abs(pt(d)-b) << '\n';
}