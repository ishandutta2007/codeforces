#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct bowl {
	ld h, b, r;
	ld sharpness() {
		return h / (r-b);
	}
};

// (u)nder (o)ver
ld collide(bowl u, bowl o) {
	ld z = 0;
	// o sedi na u
	if (o.b >= u.r)
		return u.h;

	// sad znamo da je o.b < u.r

	// ova odozgo je vise casasta, njeno dno zapinje
	if (o.sharpness() >= u.sharpness() && o.b >= u.b) {
		ld t = (o.b-u.b) * u.sharpness();
		z = max(z, min(t, u.h));
	}
	// ova odozgo je manje casasta, lezi na vrhu druge
	if (o.sharpness() <= u.sharpness()) {
		ld t;
		if (o.r < u.r) {
			// ruzan slucaj
			t = u.h - (u.r-o.r) * u.sharpness() - o.h;
		} else {
			// normalan slucaj
			t = u.h - (u.r-o.b) * o.sharpness();
		}

		z = max(z, min(t, u.h));
	}
	return z;
}

bowl a[3005];
ld h[3005], sol;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	#ifdef LOCAL
		auto& input = cin;
		auto& output = cout;
	#else
		ifstream input("input.txt");
		ofstream output("output.txt");
	#endif

	input >> n;
	for (int i=0; i<n; i++) {
		input >> a[i].h >> a[i].b >> a[i].r;
		for (int j=0; j<i; j++) {
			h[i] = max(h[i], collide(a[j], a[i]) + h[j]);
		}
		sol = max(sol, h[i] + a[i].h);
	}
	output << setprecision(20) << fixed << sol << '\n';
}