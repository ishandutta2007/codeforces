#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ld x, y, z;

	bool operator< (const pt& b) const {
		return tie(x, y, z) < tie(b.x, b.y, b.z);
	}
};

pt b[300005], z[300005];
mt19937 eng;

ld rld() {
	return uniform_real_distribution<ld>(-1, 1)(eng);
}

pt refl(pt a, pt b) {
	ld q = a.x*b.x + a.y*b.y + a.z*b.z;
	q *= 2;
	pt c = {b.x*q, b.y*q, b.z*q};
	return {a.x-c.x, a.y-c.y, a.z-c.z};
}

void rnd(ld& x) {
	x = round(x * 1e7);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<=300000; i++) {
		b[i] = {rld(), rld(), rld()};
		ld g = sqrt(b[i].x*b[i].x + b[i].y*b[i].y + b[i].z*b[i].z);
		b[i].x /= g;
		b[i].y /= g;
		b[i].z /= g;
	}
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		z[0] = b[0];
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			z[i+1] = refl(z[i], b[x]);
		}
		for (int i=0; i<=n; i++) {
			// cerr << z[i].x << ' ' << z[i].y << ' ' << z[i].z << '\n';
			rnd(z[i].x);
			rnd(z[i].y);
			rnd(z[i].z);
		}
		sort(z, z+n+1);
		ll sol = 0, str = 1;
		for (int i=1; i<=n; i++) {
			if (z[i-1] < z[i])
				str = 1;
			else
				str++;
			sol += str - 1;
		}
		cout << sol << '\n';
	}

}